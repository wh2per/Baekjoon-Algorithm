import java.util.*;

public class Main {
	public static final int[] dx = { 0, 0, 1, -1 };
	public static final int[] dy = { 1, -1, 0, 0 };
	public static int go(String[] board, boolean[] check, int x, int y) {
		int ans = 0;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < board.length && ny >= 0 && ny < board[0].length()) {
				if (check[board[nx].charAt(ny) - 'A'] == false) {
					check[board[nx].charAt(ny) - 'A'] = true;
					int next = go(board, check, nx, ny);
					if (ans < next) {
						ans = next;
					}
					check[board[nx].charAt(ny) - 'A'] = false;
				}
			}
		}
		return ans + 1;
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		sc.nextLine();
		String[] board = new String[n];
		for (int i = 0; i < n; i++) {
			board[i] = sc.nextLine();
		}
		boolean[] check = new boolean[26];
		check[board[0].charAt(0) - 'A'] = true;
		System.out.println(go(board, check, 0, 0));
	}
}