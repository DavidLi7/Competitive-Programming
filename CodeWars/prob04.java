import java.io.*;
import java.util.*;

public class prob04{
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[]s = new String[N];
        for(int i = 0; i < N; i++){
            s[i] = br.readLine();
        }
        for(int i = N - 1; i >= 0; i--){
            System.out.println(s[i]);
        }
    }
}