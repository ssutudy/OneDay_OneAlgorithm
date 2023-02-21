import java.io.*;
import java.util.*;

public class BOJ_11725 {
    static ArrayList<Integer>[] tree;
    static Boolean[] visited;
    static int[] parent;
    public static void bfs(int start) {
        LinkedList<Integer> queue = new LinkedList<>();

        queue.offer(start);
        visited[start] = true;

        while(!queue.isEmpty()) {
            int poll = queue.poll();

            for(int i: tree[poll]) {
                if(visited[i]) continue;

                queue.offer(i);
                visited[i] = true;
                parent[i] = poll;
            }
        }
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;

        tree = new ArrayList[n+1];
        visited = new Boolean[n+1];
        parent = new int[n+1];

        for(int i = 1 ; i < n+1; i++) {
            tree[i] = new ArrayList<>();
            visited[i] = false;
        }

        for(int i = 0; i < n-1; i++) {
            st = new StringTokenizer(br.readLine()," ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            tree[a].add(b);
            tree[b].add(a);
        }

        bfs(1);

        for(int i = 2; i < n+1; i++) {
            System.out.println(parent[i]);
        }
    }
}
