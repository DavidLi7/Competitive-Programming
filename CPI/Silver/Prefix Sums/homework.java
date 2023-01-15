import java.io.*;
import java.util.*;

public class homework {
    public static void main(String[]args) throws IOException{
       
        //input stuff
        // BufferedReader br = new BufferedReader(new FileReader("homework.in"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        //read in input
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[]grades = new int[N];
        for(int i = 0; i < N; i++){
            grades[i] = Integer.parseInt(st.nextToken());
        }

        //actual algorithm
        ArrayList<Integer> ans = new ArrayList<>();
        double high = 0;
        int suffSum = grades[N - 1];
        int currMin = grades[N - 1];

        //range goes from K -> end

        for(int K = N - 2; K >= 1; K--){
            suffSum += grades[K];
            currMin = Math.min(currMin, grades[K]);
            double avg = (suffSum - currMin)/((double)(N - K - 1));//sum of Vals/ # of vals
            if(avg > high){
                ans.clear();
                ans.add(K);
                high = avg;
            }
            else if(avg == high){
                ans.add(K);
            }
        }

        //output stuff
        // PrintWriter out = new PrintWriter("homework.out");
        for(int i = ans.size() - 1; i >= 0; i--){
            System.out.println(ans.get(i));
            // out.println(ans.get(i));
        }
        // out.close();
        br.close();
    }
}

/*
SAMPLE INPUT:
5
3 1 9 2 7

if we eat K, we have N - K left. -> N - K - 1

SAMPLE OUTPUT:
2
*/