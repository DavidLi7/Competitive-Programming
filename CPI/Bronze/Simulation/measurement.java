import java.io.*;
import java.util.*;

public class measurement {
    public static void main(String[]args) throws IOException{

        BufferedReader br = new BufferedReader(new FileReader("measurement.in"));

        int N = Integer.parseInt(br.readLine());
        int[] day = new int[N];
        String[] cow = new String[N];
        int[] change = new int[N];
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            day[i] = Integer.parseInt(st.nextToken());
			cow[i] = st.nextToken();
			change[i] = Integer.parseInt(st.nextToken());
        }
        int bessieMilk = 7, elsieMilk = 7, mildredMilk = 7;
        boolean bessieOn = true, elsieOn = true, mildredOn = true;
        int ans = 0;

        for(int d = 1; d <= 100; d++){
            for(int i = 0; i < N; i++){
                if(day[i] == d){
                    if(cow[i].equals("Bessie")) {
						bessieMilk += change[i];
					}
					if(cow[i].equals("Elsie")) {
						elsieMilk += change[i];
					}
					if(cow[i].equals("Mildred")) {
						mildredMilk += change[i];
					}
                }
            }
            int highestMilk = Math.max(bessieMilk, Math.max(elsieMilk, mildredMilk));
			boolean bessieOnNext = bessieMilk == highestMilk;
			boolean elsieOnNext = elsieMilk == highestMilk;
			boolean mildredOnNext = mildredMilk == highestMilk;
			if(bessieOn != bessieOnNext || elsieOn != elsieOnNext || mildredOn != mildredOnNext) {
				ans++;
			}
			bessieOn = bessieOnNext;
			elsieOn = elsieOnNext;
			mildredOn = mildredOnNext;
        }
        
        PrintWriter out = new PrintWriter(new FileWriter("measurement.out"));
        out.println(ans);
        out.close();
    }
}