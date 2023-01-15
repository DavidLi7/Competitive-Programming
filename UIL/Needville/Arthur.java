import java.io.*;
import java.util.*;

public class Arthur{
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("arthur.dat"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[]nums = new int[3];
            for(int j = 0; j < 3; j++){
                nums[j] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(nums);
            System.out.print(nums[0] + ", ");
            System.out.print(nums[1] + ", ");
            System.out.print(nums[2] + " is");
            if(nums[0] * nums[0] + nums[1] * nums[1] != nums[2] * nums[2]){
                System.out.print(" not");
            }
            System.out.print(" a Pythagorean triple.");
            if(i != N - 1)
                System.out.println();
        }
    }
}