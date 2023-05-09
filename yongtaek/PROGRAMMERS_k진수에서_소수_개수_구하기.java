import java.util.*;

class PROGRAMMERS_k진수에서_소수_개수_구하기 {
    private String convert(int n, int k) {
        String s = "";
        
        while(true) {
            int leftover = n % k;
            
            s = String.valueOf(leftover) + s;
            
            if((n / k) < k) {
                s = String.valueOf(n/k) + s;
                break;
            }
            n = n / k;
        }
        
        return s;
    }
    
    private Boolean isDecimal(long k) {
        if(k == 1) return false;
        
        for(int i = 2; i <= Math.sqrt(k); i++) {
            if((k % i) == 0) {
                return false;
            } 
        }
        return true;
    }
    
    public int solution(int n, int k) {
        int answer = 0;
        
        String converted = convert(n,k);
        
        StringTokenizer st = new StringTokenizer(converted,"0");
        
        while(st.hasMoreTokens()) {
            long num = Long.parseLong(st.nextToken());
            
            if(isDecimal(num)) {
                answer++;
            }
        }
        
        return answer;
    }
}