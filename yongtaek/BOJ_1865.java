import java.io.*;
import java.util.*;

public class BOJ_1865 {
    static ArrayList<Pair>[] graph;
    static long[] distance;
    static int n;
    static int m;
    static int w;

    public static class Pair {
        int e,t;

        Pair(int e, int t) {
            this.e = e;
            this.t = t;
        }
    }
    public static Boolean belmanFord(int start) {
        distance[start] = 0;
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < m+1; j++) {
                for(Pair pair: graph[j]) {
                    if(distance[j] != Integer.MAX_VALUE) {
                        distance[pair.e] = Math.min(distance[pair.e], distance[j] + pair.t);
                    }
                }
            }
        }

        for(int j = 1; j < m+1; j++) {
            for(Pair pair: graph[j]) {
                if(distance[j] != Integer.MAX_VALUE && distance[pair.e] > distance[j] + pair.t) {
                    return false;                    
                }
            }
        }

        return true;
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
     
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());

        distance = new long[n+1];
        graph = new ArrayList[n+1];

        for(int i = 0; i < tc; i++) {
            Boolean isNegative = false;

            for(int p = 1; p < n+1; p++) {
                distance[p] = Integer.MAX_VALUE;
                graph[p] = new ArrayList<>();
            }

            for(int j = 0; j < m+w; i++) {
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                int t = Integer.parseInt(st.nextToken());

                if(j >= m) graph[s].add(new Pair(e,-1 * t));
                else {
                    graph[s].add(new Pair(e,t));
                    graph[e].add(new Pair(s,t));
                }
            }

            for(int k = 1; k < n+1; k++) {
                Arrays.fill(distance,Integer.MAX_VALUE);
                if(!belmanFord(k)) isNegative = true;
            }

            if(isNegative) sb.append("NO\n");
            else sb.append("YES\n"); 
        }

        System.out.println(sb);


    }
}
