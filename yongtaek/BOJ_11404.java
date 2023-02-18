import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_11404 {
    static long graph[][];
    static int n;
    static void floydWarshall() {
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < n+1; j++) {
                for(int k = 1; k < n+1; k++) {
                    graph[j][k] = Math.min(graph[j][k], graph[j][i] + graph[i][k]);
                }
            }
        }
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        graph = new long[n+1][n+1];

        for(int i = 0; i < n+1; i++) {
            for(int j = 0; j < n+1; j++) {
                if(i == j) {
                    graph[i][j] = 0;                   ;
                } else {
                    graph[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        for(int i = 0 ; i < m; i++) {
            st = new StringTokenizer(br.readLine()," ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if(c < graph[a][b]) {
                graph[a][b] = c;
            }
        }

        floydWarshall();

        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < n+1; j++) {
                if(graph[i][j] >= Integer.MAX_VALUE) {
                    sb.append(0 + " ");
                } else {
                    sb.append(graph[i][j] + " ");
                }
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }
}