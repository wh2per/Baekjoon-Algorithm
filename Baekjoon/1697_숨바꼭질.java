import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int MAX = 1000000;
		int N = scan.nextInt();
		int K = scan.nextInt();
		
		boolean[] check = new boolean[MAX];
		int[] dist = new int[MAX];
		check[N] = true;
		dist[N] = 0;
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(N);
		
		while(!q.isEmpty()) {
			int now = q.remove();
			
			if(now-1 >=0) {
				if(check[now-1]==false) {
					q.add(now-1);
					check[now-1] = true;
					dist[now-1] = dist[now] + 1;
				}
			}
			
			if(now+1 < MAX) {
				if(check[now+1]==false) {
					q.add(now+1);
					check[now+1]=true;
					dist[now+1] = dist[now]+1;
				}
			}
			
			if(now*2 < MAX) {
				if(check[now*2]==false) {
					q.add(now*2);
					check[now*2]=true;
					dist[now*2] = dist[now]+1;
				}
			}
		}

		
		System.out.println(dist[K]);
	}

}
