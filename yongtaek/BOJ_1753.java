import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_1753 {
    static ArrayList<Pair>[] graph;
    static int[] distance;

    static class Pair implements Comparable<Pair> {
        private int v,w;

        Pair(int v, int w) {
            this.v = v;
            this.w = w;
        }

        @Override
        public int compareTo(Pair p) {
            if(this.w == p.w) return this.v - p.v;
            return this.w - p.w;
        }
    }

    public static void dijkstra(int start) {
        PriorityQueue<Pair> pQueue = new PriorityQueue<Pair>();

        pQueue.offer(new Pair(start, 0));

        distance[start] = 0;

        while(!pQueue.isEmpty()) {
            Pair pair = pQueue.poll();
            int pollv = pair.v;
            int pollw = pair.w;

            if(distance[pollv] < pollw) {
                continue;
            }

            for(Pair i : graph[pollv]) {
                int cost = pollw + i.w;
                if(cost < distance[i.v]) {
                    distance[i.v] = cost;
                    pQueue.offer(new Pair(i.v, cost));
                }
            }
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine()," ");

        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        graph = new ArrayList[v+1];
        distance = new int[v+1];

        for(int i = 1; i < v + 1; i++) {
            distance[i] = Integer.MAX_VALUE;
            graph[i] = new ArrayList<>();
        }

        int k = Integer.parseInt(br.readLine());

        for(int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine()," ");
            int tmpU = Integer.parseInt(st.nextToken());
            int tmpE = Integer.parseInt(st.nextToken());
            int tmpW = Integer.parseInt(st.nextToken());

            graph[tmpU].add(new Pair(tmpE, tmpW));
        }

        dijkstra(k);

        for(int i = 1 ; i < v + 1; i++) {
            if(distance[i] == Integer.MAX_VALUE) {
                System.out.println("INF");
            } else {
                System.out.println(distance[i]);   
            }
        }
    }
}
