import java.util.*;

public class Main {
	public static boolean[][] arr = new boolean[15][15];
	public static int n;
	public static boolean[] check_col = new boolean[15];
	public static boolean[] check_dig = new boolean[40];
	public static boolean[] check_dig2 = new boolean[40];
	
	public static boolean check(int row, int col) {
		if(check_col[col]) {
			return false;
		}
		
		if(check_dig[row+col]) {
			return false;
		}
		
		if(check_dig2[row-col+n]) {
			return false;
		}
		
		return true;
	}
	
	public static int calc(int row) {
		if(row==n)
			return 1;
		
		int cnt = 0;
		
		for(int col=0; col<n; col++) {
			if(check(row,col)) {
				check_dig[row+col] = true;
				check_dig2[row-col+n] = true;
				check_col[col] = true;
				arr[row][col] = true;
				cnt += calc(row+1);
				check_dig[row+col] = false;
				check_dig2[row-col+n] = false;
				check_col[col] = false;
				arr[row][col] = false; 
			}
		}
		
		return cnt;
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		n = scan.nextInt();
		
		System.out.println(calc(0));
	}

}
