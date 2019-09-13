import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int E = scan.nextInt();
		int S = scan.nextInt();
		int M = scan.nextInt();
		int te = 0;
		int ts = 0;
		int tm = 0;
		int count = 0;

		while (te != E || ts != S || tm != M) {
			te++;
			ts++;
			tm++;
			count++;
			if (te > 15)
				te = 1;
			if (ts > 28)
				ts = 1;
			if (tm > 19)
				tm = 1;
		}

		System.out.println(count);
	}
}
