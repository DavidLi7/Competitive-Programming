import java.io.*;
import java.util.*;

public class paint{
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("paint.in"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        //loop from 0 to 100, for each segment, check if its within one of the bounds
        if(c < a){
            int temp = c;
            c = a;
            a = temp;
            temp = b;
            b = d;
            d = temp;
        }
        int ans = 0;
        if(b <= c){
            ans = (d - c) + (b - a);
        }
        else{
            if(d < b){
                ans = b - a; 
            }
            else{
                ans = d - a;
            }
        }
        PrintWriter out = new PrintWriter("paint.out");
        out.println(ans);
        out.close();
    }
}