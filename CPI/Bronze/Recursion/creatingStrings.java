import java.io.*;
import java.util.*;

public class creatingStrings{
    static boolean[] contains;
    static String s;
    static int N;
    static TreeSet<String> ans;
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s = br.readLine();
        N = s.length();
        contains = new boolean[N];
        ans = new TreeSet<>();
        generate("");
        System.out.println(ans.size());
        for(String x: ans){
            System.out.println(x);
        }
    }
    public static void generate(String curr){
        if(curr.length() == N){
            ans.add(curr);
            return;
        }
        for(int i = 0; i < N; i++){
            if(!contains[i]){
                contains[i] = true;
                generate(curr + s.charAt(i));
                contains[i] = false;
            }
        }
    }
}