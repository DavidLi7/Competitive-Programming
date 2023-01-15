import java.io.*;
import java.util.*;

public class gymnastics{
    public static void main(String[]args) throws IOException{
        //reading in input
        BufferedReader br = new BufferedReader(new FileReader("gymnastics.in"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int[][] data = new int[K][N];//stores the input data
        int[][] better = new int[N][N];//stores how many times cow a comes before cow b

        //reading in input
        for(int i = 0; i < K; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                data[i][j] = Integer.parseInt(st.nextToken()) - 1;
            }
        }

        //calculating the amount of times that cow a comes before cow b
        for(int i = 0; i < K; i++){//looping over the trials
            for(int j = 0; j < N; j++){//data[i][j] = cow a
                for(int k = j + 1; k < N; k++){//data[i][k] = cow b
                    better[data[i][j]][data[i][k]]++;
                }
            }
        }

        //calculating answer
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(better[i][j] == K)//if cow i comes before cow j K times then increment our answer
                    ans++;
            }
        }

        //print answer
        PrintWriter out = new PrintWriter("gymnastics.out");
        out.print(ans);
        out.close();
    }
}