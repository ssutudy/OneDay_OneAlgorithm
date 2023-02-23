import java.io.*;
import java.util.*;

public class BOJ_2630 {
    static int[][] paper;
    static int countWhite = 0;
    static int countBlue = 0;

    public static Boolean chkColor(int xstart, int ystart, int middle) {
        int standard = paper[xstart][ystart];
        Boolean isFilled = true;

        for(int i = xstart; i < xstart + middle ; i++) {
            for(int j = ystart; j < ystart + middle; j++) {
                if(paper[i][j] != standard) {
                    isFilled = false;
                }
            }
        }

        if(isFilled) {
            if(standard == 0) {
                countWhite++;
            } else {
                countBlue++;
            }
        }

        return isFilled;
    }

    public static Boolean fold(int xstart, int ystart, int middle) {
        if(chkColor(xstart, ystart, middle)) {
            return true;
        }

        int newMiddle = 0;

        if(middle % 2 == 0) {
            newMiddle = middle / 2;
        } else {
            newMiddle = (middle / 2) + 1;
        }

        fold(xstart, ystart, newMiddle);
        fold(xstart + newMiddle, ystart, newMiddle);
        fold(xstart, ystart + newMiddle, newMiddle);
        fold(xstart+ newMiddle, ystart + newMiddle, newMiddle);

        return true;
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;

        paper = new int[n+1][n+1];

        for(int i = 1; i < n+1; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j < n+1; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        fold(1, 1, n);

        System.out.println(countWhite);
        System.out.println(countBlue);
    }
}
