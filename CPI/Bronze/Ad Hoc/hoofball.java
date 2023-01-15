import java.io.*;
import java.util.*;

public class hoofball{

    static int N;
    static int[] x, passto;
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader(new File("hoofball.in")));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        x = new int[N];
        passto = new int[N];
        for(int i = 0; i < N; i++){
            x[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < N; i++){
            passto[target(i)]++;
        }

        int ans = 0;
        for(int i = 0; i < N; i++){
            if(passto[i] == 0)
                ans++;
            if(i < target(i) && target(target(i)) == i && passto[i] == 1 && passto[target(i)] == 1)
                ans++;
        }

        PrintWriter out = new PrintWriter("hoofball.out");
        out.println(ans);
        out.close();

    }
    public static int target(int i){
        int l = -1, ld = 1000;
        int r = -1, rd = 1000;
        for(int j = 0; j < N; j++){
            if(x[j] < x[i] && x[i] - x[j] < ld){
                l = j;
                ld = x[i] - x[j];
            }
            if(x[j] > x[i] && x[j] - x[i] < rd){
                r = j;
                rd = x[j] - x[i];
            }
        }
        if(ld <= rd)
            return l;
        return r;
    }
}