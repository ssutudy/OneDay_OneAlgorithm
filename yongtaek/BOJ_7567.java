import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class BOJ_7567 {
    static int[][] graph;
    static int m;
    static int n;
    static int count = 0;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static LinkedList<Point> queue = new LinkedList<>();
    static int depthMax = 0;

    public static class Point{
        int x,y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void bfs() {
        while(!queue.isEmpty()) {
            Point point = queue.poll();

            int pollx = point.x;
            int polly = point.y;

            for(int i = 0; i < 4; i++) {

                int newx = pollx + dx[i];
                int newy = polly + dy[i];


                if(newx <= -1 || newy <= -1 || newx >= n || newy >= m) {
                    continue;
                }
    
                if(graph[newx][newy] == 0) {
                    queue.offer(new Point(newx, newy));
                    graph[newx][newy] = graph[pollx][polly] + 1;
                }
            }
        }
    }
    public static void main(String args[]) throws IOException, NullPointerException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st;
        st = new StringTokenizer(br.readLine()," ");

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        graph = new int[n][m];

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine()," ");

            for(int j = 0; j < m; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
                if(graph[i][j] == 1) {
                    queue.offer(new Point(i,j));
                }
            }
        }

        int[] preResult = Arrays.stream(graph).flatMapToInt(Arrays::stream).filter(data -> data == 0).toArray();

        if(preResult.length == 0) {
            System.out.println(0);
        } else {
            bfs();

            int[] result = Arrays.stream(graph).flatMapToInt(Arrays::stream).filter(data -> data == 0).toArray();

            if(result.length != 0) {
                System.out.println(-1);
            } else {
                System.out.println(Arrays.stream(graph).flatMapToInt(Arrays::stream).max().getAsInt() - 1);
            }
        }

    }
}
