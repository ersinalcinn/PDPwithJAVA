
public class Taktik implements ITaktik {
    
    public void yoket() {
        // Burada yok etme işlemleri yapılabilir, ancak bu örnekte boş bırakacağım.
    }
    
    public static Taktik taktikOlustur() {
        Taktik taktik = new Taktik();
        return taktik;
    }

	@Override
	public int atak(int populasyon) {
		// TODO Auto-generated method stub
		return 0;
	}
}