import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main (String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		BigInteger ans = BigInteger.ZERO;
		while(true) {
			BigInteger aux = in.nextBigInteger();
			if(aux.compareTo(BigInteger.ZERO) == 0) break;
			ans = ans.add(aux);
		}
		System.out.print(ans + "\n");
	}
}

