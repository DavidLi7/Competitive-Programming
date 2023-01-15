import java.io.*;
import java.util.*;

public class ToiletSeat{
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        //Solving case 1
        int curr = 0;
        char prev = s.charAt(0);
        for(int i = 1; i < s.length(); i++){
            if(s.charAt(i) != prev)
                curr++;
            if(s.charAt(i) != 'U')//s[i] == 'D'
                curr++;
            prev = 'U';
        }
        System.out.println(curr);

        //Solving case 2
        curr = 0;
        prev = s.charAt(0);
        for(int i = 1; i < s.length(); i++){
            if(s.charAt(i) != prev)
                curr++;
            if(s.charAt(i) != 'D')//s[i] = 'U'
                curr++;
            prev = 'D';
        }
        System.out.println(curr);

        //Solving case 3
        curr = 0;
        prev = s.charAt(0);
        for(int i = 1; i < s.length(); i++){
            if(s.charAt(i) != prev)
                curr++;
            prev = s.charAt(i);
        }
        System.out.println(curr);
        
    
    }
}