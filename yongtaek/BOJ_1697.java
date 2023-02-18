import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class BOJ_1697 {
    static LinkedList<Integer> queue = new LinkedList<>();
    static int[] array = new int[100001];
    static int n;
    static int k;
    static int answer = 0;

    static void bfs(int n) {
        queue.offer(n);
    
        while(!queue.isEmpty()) {
            int v = queue.poll();

            if(v == k) {
                answer = array[v];
                break;
            }

            if(v != 0 && array[v-1] == 0) {
                queue.offer(v-1);
                array[v-1] = array[v] + 1;
            }

            if(v != 100000 && array[v+1] == 0){
                queue.offer(v+1);
                array[v+1] = array[v] + 1;
            }

            if(v <= 50000 && v != 0 && array[v*2] == 0) {
                queue.offer(v*2);
                array[v*2] = array[v] + 1;
            }
        }
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        bfs(n);

        System.out.println(answer);
    }
}
