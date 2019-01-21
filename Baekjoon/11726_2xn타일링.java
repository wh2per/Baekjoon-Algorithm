/*
import java.util.*;
public class Main {
	static int[] d;
	public static int go(int n) {
		if(n==1)
			return 1;
		
		if(d[n]>0)
			return d[n];
		
		d[n] = go(n-1) + go(n-2);
		if(d[n] > 10007)
			d[n] = d[n]%10007;
		return d[n];
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		d = new int[n+1];
		d[0] = 1;
		d[1] = 1;
		System.out.println(go(n));
	}
}
*/