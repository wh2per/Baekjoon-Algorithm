import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int temp1=0,s=0;
		int k = scan.nextInt();
		int m[],n[],x[],y[];
		
		
		m = new int[k];
		n = new int[k];
		x = new int[k];
		y = new int[k];
		
		for(int i=0; i<k; i++){
			m[i] = scan.nextInt();
			n[i] = scan.nextInt();
			x[i] = scan.nextInt();
			y[i] = scan.nextInt();
		}
		for(int i=0; i<k; i++){
			if(m[i]<n[i]){
				temp1 = x[i];
				while(s<=n[i]){
					if(temp1==y[i])
						break;
					else{
						temp1 = temp1+ m[i];
						while(temp1>n[i])
							temp1= temp1-n[i];
					}
					s++;
				}
				if(s>=n[i])
					System.out.println("-1");
				else
					System.out.println(x[i] + m[i]*s);
			}else{
				temp1 = y[i];
				while(s<=m[i]){
					if(temp1==x[i])
						break;
					else{
						temp1 = temp1+n[i];
						while(temp1>m[i])
							temp1 -=m[i];
					}
					s++;
				}
				if(s>=m[i])
					System.out.println("-1");
				else
					System.out.println(y[i] + n[i]*s);
			}
			
			temp1=0;
			s=0;
		}
	}
}
