import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	static BigInteger fact(int n) {
	    BigInteger res = new BigInteger("1");
	    
	    for(int i = 2; i <= n; i++)
	       res=res.multiply(BigInteger.valueOf(i));
	    
	    return res;
    }
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		System.out.println(fact(n));
	}
}