import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.StringBuilder;
import java.util.StringTokenizer;

public class BOJ_11659 { 
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        
        st = new StringTokenizer(br.readLine()," ");

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        int[] array = new int[n];
        int[] answer = new int[n];
        
        st = new StringTokenizer(br.readLine()," ");
        
        for(int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }
        
        answer[0] = array[0];
        
        for(int i = 1; i < n; i++) {
            answer[i] = answer[i-1] + array[i];
        }
        
        
        for(int i = 0 ; i < m; i++) {
            st = new StringTokenizer(br.readLine()," ");
            
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            
            int result;
            
            if(a == b) result = array[b];
            else if(a == 0) result = answer[b];
            else result = answer[b] - answer[a-1]; 
            
            sb.append(result + "\n");
        }
        
        System.out.println(sb);
    }
}