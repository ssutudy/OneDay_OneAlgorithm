import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class BOJ_16928 {
    static int[] count = new int[101];
    static Boolean[] visited = new Boolean[101];
    static int[] snakeLadder = new int[101];

    public static void bfs(int start) {
        LinkedList<Integer> queue = new LinkedList<>();
        count[start] = 0;
        visited[start] = true;

        queue.offer(start);

        while(!queue.isEmpty()) {
            int poll = queue.poll();

            for(int i = 1; i < 7; i++) {
                int newDist = poll + i;
                
                if(newDist > 100) continue;
                if(visited[newDist]) continue;

                visited[newDist] = true;

                if(snakeLadder[newDist] != 0) {
                    if(!visited[snakeLadder[newDist]]) {
                        count[snakeLadder[newDist]] = count[poll] + 1;
                        visited[snakeLadder[newDist]] = true;
                        queue.offer(snakeLadder[newDist]);
                    }
                } else {
                    count[newDist] = count[poll] + 1;
                    visited[newDist] = true;
                    queue.offer(newDist);
                }
            }
        }
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for(int i = 0; i < 101; i++) {
            visited[i] = false;
            count[i] = 0;
            snakeLadder[i] = 0;
        }

        for(int i = 0; i < n + m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            snakeLadder[a] = b;
        }

        bfs(1);

        System.out.println(count[100]);
    }
}
