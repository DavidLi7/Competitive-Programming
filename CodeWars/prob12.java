import java.io.*;
import java.util.*;

public class prob12{
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String name = st.nextToken();
        double s = Double.parseDouble(st.nextToken());
        String lengthunit = st.nextToken();
        st.nextToken();
        String timeunit = st.nextToken();
        if(lengthunit.equals("MILES")){
            s *= 5280.0;
            s /= 3.28;
        }
        if(lengthunit.equals("KILOMETERS")){
            s *= 1000.0;
        }
        if(lengthunit.equals("YARDS")){
            s *= 3.0;
            s /= 3.28;
        }
        if(lengthunit.equals("FEET")){
            s /= 3.28;
        }
        if(lengthunit.equals("INCHES")){
            s /= 12.0;
            s /= 3.28;
        }
        if(lengthunit.equals("CENTIMETERS")){
            s /= 100.0;
        }
        if(timeunit.equals("HOUR")){
            s /= 60.0;
            s /= 60.0;
        }
        if(timeunit.equals("MINUTE")){
            s /= 60.0;
        }
        double h = s * s / (2.0 * 9.805);
        System.out.print(name + " will launch the messenger ");
        System.out.printf("%.2f", h);
        System.out.print(" meters high, ");
        if(h >= 50.00){
            System.out.print("OUCH!");
        }
        else if(h >= 25.00){
            System.out.print("SUCCESS!");
        }
        else{
            System.out.print("SPLAT!");
        }
    }
}