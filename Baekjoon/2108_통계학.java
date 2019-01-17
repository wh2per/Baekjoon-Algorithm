/*
import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int N = scan.nextInt();
		float[] arr = new float[N];
		int[] index = new int[8001];
		int[] list = new int[8001];
		float ans1=0, ans2=0, ans3=0, ans4=0;
		float sum=0;
		int max = Integer.MIN_VALUE;
		int maxindex = -1;
		int j=0;
		
		for(int i=0; i<N; i++)
			arr[i] = scan.nextInt();
		Arrays.sort(arr);
		for(int i=0; i<N; i++) {		// 카운팅
			sum += arr[i];
			index[(int) (arr[i]+4000)]++;
		}
		for(int i=0; i<8001; i++) {		// 뭐가 제일 높은지
			if(max < index[i]) {
				max = index[i];
				maxindex = i;
			}
			list[i] = -4001;
		}
		for(int i=0; i<8001; i++) {		// 높은것들 모으기
			if(index[i]==max) {
					list[j++] = i-4000;
			}
		}
		ans1 = Math.round(sum/N);
		ans2 = arr[N/2];
		if(list[1]!=-4001)
			ans3 = list[1];
		else
			ans3 = list[0];
		ans4 = arr[N-1]-arr[0];

		System.out.println((int)ans1);
		System.out.println((int)ans2);
		System.out.println((int)ans3);
		System.out.println((int)ans4);
	}
}
*/