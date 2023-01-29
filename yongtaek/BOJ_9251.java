import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_9251 { 
    static String str1;
    static String str2;
    static int result[][];

    static void LCS(int length, int length2) {
        for(int i = 1; i < length + 1 ; i++) {
            for(int j = 1; j < length2 + 1; j++) {
                result[i][j] = 0;

                if(str1.charAt(i-1) == str2.charAt(j-1)) {
                    result[i][j] = result[i-1][j-1] + 1;
                } else {
                    result[i][j] = Math.max(result[i-1][j], result[i][j-1]);
                }
            }
        }
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        str1 = br.readLine();
        str2 = br.readLine();

        int length = str1.length();
        int length2 = str2.length();

        result = new int[length+1][length2+1];

        LCS(length, length2);

        System.out.println(result[length][length2]);
    }
}