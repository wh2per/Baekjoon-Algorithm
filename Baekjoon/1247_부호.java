import java.math.BigInteger;
import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<3;i++) {
            int n = sc.nextInt();
            BigInteger zero = new BigInteger("0");
            BigInteger sum = new BigInteger("0");
            for(int j=0;j<n;j++) {
                BigInteger a = sc.nextBigInteger();
                sum = sum.add(a);
            }

            if(sum.compareTo(zero) ==0)
            	System.out.print("0\n");
            else if(sum.compareTo(zero) == -1)
            	System.out.print("-\n");
            else
            	System.out.print("+\n");
        }
    }
}