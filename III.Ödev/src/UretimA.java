
public class UretimA extends Uretim implements IUretim{

	@Override
	public int uret(int populasyon) {
		int atak = (int)Math.floor(Math.random() * (1000 - 0 + 1) + 0);
	    return (atak);
	}

	@Override
	public int kazanma() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int kaybetme() {
		// TODO Auto-generated method stub
		return 0;
	}

}
