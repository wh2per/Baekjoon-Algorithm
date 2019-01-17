/*
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();
        int result = 0,answer=-1001, temp = num;
        int[] value = new int[num];
        
        for(int k=0; k<num; k++) 
        	value[k] = scan.nextInt();
        
        for(int j=0; j<temp; j++) {			//하나씩 제거
        	if(num==0)
        		break;
        	result = 0;
        	while(num>1 && value[num-1]<0 && (value[num-1] <= value[num-2])) {
        		num--;
        	}
	        for(int i=num-1; i>=0; i--) {	//10, 9 , 8 ... 까지만 더하기
	        	if(i==num-1)
	        		result = value[i];
	        	else
	        		result = result+value[i];
	        	answer = Math.max(answer, result);
	        }
	        num--;	
        }
        System.out.println(answer);
	}
}
*/