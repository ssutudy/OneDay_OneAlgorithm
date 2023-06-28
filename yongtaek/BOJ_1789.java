import java.io.*;

public class BOJ_1789 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Long S = Long.parseLong(br.readLine());

        long sum = 0;
        int N = 0;

        for(int i = 2; i <= S; i++) {
            if(sum + i >= S) {
                N = i - 1;
                break;
            }
            sum += i;
        }

        if(S == 1) {
            System.out.println(1);
        } else {
            System.out.println(N);
        }
    }
}
