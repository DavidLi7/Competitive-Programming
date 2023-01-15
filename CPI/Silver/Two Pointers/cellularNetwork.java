import java.io.*;
import java.util.*;

public class cellularNetwork {
    public static void main(String[]args) throws IOException{
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        long[]cities = new long[N];
        long[]towers = new long[M];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            cities[i] = Long.parseLong(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < M; i++){
            towers[i] = Long.parseLong(st.nextToken());
        }
        
        long max = 0;
        for(int i = 0, j = 0; i < N; i++){
            while(j < M - 1 && Math.abs(cities[i] - towers[j + 1]) <= Math.abs(cities[i] - towers[j])){
                j++;
            }
            max = Math.max(max, Math.abs(cities[i] - towers[j]));
        }
        System.out.println(max);



    }
}

/*

Input:
3  2
-2 2 4
-3 0

Output: 
4

Input:
5 3
1 5 10 14 17
4 11 15

Output:
3
*/