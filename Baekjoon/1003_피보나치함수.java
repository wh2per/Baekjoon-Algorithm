/*
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int arr[][];
		
		arr = new int[41][2];
		
		Scanner scan = new Scanner(System.in);
		
		int count;
		int number;
		
		arr[0][0] = 1;
		arr[0][1] = 0;
		
		arr[1][0] = 0;
		arr[1][1] = 1;
		
		count = scan.nextInt();
		
		for(int i=0; i<count; i++) {
			number = scan.nextInt();
			for(int j=2; j<=number; j++) {
				arr[j][0] = arr[j-1][0] + arr[j-2][0];
				arr[j][1] = arr[j-1][1] + arr[j-2][1];
			}
			System.out.println(arr[number][0]+" "+arr[number][1]);
		}
	}
}
*/