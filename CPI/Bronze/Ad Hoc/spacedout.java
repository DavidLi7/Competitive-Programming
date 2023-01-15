import java.io.*;
import java.util.*;

public class spacedout {
    public static void main (String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] grid = new int[N][N];
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int ans1 = 0;
        int ans2 = 0;
        for(int i = 0; i < N; i++){
            int[] sums = new int[2];
            for(int j = 0; j < N; j++){
                sums[j % 2] += grid[i][j];
            }
            ans1 += Math.max(sums[0], sums[1]);
        }
    
        for(int i = 0; i < N; i++){
            int[] sums = new int[2];
            for(int j = 0; j < N; j++){
                sums[j % 2] += grid[j][i];
            }
            ans2 += Math.max(sums[0], sums[1]);
        }

        System.out.println(Math.max(ans1, ans2));
    }
}
