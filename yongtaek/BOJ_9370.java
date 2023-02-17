import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.Collections;

public class BOJ_9370 {
    static ArrayList<Pair>[] graph;
    static int[] distance;
    static int[] candidate;

    public static class Pair implements Comparable<Pair> {
        int b,d;

        Pair(int b, int d) {
            this.b = b;
            this.d = d;
        }

        @Override
        public int compareTo(Pair p) {
            if(this.d == p.d) return this.b - p.d;

            return this.d - p.d;
        }
    }
    public static long dijkstra(int start, int end) {
        Arrays.fill(distance, Integer.MAX_VALUE);
        PriorityQueue<Pair> pQueue = new PriorityQueue<Pair>();

        pQueue.offer(new Pair(start, 0));
        distance[start] = 0;

        while(!pQueue.isEmpty()) {
            Pair pair = pQueue.poll();
            int pollb = pair.b;
            int polld = pair.d;

            if(distance[pollb] < polld) {
                continue;
            }

            for(Pair p: graph[pollb]) {
                int cost = polld + p.d;
                if(cost < distance[p.b]) {
                    distance[p.b] = cost;
                    pQueue.add(new Pair(p.b, cost));
                }
            }
        }
        
        return distance[end];
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for(int i = 0; i < T; i++) {

            st = new StringTokenizer(br.readLine()," ");

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            graph = new ArrayList[n+1];
            distance = new int[n+1];
            candidate = new int[t];

            for(int j = 1; j < n + 1; j++) {
                distance[j] = Integer.MAX_VALUE;
                graph[j] = new ArrayList<>();
            }

            st = new StringTokenizer(br.readLine()," ");

            int s = Integer.parseInt(st.nextToken()); 
            int h = Integer.parseInt(st.nextToken()); 
            int g = Integer.parseInt(st.nextToken()); 

            for(int k = 0; k < m; k++) {
                st = new StringTokenizer(br.readLine()," ");
                
                int a = Integer.parseInt(st.nextToken()); 
                int b = Integer.parseInt(st.nextToken()); 
                int d = Integer.parseInt(st.nextToken()); 

                graph[a].add(new Pair(b,d));
                graph[b].add(new Pair(a,d));
            }

            for(int p = 0; p < t; p++) {
                candidate[p] = Integer.parseInt(br.readLine());
            }

            ArrayList<Integer> result = new ArrayList<>();
            for(int p = 0; p < t; p++) {
               long distA = dijkstra(s,h) + dijkstra(h,g) + dijkstra(g,candidate[p]);
               long distB = dijkstra(s,g) + dijkstra(g,h) + dijkstra(h,candidate[p]);
               long dist = dijkstra(s, candidate[p]);
        
               if(distA <= dist || distB <= dist) {
                    result.add(candidate[p]);
               }
            }

            Collections.sort(result);

            result.stream().forEach(data -> sb.append(data +" "));

            if(i != T-1) sb.append("\n");
        }

        System.out.println(sb);
    }
}
