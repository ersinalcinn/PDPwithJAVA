import java.util.Random;
public class TaktikB  extends Taktik implements ITaktik{

	@Override
	public int atak(int populasyon) {
		 Random rand = new Random();
	        int atak = (int) ((populasyon % 1001) * rand.nextInt());
	        atak %= 1001;
	        return atak;
	}

	@Override
	public void yoket() {
		// TODO Auto-generated method stub
		
	}

}
