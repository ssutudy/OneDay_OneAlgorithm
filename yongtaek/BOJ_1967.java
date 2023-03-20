import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_1967 {
    static ArrayList<Pair>[] graph;
    static Boolean[] visited;
    static int max = 0;
    
    static class Pair {
        int b,c;

        Pair(int b, int c) {
            this.b = b;
            this.c = c;
        }
    }

    public static void dfs(int start, int len) {
        visited[start] = true;

        for(Pair p: graph[start]) {
            int b = p.b;
            int c = p.c;

            if(visited[b]) continue;

            dfs(b, c+len);
        }

        if(len > max) {
            max = len;
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st ;

        graph = new ArrayList[n+1];
        visited = new Boolean[n+1];

        for(int i = 1; i < n+1; i++) {
            graph[i] = new ArrayList<>();
            visited[i] = false;
        }

        for(int i = 0 ; i < n-1 ; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[a].add(new Pair(b,c));
            graph[b].add(new Pair(a,c));
        }

        for(int i = 1 ; i < n+1; i++) {
            Arrays.fill(visited, false);
            visited[i] = true;
            for(Pair p: graph[i]) {
                int b = p.b;
                int cost = p.c;

                dfs(b,cost);
            }
        }

        System.out.println(max);

    }
}
