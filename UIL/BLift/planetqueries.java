import java.io.*;
import java.util.*;

public class planetqueries{
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out, true);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        //dp[x][0] = t[x]
        int[][] go = new int[N + 1][31];
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N; i++){
            go[i][0] = Integer.parseInt(st.nextToken());
        }
        for(int d = 1; d < 31; d++){
            for(int i = 1; i <= N; i++){
                go[i][d] = go[go[i][d - 1]][d - 1];
            }
        }
        for(int i = 0; i < Q; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());//5 - > 101
            for(int d = 30; d >= 0; d--){
                if((k & (1 << d)) != 0){
                    x = go[x][d];
                }
            }
            out.println(x);
        }
    }
}
/*
Input:
4 3
2 1 1 4
1 2
3 4
4 1

Output:
1
2
4
*/