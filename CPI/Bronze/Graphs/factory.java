import java.io.*;
import java.util.*;

public class factory{
    public static void main(String[]args)throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("factory.in"));
        int N = Integer.parseInt(br.readLine());
        int[] out = new int[N + 1];
        for(int i = 1; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            out[a]++;
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i = 1; i <= N; i++){
            if(out[i] == 0)
                ans.add(i);
        }
        PrintWriter pw = new PrintWriter("factory.out");
        if(ans.size() != 1){
            pw.println(-1);
        }
        else{
            pw.println(ans.get(0));
        }
        pw.close();
    }
}