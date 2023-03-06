import java.io.*;
import java.util.*;

public class BOJ_1620 {
    public static boolean isNumeric(String s) {
        return s != null && s.matches("[-+]?\\d*\\.?\\d+");
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        HashMap<String, Integer> pokiDic = new HashMap<String, Integer>();
        HashMap<Integer, String> pokiDicIdx = new HashMap<Integer, String>();

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++) {
            String pokimon = br.readLine();
            pokiDic.put(pokimon, i+1);
            pokiDicIdx.put(i+1, pokimon);
        }

        for(int i = 0; i < m; i++) {
            String problem = br.readLine();
            if(isNumeric(problem)) {
                int num = Integer.parseInt(problem);
                sb.append(pokiDicIdx.get(num) + "\n");
            } else {
                sb.append(pokiDic.get(problem) + "\n");
            }
        }

        System.out.println(sb);
    }
}
