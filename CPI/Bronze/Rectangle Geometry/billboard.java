import java.io.*;
import java.util.*;

public class billboard{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("billboard.in"));
        
        boolean[][] ok = new boolean[2001][2001];

        //billboard 1
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x1 = Integer.parseInt(st.nextToken());
        int y1 = Integer.parseInt(st.nextToken());
        int x2 = Integer.parseInt(st.nextToken());
        int y2 = Integer.parseInt(st.nextToken());
        for(int i = x1; i < x2; i++){
            for(int j = y1; j < y2; j++){
                ok[i + 1000][j + 1000] = true;
            }
        }

        //billboard 2
        st = new StringTokenizer(br.readLine());
        x1 = Integer.parseInt(st.nextToken());
        y1 = Integer.parseInt(st.nextToken());
        x2 = Integer.parseInt(st.nextToken());
        y2 = Integer.parseInt(st.nextToken());
        for(int i = x1; i < x2; i++){
            for(int j = y1; j < y2; j++){
                ok[i + 1000][j + 1000] = true;
            }
        }

        //truck
        st = new StringTokenizer(br.readLine());
        x1 = Integer.parseInt(st.nextToken());
        y1 = Integer.parseInt(st.nextToken());
        x2 = Integer.parseInt(st.nextToken());
        y2 = Integer.parseInt(st.nextToken());
        for(int i = x1; i < x2; i++){
            for(int j = y1; j < y2; j++){
                ok[i + 1000][j + 1000] = false;
            }
        }

        int ans = 0;
        for(int i = 0; i < 2000; i++){
            for(int j = 0; j < 2000; j++){
                if(ok[i][j])
                    ans++;
            }
        }

        PrintWriter out = new PrintWriter(new FileWriter("billboard.out"));
        out.println(ans);
        out.close();
    }
}