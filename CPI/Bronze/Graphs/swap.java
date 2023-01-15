import java.io.*;
import java.util.*;

public class swap{
    static int A1, A2, B1, B2;
    public static void main(String[]args) throws IOException{
        //reading in input
        BufferedReader br = new BufferedReader(new FileReader(new File("swap.in")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        A1 = Integer.parseInt(st.nextToken());
        A2 = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        B1 = Integer.parseInt(st.nextToken());
        B2 = Integer.parseInt(st.nextToken());
        int[] res = new int[N + 1];
        
        //solve for each cow
        for (int i = 1; i <= N; ++i) {
            //p = how many turns so far?
            //cur = where are we after p turns?
            int p = 1, cur = nex(i);
            while (cur != i) { //keep going until we have found a cycle
                p++;
                cur = nex(cur);//simulating another turn
            }
            int k = K % p; //reduce k
            for (int j = 0; j < k; ++j)
                cur = nex(cur);
            res[cur] = i; // position of cow i after k steps is cur
        }

        PrintWriter out = new PrintWriter("swap.out");
        for(int i = 1; i <= N; i++){
            out.println(res[i]);
        }
        out.close();
    }
    public static int nex(int x) {//simulates a turn, or two steps
        if (A1 <= x && x <= A2)
            x = A1 + A2 - x;
        if (B1 <= x && x <= B2)
            x = B1 + B2 - x;
        return x;
    }
    
}