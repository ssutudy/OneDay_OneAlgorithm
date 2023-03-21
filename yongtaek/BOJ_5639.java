import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_5639 {
    public static class Node {
        int num;
        Node left, right;

        Node(int num) {
            this.num = num;
        }

        void input(int inputNum) {
            //left
            if(inputNum < this.num) {
                if(this.left == null) {
                    this.left = new Node(inputNum);
                } else {
                    this.left.input(inputNum);
                }
            } else { //right
                if(this.right == null) {
                    this.right = new Node(inputNum);
                } else {
                    this.right.input(inputNum);
                }
            }
        }
    }
    public static void preOrder(Node node) {
        if(node.left != null) {
            preOrder(node.left);
        }
        if(node.right != null) {
            preOrder(node.right);
        }

        System.out.println(node.num);
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int root = Integer.parseInt(br.readLine());

        Node node = new Node(root);

        String input;

        while(true) {
            input = br.readLine();

            if(input == null || input.equals("")) {
                break;
            }
            node.input(Integer.parseInt(input));
        }

        preOrder(node);
    }    
}
