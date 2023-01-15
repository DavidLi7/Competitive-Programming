import java.io.*;
import java.util.*;
public class Studying{
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        int[] a = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(a);//3, 3, 4, 4, whatever
        int curr = 0;
        int ans = 0;
        while(ans < N && curr + a[ans] <= X){
            curr += a[ans];
            ans++;
        }
        System.out.println(ans);
    }
}