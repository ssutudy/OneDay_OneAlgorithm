import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ_24479 {
    static Boolean[] visited;
    static ArrayList<Integer>[] edges;
    static int index = 0;
    static int[] result;
    static StringBuilder sb;

    public static void dfs(int r) {
        visited[r] = true;

        result[r] = ++index;

        for(int i : edges[r]){
            if(visited[i]) continue;
            visited[i] = true;
            dfs(i);
        }
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        sb = new StringBuilder();

        st =  new StringTokenizer(br.readLine()," ");

        int n = Integer.parseInt(st.nextToken());

        edges = new ArrayList[n+1];
        result = new int[n+1];

        for(int i = 1; i < n + 1; i++) {
            edges[i] = new ArrayList<>();
        }

        visited = new Boolean[n+1];

        for(int i = 1; i < n + 1; i++) {
            visited[i] = false;
        }

        int m = Integer.parseInt(st.nextToken());

        int r = Integer.parseInt(st.nextToken());

        for(int i = 1 ; i < m + 1; i++) {
            st =  new StringTokenizer(br.readLine()," ");
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            edges[u].add(v);
            edges[v].add(u);
        }

        for(int i = 1 ; i < n + 1; i++) {
            Collections.sort(edges[i]);
        }

        dfs(r);

        for(int i = 1; i < n + 1; i++) {
            sb.append(result[i]+"\n");
        }

        System.out.println(sb);
    }
}
