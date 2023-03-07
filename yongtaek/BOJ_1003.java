import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
 
public class BOJ_1003 {
 
	static int first;
	static int second;
	static int plus;
	public static void main(String[] args) throws IOException {
 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 
		int T = Integer.parseInt(br.readLine());
		
		StringBuilder sb = new StringBuilder();
		
		for (int i = 0; i < T; i++) {
			int N = Integer.parseInt(br.readLine());
			fibonacci(N);			
			sb.append(first).append(' ').append(second).append('\n');
		}
		System.out.println(sb);
 
	}
 
	public static void fibonacci(int N) {
		first = 1;
		second = 0;
		plus = 1;
 
		for (int i = 0; i < N; i++) {
			first = second;
			second = plus;
			plus = first + second;
		}
 
	}
 
}