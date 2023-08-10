import java.util.Random;
public class TaktikA extends Taktik implements ITaktik {

	@Override
	public int atak(int populasyon) {
		Random rand = new Random();
        long atak = rand.nextInt(1001);
        return (int) atak;
	}

	@Override
	public void yoket() {
		// TODO Auto-generated method stub
		
	}

}