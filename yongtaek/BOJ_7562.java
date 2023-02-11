import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class BOJ_7562 {
    static int l;
    static int startx;
    static int starty;
    static int endx;
    static int endy;
    static int[][] graph;
    static int[] dx = {-2, -1, 1, 2, 2, 1, -1, -2};
    static int[] dy = {1, 2, 2, 1, -1, -2, -2, -1};
    static LinkedList<Point> queue;
    static StringBuilder sb = new StringBuilder();

    public static class Point {
        private int x,y,depth;

        Point(int x, int y, int depth) {
            this.x = x;
            this.y = y;
            this.depth = depth;
        }
    }

    public static int bfs(int x, int y) {
        queue = new LinkedList<>();

        queue.offer(new Point(x,y,0));
        graph[x][y] = 1;

        while(!queue.isEmpty()) {
            Point point = queue.poll();

            int pointx = point.x;
            int pointy = point.y;
            int pointDepth = point.depth;

            if(pointx == endx && pointy == endy) {
                return pointDepth;
            }

            for(int i = 0 ; i < 8; i++) {
                int newx = pointx + dx[i];
                int newy = pointy + dy[i];
                int newDepth = pointDepth + 1;

                if(newx <= -1 || newy <= -1 || newx >= l || newy >= l) {
                    continue;
                }

                if(graph[newx][newy] == 0) {
                    graph[newx][newy] = 1;
                    queue.offer(new Point(newx, newy, newDepth));   
                }
            }
        }
        return 0;
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++) {
            l = Integer.parseInt(br.readLine());

            graph = new int[l][l];

            st = new StringTokenizer(br.readLine()," ");
            startx = Integer.parseInt(st.nextToken());
            starty = Integer.parseInt(st.nextToken());

            
            st = new StringTokenizer(br.readLine()," ");
            endx = Integer.parseInt(st.nextToken());
            endy = Integer.parseInt(st.nextToken());

            sb.append(bfs(startx, starty) + "\n");
        }

        System.out.println(sb);
    }
}
