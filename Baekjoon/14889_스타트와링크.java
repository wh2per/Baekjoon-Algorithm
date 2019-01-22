/*
import java.util.*;
public class Main {

	static boolean next_permutgetion(int[] a) {
        int i = a.length-1;
        while (i > 0 && a[i-1] >= a[i]) {
            i -= 1;
        }
        if (i <= 0) {
            return false;
        }
        int j = a.length-1;
        while (a[j] <= a[i-1]) {
            j -= 1;
        }
        int temp = a[i-1];
        a[i-1] = a[j];
        a[j] = temp;

        j = a.length-1;
        while (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i += 1;
            j -= 1;
        }
        return true;
    }
	
    public static void main(String[] args) {
       Scanner scan = new Scanner(System.in);
       int n = scan.nextInt();
       int arr[][] = new int[n][n];
       int ans = Integer.MAX_VALUE;
       
       for(int i=0; i<n; i++) {
    	   for(int j=0; j<n; j++) {
    		   arr[i][j] = scan.nextInt();
    	   }
       }
       
       int[] d= new int[n];
       for(int i=0; i<n/2; i++)
    	   d[i] = -1;
       
       do {
    	   int cost1 = 0;
    	   int cost2 = 0;
    	   int[] S = new int[n/2];
    	   int[] L = new int[n/2];
    	   int sindex=0;
    	   int lindex=0;
    	   
    	   for(int i=0; i<n; i++) {
    		   if(d[i]==0) {
    			   S[sindex++] = i;
    		   }else if(d[i]==-1) {
    			   L[lindex++] = i;
    		   }  
    	   }
    	   
    	   for(int i=0; i<n/2; i++) {
    		   for(int j=0; j<n/2; j++) {
    			   if(j!=i) {
    				   cost1 += arr[S[i]][S[j]];
    				   cost2 += arr[L[i]][L[j]];
    			   }
    				   
    		   }
    	   }
    	   
    	   int temp = Math.abs(cost1-cost2);
    	   if(ans > temp)
    		   ans = temp;
       }while(next_permutgetion(d));
       
       System.out.println(ans);
    }
}
*/