import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner("in.txt");
		while(in.hasNext()) {
			int n = in.nextInt();
			BigInteger p = in.nextBigInteger();
			int lo = 0, hi = 1000000010, mid, ans = 0;
			for(int i = 0; i < 50; ++i) {
				mid = (lo+hi)/2;
				int aux = (BigInteger.valueOf(mid).pow(n)).compareTo(p);
				if(aux > 0 ) {
					hi = mid;
				} else if (aux < 0) {
					lo = mid;
				} else {
					ans = mid;
				}
			}
			
			System.out.print(ans + "\n");
		}
	}
}

