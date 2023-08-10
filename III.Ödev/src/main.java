import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tur = 0;

        System.out.println("sadece numara ve boşluklardan oluşan bir input giriniz (max 256 karakter):");
        String input_str = scanner.nextLine();

        int ac = 0;
        Oyun oyun = new Oyun(ac, input_str);

        System.out.println("Tur: " + tur);
        oyun.printKoloniler(oyun.koloniler);
        System.out.println("---------------------------------------------------------------------------------------------\n\n\n\n");

        while (oyun.isGood(oyun.koloniler)) {
            oyun.uretKoloniler(oyun.koloniler);
            oyun.turetKoloniler(oyun.koloniler);
            oyun.yedirKoloniler(oyun.koloniler);
            oyun.savastirKoloniler(oyun.koloniler);

            System.out.println("Tur: " + (++tur));
            oyun.printKoloniler(oyun.koloniler);
            System.out.println("---------------------------------------------------------------------------------------------\n\n\n\n");
        }

        oyun.deleteOyun(oyun, ac - 1);
    }
}
