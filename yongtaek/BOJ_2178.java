import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class BOJ_2178 {
    static int[][] graph;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int n;
    static int m;
    static LinkedList<Point> queue = new LinkedList<>();

    public static class Point {
        private int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static int bfs(int x, int y) {
        queue.offer(new Point(x,y));
        
        while(!queue.isEmpty()) {
            Point point = queue.poll();
            int pollx = point.x;
            int polly = point.y;

            for(int i = 0; i < 4; i++) {
                int newx = pollx + dx[i];
                int newy = polly + dy[i];

                if(newx < 0 || newy < 0 || newx >= n || newy >= m) {
                    continue;
                } 

                if(graph[newx][newy] == 0) {
                    continue;
                }

                if(graph[newx][newy] == 1) {
                    graph[newx][newy] = graph[pollx][polly] + 1;
                    queue.offer(new Point(newx, newy));
                }
            }
        }

        return graph[n-1][m-1];
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        graph = new int[n][m];

        for(int i = 0; i < n; i++) {
            String str = br.readLine();

            for(int j = 0 ; j < m; j++) {
                graph[i][j] = Character.getNumericValue(str.charAt(j));
            }
        }

        System.out.println(bfs(0,0));
    }
}
