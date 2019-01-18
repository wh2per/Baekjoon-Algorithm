/*
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int arr[] = new int[9];
		int ans[] = new int[7];
		int result=0;
		
		for(int i=0; i<9; i++)
			arr[i]= scan.nextInt();
		
		
		Arrays.sort(arr);
		for(int i=0; i<9; i++) {
			for(int j=i; j<9; j++) {
				for(int k=0; k<9; k++) {
					if(k!=i && k!=j)
						result+=arr[k];
				}
				if(result==100) {
					for(int k=0; k<9; k++) {
						if(k!=i && k!=j) {
							System.out.println(arr[k]);
						}
					}
				}
				result=0;
			}
		}
		
	}
}
*/