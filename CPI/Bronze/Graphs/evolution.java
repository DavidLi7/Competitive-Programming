import java.io.*;
import java.util.*;

public class evolution{

    static int N;
    static ArrayList<String>[] ind;
    static ArrayList<String> all;

    public static void main(String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(new File("evolution.in")));
        N = Integer.parseInt(br.readLine());
        ind = new ArrayList[N];
        all = new ArrayList<>();
        for(int i = 0; i < N; i++){
            ind[i] = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int K = Integer.parseInt(st.nextToken());
            for(int j = 0; j < K; j++){
                String temp = st.nextToken();
                ind[i].add(temp);
                boolean alreadyexists = false;
                for(String x: all)
                    alreadyexists |= (temp.equals(x));
                if(!alreadyexists)
                    all.add(temp);
            }
        }

        boolean ok = true;
        for(int i = 0; ok && i < all.size(); i++)
            for(int j = i + 1; ok && j < all.size(); j++)
                if(crosses(i, j))
                    ok = false;

        PrintWriter out = new PrintWriter("evolution.out");
        if(ok)
            out.println("yes");
        else
            out.println("no");
        out.close();
    }

    public static boolean crosses(int a, int b){
        int A = 0, B = 0, AB = 0;
        for(int i = 0; i < N; i++){
            boolean has_a = false, has_b = false;
            for(String x: ind[i]){
                if(x.equals(all.get(a)))
                    has_a = true;
                if(x.equals(all.get(b)))
                    has_b = true;
            }
            if(has_a && has_b)
                AB++;
            else if(has_a)
                A++;
            else if(has_b)
                B++;
        }
        return A > 0 && B > 0 && AB > 0;
    }
}