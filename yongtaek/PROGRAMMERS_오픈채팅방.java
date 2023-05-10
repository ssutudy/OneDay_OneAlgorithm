import java.util.*;

class PROGRAMMERS_오픈채팅방 {
    public ArrayList<String> solution(String[] record) {
        ArrayList<String> answer = new ArrayList<>();
        
        HashMap<String, String> users = new HashMap<>(); 
        StringTokenizer st;
        
        for(int i = 0; i < record.length; i++) {
            st = new StringTokenizer(record[i]," ");
            
            switch(st.nextToken()) {
                case "Enter":
                case "Change":          
                    users.put(st.nextToken(), st.nextToken());
                    break;
            }
        }
        
        for(int i = 0; i < record.length; i++) {
            st = new StringTokenizer(record[i]," ");
            
            switch(st.nextToken()) {
                case "Enter":
                    answer.add(users.get(st.nextToken())+"님이 들어왔습니다.");
                    break;
                case "Leave":
                    answer.add(users.get(st.nextToken())+"님이 나갔습니다.");
                    break;
            }
        }
        
        return answer;
    }
}