import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_11657 {
    static ArrayList<Pair>[] graph;
    static long[] distance;
    static int n;
    static int m;

    public static class Pair {
        int b,c;

        Pair(int b, int c) {
            this.b = b;
            this.c = c;
        }
    }
    public static Boolean bellmanford(int start) {
        distance[start] = 0;

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < n+1; j++) {
                for(Pair pair: graph[j]) {
                    if(distance[j] != Integer.MAX_VALUE) {
                        distance[pair.b] = Math.min(distance[pair.b], distance[j] + pair.c);
                    }
                }
            }
        }

        for(int j = 1; j < n+1; j++) {
            for(Pair pair: graph[j]) {
                if(distance[j] != Integer.MAX_VALUE && distance[pair.b] > distance[j] + pair.c) {
                    return false;                    
                }
            }
        }

        return true;        
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine()," ");

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        graph = new ArrayList[n+1];
        distance = new long[n+1];

        for(int i = 1; i < n+1; i++) {
            distance[i] = Integer.MAX_VALUE;
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine()," ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[a].add(new Pair(b, c));
        }

        if(bellmanford(1)){
            for(int i = 2; i < n+1; i++) {
                if(distance[i] == Integer.MAX_VALUE) {
                    System.out.println(-1);
                    continue;
                }
                System.out.println(distance[i]);
            }
        } else {
            System.out.println(-1);
        }
    }
}
