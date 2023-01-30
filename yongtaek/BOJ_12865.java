import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_12865 {
    static int dp[][];
    static int back[][];

    static void knapsack(int n, int k) {
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < k + 1; j++) {
                if(j - back[i-1][0] >= 0) {
                    dp[i][j] = Math.max(dp[i-1][j-back[i-1][0]] + back[i-1][1], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine()," ");
        
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        back = new int[n][2];
        dp = new int[n+1][k+1];

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine()," ");

            back[i][0] = Integer.parseInt(st.nextToken());
            back[i][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(back, (m1, m2) -> {
            if(m1[0] == m2[0]) {
                return m1[1] - m2[1];
            } else {
                return m1[0] - m2[0];
            }
        });

        knapsack(n, k);
       
        System.out.println(dp[n][k]);
    }
}
