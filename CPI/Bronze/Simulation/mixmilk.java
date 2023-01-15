import java.io.*;
import java.util.*;

public class mixmilk{

    static int[] m, c;

    public static void main(String[]args) throws IOException{
        
        BufferedReader br = new BufferedReader(new FileReader("mixmilk.in"));

        c = new int[3];
        m = new int[3];
        for(int i = 0; i < 3; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            c[i] = Integer.parseInt(st.nextToken());
            m[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < 33; i++){
            pour(0, 1);
            pour(1, 2);
            pour(2, 0);
        }
        pour(0, 1);

        PrintWriter out = new PrintWriter(new FileWriter("mixmilk.out"));
        for(int i = 0; i < 3; i++){
            out.println(m[i]);
        }
        out.close();
    }

    public static void pour(int a, int b){
        int amt = Math.min(m[a], c[b] - m[b]);
        m[a] -= amt;
        m[b] += amt;
    }
}

