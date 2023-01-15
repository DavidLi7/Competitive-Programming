import java.io.*;
import java.util.*;

public class Hannah{

    static HashMap<Character, Long> m;
    static HashMap<Long, Character> m2;

    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("hannah.dat"));

        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        m = new HashMap<>();
        m2 = new HashMap<>();
        m.put('0', 0L);
        m.put('1', 1L);
        m.put('2', 2L);
        m.put('3', 3L);
        m.put('4', 4L);
        m.put('5', 5L);
        m.put('6', 6L);
        m.put('7', 7L);
        m.put('8', 8L);
        m.put('9', 9L);
        m.put('A', 10L);
        m.put('B', 11L);
        m.put('C', 12L);
        m.put('D', 13L);
        m.put('E', 14L);
        m.put('F', 15L);
        m2.put(0L, '0');
        m2.put(1L, '1');
        m2.put(2L, '2');
        m2.put(3L, '3');
        m2.put(4L, '4');
        m2.put(5L, '5');
        m2.put(6L, '6');
        m2.put(7L, '7');
        m2.put(8L, '8');
        m2.put(9L, '9');
        m2.put(10L, 'A');
        m2.put(11L, 'B');
        m2.put(12L, 'C');
        m2.put(13L, 'D');
        m2.put(14L, 'E');
        m2.put(15L, 'F');

        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++){
            long B = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            String a = st.nextToken();
            String op = st.nextToken();
            String b = st.nextToken();
            long aval = convertToDecimal(a, B);
            long bval = convertToDecimal(b, B);
            long result = 0L;
            if(op.equals("*"))
                result = aval * bval;
            else if(op.equals("/"))
                result = aval / bval;
            else if(op.equals("+"))
                result = aval + bval;
            else
                result = aval - bval;
            String res = convertFromDecimal(Math.abs(result), B);
            if(result < 0L)
                res = "-" + res;
            System.out.print(a + " " + op + " " + b + " = " + res);
            if(i != N - 1)
                System.out.println();
        }
    }

    public static long convertToDecimal(String s, long b){
        long pow = 1;
        long ret = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            ret += m.get(s.charAt(i)) * pow;
            pow *= b;
        }
        return ret;
    }

    public static String convertFromDecimal(long x, long b){
        String s = "";
        while(x > 0){
            s += m2.get(x % b);
            x /= b;
        }
        String ret = "";
        for(int i = s.length() - 1; i >= 0; i--){
            ret += s.charAt(i);
        }
        if(ret.length() == 0)
            ret += "0";
        return ret;
    }
}