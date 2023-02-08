import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class BOJ_2667 {
    static int n;
    static int[][] graph;
    static int aptComplexNum = 0;
    static StringBuilder sb = new StringBuilder();

    public static Boolean dfs(int x, int y) {
        if(x <= -1 || x >= n || y <= -1 || y >= n) {
            return false;
        }

        if(graph[x][y] == 1) {
            graph[x][y] = 0;

            dfs(x+1,y);
            dfs(x-1,y);
            dfs(x,y-1);
            dfs(x,y+1);

            aptComplexNum++;

            return true;
        }

        return false;

    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        graph = new int[n][n];
        ArrayList<Integer> answer = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            String input = br.readLine();
            for(int j = 0; j < n; j++) {
                graph[i][j] = Character.getNumericValue(input.charAt(j));
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs(i,j) == true) {
                    count++;
                    answer.add(aptComplexNum);
                    aptComplexNum = 0;
                }
            }
        }

        Collections.sort(answer);

        System.out.println(count);

        answer.stream().forEach(s->{
            System.out.println(s);
        });
    }
}
