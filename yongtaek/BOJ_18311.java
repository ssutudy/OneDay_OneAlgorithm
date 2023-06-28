import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_18311 {
    static int moveX[] = {0, -1, 0, 1};
    static int moveY[] = {1, 0, -1, 0};

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < T; i++) {
            int direction = 0; 
            int x = 0; 
            int y = 0;
            int max_x = 0;
            int max_y = 0;
            int min_x = 0;
            int min_y = 0;
            String command = br.readLine();
            for(int j = 0; j < command.length(); j++) {
                switch(command.charAt(j)) {
                    case 'F': 
                        x += moveX[direction];
                        y += moveY[direction];
                        break;
                    case 'B':
                        x -= moveX[direction];
                        y -= moveY[direction];
                        break;
                    case 'L':
                        if (direction == 3) {
                            direction = 0;
                        } else {
                            direction += 1;
                        }
                        break;
                    case 'R':
                        if (direction == 0) {
                            direction = 3;
                        } else {
                            direction -= 1;
                        }
                        break;
                }
                min_x = Math.min(min_x, x);
                min_y = Math.min(min_y, y);
                max_x = Math.max(max_x, x);
                max_y = Math.max(max_y, y);
            }
            sb.append((Math.abs(min_x) + Math.abs(max_x)) * (Math.abs(min_y) + Math.abs(max_y)) + "\n");
        }
        System.out.println(sb.toString());
    }
}
