import java.io.*;
import java.util.*;

public class Sharon{
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("sharon.dat"));

        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int G = Integer.parseInt(br.readLine());
        for(int i = 0; i < G; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int C = Integer.parseInt(st.nextToken());
            int N = Integer.parseInt(st.nextToken());
            String[] names = new String[N];
            for(int j = 0; j < N; j++){
                names[j] = st.nextToken();
            }
            boolean[] ok = new boolean[N];
            for(int j = 0; j < N; j++){
                ok[j] = true;
            }
            int curr = N - 1;
            int rem = N;
            while(rem > 1){
                int m = 0;
                while(m < C){
                    curr = (curr + 1) % N;;
                    if(ok[curr])
                        m++;
                    // System.out.println(names[curr] + " " + m);
                }
                // System.out.println(names[curr] + "die");
                ok[curr] = false;
                rem--;
            }
            for(int j = 0; j < N; j++){
                if(ok[j]){
                    System.out.print("The winner is "+ names[j]);
                }
            }
            if(i != N - 1)
                System.out.println();
        }

    }
}