import java.io.*;
import java.util.*;

public class BOJ_1764 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Set<String> Aset = new TreeSet<>();
        Set<String> Bset = new TreeSet<>();₩

        for (int i = 0; i < n; i++) {
            Aset.add(br.readLine());
        }
        for (int i = 0; i < m; i++) {
            Bset.add(br.readLine());
        }

        Aset.retainAll(Bset);

        sb.append(Aset.size()).append("\n");
        for (String s : Aset) {
            sb.append(s).append("\n");
        }
        System.out.println(sb);
    }
}