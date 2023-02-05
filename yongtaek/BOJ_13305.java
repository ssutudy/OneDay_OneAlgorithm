import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_13305 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());

        Long[] length = new Long[n-1];
        Long[] cost = new Long[n];

        st = new StringTokenizer(br.readLine()," ");
        for(int i = 0; i < n-1; i++) {
            length[i] = Long.parseLong(st.nextToken());
        }

        st = new StringTokenizer(br.readLine()," ");
        for(int i = 0; i < n; i++) {
            cost[i] = Long.parseLong(st.nextToken());
        }

        Long topCost = cost[0];
        Long total = cost[0] * length[0];

        for(int i = 1; i < n-1; i++) {
            if(cost[i] < topCost) {
                total += cost[i] * length[i];
                topCost= cost[i];
            } else {
                total += topCost * length[i];
            }
        }

        System.out.println(total);
    }
}
