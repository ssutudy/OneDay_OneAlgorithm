
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_1504 {
    static ArrayList<Pair>[] graph;
    static int distance[];

    public static class Pair implements Comparable<Pair> {
        private int u, w;

        Pair(int u, int w) {
            this.u = u;
            this.w = w;
        }

        @Override
        public int compareTo(Pair p) {
            if(this.w == p.w) return this.u - p.u;

            return this.w - p.w;
        }
    }

    public static long dijkstra(int start, int end) {
        Arrays.fill(distance, Integer.MAX_VALUE);
        PriorityQueue<Pair> pQueue = new PriorityQueue<Pair>();

        pQueue.offer(new Pair(start, 0));
        distance[start] = 0;

        while(!pQueue.isEmpty()) {
            Pair pair = pQueue.poll();
            int pollu = pair.u;
            int pollw = pair.w;

            if(distance[pollu] < pollw) {
                continue;
            }

            for(Pair i : graph[pollu]) {
                int cost = i.w + pollw;
                if(cost < distance[i.u]) {
                    distance[i.u] = cost;
                    pQueue.offer(new Pair(i.u, cost));
                }
            }
        }
        return distance[end];
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine()," ");

        int n = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        graph = new ArrayList[n+1];
        distance = new int[n+1];

        for(int i = 1; i < n + 1; i++) {
            graph[i] = new ArrayList<>();
            distance[i] = Integer.MAX_VALUE;
        }

        for(int i = 0 ; i < e; i++) {
            st = new StringTokenizer(br.readLine()," ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[a].add(new Pair(b,c));
            graph[b].add(new Pair(a,c));
        }

        st = new StringTokenizer(br.readLine()," ");
        int v1 = Integer.parseInt(st.nextToken());
        int v2 = Integer.parseInt(st.nextToken());

        long directionA = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n);

        long directionB = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n);

        long answer = Math.min(directionA, directionB);

        if (answer >= Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(answer);
        }
    }
}
