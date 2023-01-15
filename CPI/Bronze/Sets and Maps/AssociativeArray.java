import java.io.*;
import java.util.*;

public class AssociativeArray{
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int Q = Integer.parseInt(br.readLine());

        TreeMap<Long, Long> m = new TreeMap<>();

        for(int i = 0; i < Q; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(st.nextToken());

            if(type == 1){
                long k = Long.parseLong(st.nextToken());
                if(m.containsKey(k))
                    System.out.println(m.get(k));
                else
                    System.out.println(0);
            }
            
            else{
                long k = Long.parseLong(st.nextToken());
                long v = Long.parseLong(st.nextToken());
                m.put(k, v);
            }
        }
    }
}