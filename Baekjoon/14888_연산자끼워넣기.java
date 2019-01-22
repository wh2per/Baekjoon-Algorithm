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
       int[] arr = new int[n];
       int[] y = new int[4];
       int count=0;
       int index=0;
       
       int min=Integer.MAX_VALUE;
       int max=Integer.MIN_VALUE;
       
       for(int i=0; i<n; i++)
        arr[i] = scan.nextInt();
       
       for(int i=0; i<4; i++) {
    	   y[i] = scan.nextInt();
    	   count += y[i];
       }
       
       int[] d = new int[count];
       for(int i=0; i<4; i++) {
    	   int temp = y[i];
    	   for(int j=0; j<temp; j++) {
    		   d[index++] = i+1;
    	   }
       }
       
       do {
    	   int ans = arr[0];
    	   for(int i=0; i<count; i++) {
    		   if(d[i]==1) {
    			   ans = ans + arr[i+1];
    		   }else if(d[i]==2) {
    			   ans = ans - arr[i+1];
    		   }else if(d[i]==3) {
    			   ans = ans * arr[i+1];
    		   }else if(d[i]==4){
    			   ans = ans / arr[i+1];
    		   }
    	   }
    	   if(ans>max)
			   max = ans;
		   if(ans<min)
			   min = ans;
       }while(next_permutgetion(d));
        
        
        System.out.println(max);
        System.out.println(min);
    }
}
*/