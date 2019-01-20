/*
import java.util.*;

public class Main {
    public static boolean next_permutation(int[] a) {
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
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i=0; i<n; i++) {
            a[i] = sc.nextInt();
        }
        int ans=0;
        
        Arrays.sort(a);
        
        for(int j=1; j<n; j++) {
        	ans += Math.abs(a[j]-a[j-1]);
        }
        
        
        while (next_permutation(a)) {
        	int temp=0;
            for (int i=1; i<n; i++) {
                temp+=Math.abs(a[i]-a[i-1]);
            }
            ans = Math.max(ans, temp);
        }
        
        System.out.println(ans);
    }
}
*/