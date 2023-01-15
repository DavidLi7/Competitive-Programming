import java.io.*;
import java.util.*;

public class Eugene{
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("eugene.dat"));

        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        TreeSet<String> initials = new TreeSet<>();
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String first = st.nextToken();
            String last = st.nextToken();
            System.out.print(first + " " + last + " ");
            System.out.print(first.substring(0, 1).toLowerCase());
            System.out.print(last.substring(0, 1).toLowerCase());
            int f = (int)first.charAt(0);
            int s = (int)last.charAt(0);
            while(initials.contains(first.substring(0, 1).toLowerCase() + last.substring(0, 1).toLowerCase() + Character.toString((char)f) + Character.toString((char)s)))
                f++;
            initials.add(first.substring(0, 1).toLowerCase() + last.substring(0, 1).toLowerCase() + Character.toString((char)f) + Character.toString((char)s));
            System.out.print(f + "" + s);
            if(i != N - 1){
                System.out.println();
            }
        }
    }
}