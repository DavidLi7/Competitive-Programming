import java.io.*;
import java.util.*;

public class cowtip{
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("cowtip.in"));
        int N = Integer.parseInt(br.readLine());
        int[][] t = new int[N][N];
        for(int i = 0; i < N; i++){
            String s = br.readLine();
            for(int j = 0; j < N; j++){
                t[i][j] = s.charAt(j) - '0';
                //‘1’ - ‘0’= 1
                //‘0’ - ‘0’ = 0；
                //‘Z'-》 26
                //’Z'- ‘A' + 1;
            }
        }
        int ans = 0;
        for(int i = N - 1; i >= 0; i--){
            for(int j = N - 1; j >= 0; j--){
                if(t[i][j] == 1){
                    //flip
                    for(int k = 0; k <= i; k++){
                        for(int l = 0; l <= j; l++){
                            t[k][l] = 1 - t[k][l];
                            //0 -> 1
                            //1 - 0 = 1;
                        }
                    }
                    ans++;
                }
            }
        }
        PrintWriter out = new PrintWriter("cowtip.out");
        out.println(ans);
        out.close();
    }
}