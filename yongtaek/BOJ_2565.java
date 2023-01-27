import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class BOJ_2565 {
    static int[][] array;
    static int[] LIS;
 
    public static void LIS(int n) {
        for(int i = 1; i < n+1; i++) {
            LIS[i] = 1;
            for(int j = 1; j < i; j++) {
                if(array[i][1] >= array[j][1]) {
                    LIS[i] = Math.max(LIS[j]+1, LIS[i]);
                }
            }
        }
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());

        array = new int[n+1][2];
        LIS = new int[n+1];
    
        for(int i = 1; i < n + 1; i++) {
            st = new StringTokenizer(br.readLine()," ");
            for(int j = 0; j < 2; j++) {
                array[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        Arrays.sort(array, new Comparator<int[]>() {
            @Override
            public int compare(int[] row1, int[] row2){
                if(row1[0] == row2[0]){
                    return row1[1] - row2[1];
                } else {
                    return row1[0] - row2[0];
                }   
            }
        });

        LIS(n);

        System.out.println(n - Arrays.stream(LIS).max().getAsInt());
    }
}
