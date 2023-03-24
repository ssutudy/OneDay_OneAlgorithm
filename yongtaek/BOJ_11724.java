import java.io.*;
import java.util.*;

public class BOJ_11724 {
    static ArrayList<Integer>[] graph;
    static Boolean[] visited;
    static int count = 0;

    public static Boolean bfs(int start) {
        LinkedList<Integer> queue = new LinkedList<>();

        visited[start] = true;
        queue.add(start);

        while(!queue.isEmpty()) {
            int pollVal = queue.poll();

            for(int i : graph[pollVal]) {
                if(visited[i]) continue;

                visited[i] = true;
                queue.add(i);
            }
        }

        return true;
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N+1];
        visited = new Boolean[N+1];

        for(int i = 1; i < N+1; i++) {
            visited[i] = false;
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken());   
            int y = Integer.parseInt(st.nextToken());   

            graph[x].add(y);
            graph[y].add(x);
        }

        for(int i = 1; i < N+1; i++) {
            if(!visited[i]) {
                bfs(i);
                count++;
            }
        }

        System.out.println(count);
    }
}
