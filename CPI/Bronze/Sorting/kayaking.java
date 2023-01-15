import java.io.*;
import java.util.*;

public class kayaking{
    public static void main(String[]args) throws IOException{

        //read in the input values
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] w = new int[2 * N];
        for(int i = 0; i < 2 * N; i++){
            w[i] = Integer.parseInt(st.nextToken());
        }

        //sort the people by weight
        Arrays.sort(w);

        int ans = (int)1e9;//this variable will store our answer

        //loop through all possible combinations of people in the single kayaks
        for(int i = 0; i < 2 * N; i++){
            for(int j = i + 1; j < 2 * N; j++){

                //Arraylist 's' will store the weights of the people who need to be placed in tandem kayaks
                ArrayList<Integer> s = new ArrayList<>();
                for(int k = 0; k < 2 * N; k++){
                    if(k != i && k != j)
                        s.add(w[k]);
                }

                int temp = 0;//this variable stores the instability of this situation

                //calculating instability
                for(int k = 0; k < 2 * N - 2; k += 2){
                    temp += s.get(k + 1) - s.get(k);
                }

                //if this instability is lower than our current answer, then update answer
                ans = Math.min(ans, temp);
            }
        }
        
        //print the answer
        System.out.println(ans);
    }
}