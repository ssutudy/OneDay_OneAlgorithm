import java.util.*;

class PROGRAMMERS_주차요금계산 {
    public ArrayList<Integer> solution(int[] fees, String[] records) {
        ArrayList<Integer> answer = new ArrayList<>();
        StringTokenizer st;
        StringTokenizer st2;
        Map<Integer, Integer> totalCar = new TreeMap<>();
        Map<Integer, Integer> car = new TreeMap<>();

        int basicTime = fees[0];
        int basicFee = fees[1];
        int timeRate = fees[2];
        int feeRate = fees[3];
        
        for(int i = 0; i < records.length; i++) {
            st = new StringTokenizer(records[i], " ");   
            
            int time = 0;
            int carNum = 0;
            String inOut = "";
            
            for(int j = 0; j < 3; j++) {
                String tempValue = st.nextToken();
                if(j == 0) {
                    st2 = new StringTokenizer(tempValue, ":");
                    for(int k = 0; k < 2; k++) {
                        int tempTime = Integer.parseInt(st2.nextToken());

                        if(k == 0) {
                            time += tempTime * 60;
                        } else {
                            time += tempTime;
                        }
                    }
                }
                
                if(j == 1) {
                    carNum = Integer.parseInt(tempValue);
                }
                
                if(j == 2) {
                    inOut = tempValue;
                }
            }
            
            if(inOut.equals("IN")) {
                car.put(carNum, time);
            } else if(inOut.equals("OUT")) {
                if(totalCar.containsKey(carNum)) {
                    totalCar.put(carNum, (time - car.get(carNum)) + totalCar.get(carNum));
                } else {
                    totalCar.put(carNum, time - car.get(carNum));
                }
                car.remove(carNum);
            }
        }
        
        for (Map.Entry<Integer, Integer> e : car.entrySet()) {
            if(totalCar.containsKey(e.getKey())) {
                    totalCar.put(e.getKey(), (1439 - e.getValue()) + totalCar.get(e.getKey()));
            } else {
                    totalCar.put(e.getKey(), 1439 - e.getValue());
            }
        }
        
        for (Map.Entry<Integer, Integer> e : totalCar.entrySet()) {      
            if(e.getValue() <= basicTime) {
                answer.add(basicFee);
                continue;
            }
            
            double parsed = Math.abs((e.getValue() - basicTime));
            
            answer.add(basicFee + (int) Math.ceil(parsed / timeRate) * feeRate); 
        }
        
        return answer;
    }
}