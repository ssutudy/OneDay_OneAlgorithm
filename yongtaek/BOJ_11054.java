import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_11054 {
    static int[] LIS;
    static int[] LDS;
    static int[] array; 

    static void LIS(int n) {
        for(int i = 0; i < n; i++) {
            LIS[i] = 1;
            for(int j = 0; j < i; j++) {
                if(array[i] > array[j]) {
                    LIS[i] = Math.max(LIS[i], LIS[j] + 1);
                }
            }
        }
    }

    static void LDS(int n) {
        for(int i = n - 1; i >= 0; i--) {
            LDS[i] = 1;
            for(int j = n - 1; j > i; j--) {
                if(array[i] > array[j]) {
                    LDS[i] = Math.max(LDS[i], LDS[j] + 1);
                }
            }
        }
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        array = new int[n];
        LIS = new int[n];
        LDS = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        for(int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }

        LIS(n);
        LDS(n);   
        
        int max = 0;
        for(int i = 0; i < n; i++) {
            int temp = LIS[i] + LDS[i];
            if(temp > max) max = temp;
        }

        System.out.println(max - 1);
    }
}
