import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_11399 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] array = new int[n];
        int[] answer = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        for(int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(array);

        answer[0] = array[0];

        for(int i = 1; i < n; i++) {
            answer[i] = answer[i-1] + array[i];
        }

        System.out.println(Arrays.stream(answer).sum());
    }
}
