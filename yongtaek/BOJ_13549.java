import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_13549 {
    static int array[] = new int[100001];
    static int n; 
    static int k;
    static int answer = 0;
    public static class Pair implements Comparable<Pair> {
        int i, w;

        Pair(int i, int w) {
            this.i = i;
            this.w = w;
        }

        @Override
        public int compareTo(Pair p) {
            if(this.w == p.w) return this.i - p.i;

            return this.w - p.w;
        }
    }

    public static void djikstra(int start) {
        Arrays.fill(array, Integer.MAX_VALUE);
        PriorityQueue<Pair> pQueue = new PriorityQueue<>();

        pQueue.offer(new Pair(start, 0));

        while(!pQueue.isEmpty()) {
            Pair pair = pQueue.poll();
            int polli = pair.i;
            int pollw = pair.w;


            if(polli == k) {
                answer = array[polli];
                break;
            }

            if(array[polli] < pollw) {
                continue;
            }

            if(polli != 0) {
                int cost = pollw + 1;
                if(cost < array[polli-1]) {
                    array[polli-1] = cost;
                    pQueue.offer(new Pair(polli-1, cost));    
                }
            }

            if(polli != 100000) {
                int cost = pollw + 1;
                if(cost < array[polli+1]) {
                    array[polli+1] = cost;
                    pQueue.offer(new Pair(polli+1, cost));

                } 
            }

            if(polli != 0  && polli <= 50000) {
                int cost = pollw;
                if(cost < array[polli*2]) {
                    array[polli*2] = cost;
                    pQueue.offer(new Pair(polli*2, cost));
                } 
            }
        }
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        djikstra(n);

        if(answer == Integer.MAX_VALUE) {
            System.out.println(0);
        } else {
            System.out.println(answer);
        }
    }
}
