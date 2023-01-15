import java.io.*;
import java.util.*;

public class citystate{
    public static void main(String[]args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("citystate.in"));
        int N = Integer.parseInt(br.readLine());

        TreeMap<String, Long> m = new TreeMap<>();
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String city = st.nextToken();
            String state = st.nextToken();
            if(!city.substring(0, 2).equals(state)){
                String key = city.substring(0, 2) + state;
                if(!m.containsKey(key))
                    m.put(key, 1L);
                else
                    m.put(key, m.get(key) + 1L);
            }
        }
        
        long ans = 0;
        for(String k: m.keySet()){
            String other = k.substring(2) + k.substring(0, 2);
            if(m.containsKey(other)){
                ans += m.get(other) * m.get(k);
            }
        }
        PrintWriter out = new PrintWriter("citystate.out");
        out.println(ans / 2);
        out.close();
    }
}