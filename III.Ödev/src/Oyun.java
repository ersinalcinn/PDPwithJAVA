import java.util.StringTokenizer;

public class Oyun {
	Koloni[] koloniler;
    private int tur;
    

    public Oyun(int ac, String av) {
        tur = 0;
        koloniler = getKoloniler(ac, av);
    }

	public void deleteOyun(Oyun oyun, int sayi) {
        deleteKoloniler(sayi);
    }

    private Koloni[] getKoloniler(int arc, String av) {
        int ac = getAc(av);
        StringTokenizer tokenizer = new StringTokenizer(av, " ");
        Koloni[] koloniler = new Koloni[ac - 1];
        int i = 1;

        while (tokenizer.hasMoreTokens()) {
            int number = Integer.parseInt(tokenizer.nextToken());
            if (number > 0) {
            	int a = i+34;
                koloniler[i - 1] = new Koloni((char) (a), number);
                i++;
                
            }
        }

        return koloniler;
    }
    
    private int getAc(String str) {
        StringTokenizer tokenizer = new StringTokenizer(str, " ");
        int ac = 1;

        while (tokenizer.hasMoreTokens()) {
            int number = Integer.parseInt(tokenizer.nextToken());
            if (number > 0) {
                ac++;
            } else {
                System.out.println("Lütfen geçerli bir input giriniz! (sadece pozitif sayılar ve boşluk)");
                System.exit(1);
            }
        }

        return ac;
    }

    public void printKoloniler(Koloni[] koloniler) {
        System.out.println("Koloni\t\tPop.\t\tYemek\t\tKazanma\t\tKaybetme");
        for (int i = 0; i < koloniler.length; i++) {
            koloniler[i].printKoloni();
        }
    }

    boolean isGood(Koloni[] koloniler) {
        int kontrol = 0;

        for (int i = 0; i < koloniler.length; i++) {
            if (koloniler[i].getPopulasyon() == 0) {
                kontrol++;
            }
        }

        return koloniler.length - 1 > kontrol;
    }

    public void uretKoloniler(Koloni[] koloniler) {
        for (int i = 0; i < koloniler.length; i++) {
            if (koloniler[i].getPopulasyon() > 0) {
            	if (koloniler[i].getUretimTip() == 'a') {
                    koloniler[i].setYemek(koloniler[i].getUretim().uret(koloniler[i].getPopulasyon()));
                }

                if (koloniler[i].getUretimTip() == 'b') {
                    koloniler[i].setYemek(koloniler[i].getUretim().uret(koloniler[i].getPopulasyon()));
                }
            }
        }
    }

    public void turetKoloniler(Koloni[] koloniler) {
        for (int i = 0; i < koloniler.length; i++) {
            if (koloniler[i].getPopulasyon() > 0) {
                koloniler[i].setPopulasyon(koloniler[i].getPopulasyon() + koloniler[i].getPopulasyon() / 5);
            }
        }
    }

    public void yedirKoloniler(Koloni[] koloniler) {
        for (int i = 0; i < koloniler.length; i++) {
            if (koloniler[i].getPopulasyon() > 0) {
                koloniler[i].setYemek(koloniler[i].getYemek() - koloniler[i].getPopulasyon() * 2);
                if (koloniler[i].getYemek() < 0) {
                    koloniler[i].setPopulasyon(0);
                    koloniler[i].setYemek(0);
                }

            }
        }
    }

    public void savastirKoloniler(Koloni[] koloniler) {
        for (int i = 0; i < koloniler.length; i++) {
            for (int j = i + 1; j < koloniler.length; j++) {
                if (koloniler[i].getPopulasyon() > 0 && koloniler[j].getPopulasyon() > 0) {
                    koloniler[i].savas(koloniler[j]);
                }
            }
        }
    }

    private void deleteKoloniler(int sayi) {
        for (int i = 0; i < sayi; i++) {
            koloniler[i].yoket();
        }
    }
}