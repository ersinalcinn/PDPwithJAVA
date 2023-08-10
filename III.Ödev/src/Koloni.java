import java.util.Random;

public class Koloni {
    private char id;
    private int populasyon;
    private int yemek;
    private int kazanma;
    private int kaybetme;
    private char uretimTip;
    private Uretim uretim;
    private Taktik taktik;
    private char taktikTip;

    public Koloni(char id, int populasyon) {
        this.id = id;
        this.populasyon = populasyon;
        yemek = populasyon * populasyon;
        if(populasyon % 2 == 0) 
        {
        	 uretimTip = 'a';
             uretim = new UretimA();
             taktikTip ='b';
             taktik= new TaktikB();
        }
        else
        {
        	uretimTip = 'b';
        	uretim = new UretimB();
        	taktikTip ='a';
            taktik= new TaktikA();
        }
       
    }

    public void printKoloni() {
        System.out.println(id + "\t\t" + populasyon + "\t\t" + yemek + "\t\t" + kazanma+ "\t\t" + kaybetme);
    }

    public int getPopulasyon() {
        return populasyon;
    }

    public void setPopulasyon(int populasyon) {
        this.populasyon = populasyon;
    }

    public int getYemek() {
        return yemek;
    }

    public void setYemek(int yemek) {
        this.yemek = yemek;
    }

    public char getUretimTip() {
        return uretimTip;
    }

    public IUretim getUretim() {
        return uretim;
    }
    public int hasarKoloni() {
        if (taktikTip == 'a') {
            return ((TaktikA) taktik).atak(populasyon);
        } else if (taktikTip == 'b') {
            return ((TaktikB) taktik).atak(populasyon);
        } else {
            return 0;
        }
    }
    public void savas(Koloni koloni2) {
        int atak1 = hasarKoloni();
        int atak2 = koloni2.hasarKoloni();

        if (atak1 > atak2) {
            koloni2.populasyon -= (koloni2.populasyon * ((atak1 - atak2) / 10)) / 100;
            yemek += (koloni2.yemek * ((atak1 - atak2) / 10)) / 100;
            koloni2.yemek -= (koloni2.yemek * ((atak1 - atak2) / 10)) / 100;
            kazanma++;
            koloni2.kaybetme++;
        } else if (atak1 < atak2) {
            populasyon -= (populasyon * ((atak1 - atak2) / 10)) / 100;
            koloni2.yemek += (yemek * ((atak1 - atak2) / 10)) / 100;
            yemek -= (yemek * ((atak1 - atak2) / 10)) / 100;
            koloni2.kazanma++;
            kaybetme++;
        } else {
            if (new Random().nextBoolean()) {
                koloni2.kazanma++;
                kaybetme++;
            } else {
                kazanma++;
                koloni2.kaybetme++;
            }
        }

        if (populasyon <= 0 || yemek <= 0) {
            populasyon = 0;
            yemek = 0;
        }

        if (koloni2.populasyon <= 0 || koloni2.yemek <= 0) {
            koloni2.populasyon = 0;
            koloni2.yemek = 0;
        }
    }

    public void yoket() {
        // Bellekten kaldirma islemleri
    }
}


