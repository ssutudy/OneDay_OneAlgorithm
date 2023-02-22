import java.io.*;
import java.util.*;

public class BOJ_1167 {
    static ArrayList<Pair>[] graph;
    static Boolean[] visited;
    static ArrayList<Integer> isRoot = new ArrayList<>();
    static int maxDist = 0;
    static int maxNode;
    public static class Pair {
        int u, d;

        Pair(int u, int d) {
            this.u = u;
            this.d = d;
        }
    }
    public static void dfs(int start, int accumulate) {
        visited[start] = true;
        if(accumulate > maxDist) {
            maxDist = accumulate;
            maxNode = start;
        }

        for(Pair pair: graph[start]) {
            int newu = pair.u;
            int newd = pair.d;

            if(visited[newu]) continue;

            dfs(newu, accumulate + newd);
        }
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int v = Integer.parseInt(br.readLine());

        graph = new ArrayList[v+1];
        visited = new Boolean[v+1];

        for(int i = 1; i < v+1; i++) {
            visited[i] = false;
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i < v; i++) {
            st = new StringTokenizer(br.readLine());
            int vnum = Integer.parseInt(st.nextToken());

            while(true) {
                int unum = Integer.parseInt(st.nextToken());
                if(unum == -1) break;

                int dist = Integer.parseInt(st.nextToken());

                graph[vnum].add(new Pair(unum, dist));
            }
        }

        dfs(1,0);

        int result = maxDist;

        Arrays.fill(visited, false);
        
        maxDist = 0;

        dfs(maxNode, 0);

        if(maxDist > result) {
            result = maxDist;
        }

        System.out.println(result);
    }
}
