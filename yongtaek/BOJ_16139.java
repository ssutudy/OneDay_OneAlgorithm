import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_16139  {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String string = br.readLine();
		int n = string.length();

		int[][] array = new int[26][n+1];

		array[string.charAt(0) - 'a'][1] = 1;
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < 26; j++) {
				array[j][i + 1] = array[j][i] + (string.charAt(i) == j + 'a'? 1: 0);
			}
		}
		
		StringTokenizer st;
		char ch;
		int start, end;
		
		n = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			
			ch = st.nextToken().charAt(0);
			start = Integer.parseInt(st.nextToken());
			end = Integer.parseInt(st.nextToken());
			sb.append(array[ch - 'a'][end + 1] - array[ch - 'a'][start] + "\n");
		}
		System.out.println(sb);
	
	}
			
}