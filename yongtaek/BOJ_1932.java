import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_1932 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        int n = Integer.parseInt(br.readLine());

        int[][] dp = new int[n][n];

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine()," ");
            for(int j = 0; j < i + 1; j++) {
                dp[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i + 1; j++) {
                if(j == 0) {
                    dp[i][j] = dp[i][j] + dp[i-1][j];
                } else if (j == i) {
                    dp[i][j] = dp[i][j] + dp[i-1][j-1];
                } else {
                    dp[i][j] = Math.max((dp[i][j] + dp[i-1][j-1]), (dp[i][j] + dp[i-1][j]));
                }
            }
        }

        System.out.println(Arrays.stream(dp[n-1]).max().getAsInt());
    }
}
