/**
*
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
* @since 21.04.2023
* <p>
* Dosyayı okuma işlemi
* Sınıfların adını bulma
* Tekli, Çoklu ve Javadoc yorumlarının sayısının bulunması
* 
*/
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.io.*;

public class hw1 {
	public String fileName;
	hw1(String fileN){
		this.fileName =fileN;
		
	}
	public void printFunctionAndComments(String func, int single, int multi, int javadoc)
	{
		System.out.println("Fonksiyon: " + func);
		
        System.out.println("	Tek satırlık yorum sayısı: " + single);
        if(single>0)
        	{
        	    DosyaYaz(0,"Fonksiyon: " + func+"\n");
        		DosyaYaz(0,"	Tek satırlık yorum sayısı: " + single+"\n");
        	}
        System.out.println("	Çok satırlı yorum sayısı: " + multi);
        if(multi>0)  
        	{
        		DosyaYaz(1,"Fonksiyon: " + func+"\n");
        		DosyaYaz(1,"	Çok satırlı yorum sayısı: " + multi+"\n");  
        	}
        System.out.println("	Javadoc yorum sayısı: " + javadoc);
        if(javadoc>0) 
        	{
        		DosyaYaz(2,"Fonksiyon: " + func+"\n");
        		DosyaYaz(2,"	Javadoc yorum sayısı: " + javadoc+"\n");  
        	}
        System.out.println("---------------------------");
	}
	public void DosyaYaz(int index,String data)
	{
		
		if(index == 0)
		{
			
		
		 try {
	            FileOutputStream outputStream = new FileOutputStream("teksatir.txt", true);
	            OutputStreamWriter writer = new OutputStreamWriter(outputStream, "UTF-8");
	            writer.write(data);
	            writer.close();
	        } catch (IOException e) {
	            e.printStackTrace();
	        }
		}
		else if(index == 1)
		{
			try {
	            FileOutputStream outputStream = new FileOutputStream("coksatir.txt", true);
	            OutputStreamWriter writer = new OutputStreamWriter(outputStream, "UTF-8");
	            writer.write(data);
	            writer.close();
	        } catch (IOException e) {
	            e.printStackTrace();
	        }
		}
		else
		{
			try {
	            FileOutputStream outputStream = new FileOutputStream("javadoc.txt", true);
	            OutputStreamWriter writer = new OutputStreamWriter(outputStream, "UTF-8");
	            writer.write(data);
	            writer.close();
	        } catch (IOException e) {
	            e.printStackTrace();
	        }
		}
	}
	public void Start()
	{

		try {
            BufferedReader reader = new BufferedReader(new FileReader(fileName));
            String line = reader.readLine();
            String className = "";
            int singleComments = 0;
            int lineNum=0;
            int multiComments = 0;
            int javadocComments = 0;
            boolean isSinglelineComment = false;
            boolean isMultilineComment = false;
            boolean isJavadocComment = false;
            List<String> methodNames = new ArrayList<>();
            while (line != null) {
                
            	// Sınıf ismini bulma
                if (line.contains("class ") && (line.contains("public") || line.contains("private")|| line.contains("static"))) {
                    className = line.substring(line.indexOf("class ") + 6, line.indexOf("{")).trim();
                    System.out.println("Sınıf: " + className);
                }
                if (line.contains("//") && !isMultilineComment && !isJavadocComment) {
                	
                    singleComments++;
                }
                if (line.contains("/*") && !line.contains("/**")) {
                    isMultilineComment = true;
                    
                }
                
                if (isMultilineComment) {
                    if (line.contains("*/")) {
                        isMultilineComment = false;
                        
                        multiComments++;
                    } else {
                        
                    }
                }
                if (line.contains("/**")) {
                    isJavadocComment = true;
                    isSinglelineComment = false;
                }
                
                if (isJavadocComment) {
                    if (line.contains("*/")) {
                        isJavadocComment = false;
                        javadocComments++;
                    } else {
                        
                    }
                }
                // Fonksiyon ismini bulma ve yorum sayısını hesaplama
                if (line.contains("(") && line.contains(")")) {
                	 String[] words = line.split("\\s+");
                     for (String word : words) {
                         if (word.contains("(")) {
                             methodNames.add(word.substring(0, word.indexOf("(")));
                             
                         }
                     }
                   
                    
                    while (line != null && !line.contains("}")) {
                        
                        // Tek satırlık yorumların sayısını hesaplama
                        if (line.contains("//") && !isMultilineComment && !isJavadocComment ) {
                            singleComments++;
                            
                            DosyaYaz(0,line);
                           
                        
                        }
                        
                        // Çok satırlı yorumların sayısını hesaplama
                        if (line.contains("/*") && !line.contains("/**")) {
                            isMultilineComment = true;
                            
                        }
                        
                        if (isMultilineComment) {
                            if (line.contains("*/")) {
                                isMultilineComment = false;
                                
                                multiComments++;
                            } else {
                                
                            }
                        }
                        
                        // Javadoc yorumlarının sayısını hesaplama
                        if (line.contains("/**")) {
                            isJavadocComment = true;
                            isSinglelineComment = false;
                        }
                        
                        if (isJavadocComment) {
                            if (line.contains("*/")) {
                                isJavadocComment = false;
                                javadocComments++;
                            } else {
                                
                            }
                        }
                        
                        line = reader.readLine();
                        
                    }
                    
                    
                    printFunctionAndComments(methodNames.get(lineNum),singleComments,multiComments,javadocComments);
                    lineNum++;
                    
                    // Yorum sayılarını sıfırlama
                    singleComments = 0;
                    multiComments = 0;
                    javadocComments = 0;
                }
                
                line = reader.readLine();
            }
            
            reader.close();
            
        } catch (IOException e) {
            System.out.println("Dosya okuma hatası: " + e.getMessage());
        }
	}
}