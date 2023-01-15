import java.io.*;
import java.util.*;

public class SumOfTwoValues{
    public static void main(String[]args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        //creating and reading in the number of nodes and the target value
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());

        //creating and reading in the array
        st = new StringTokenizer(br.readLine());
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }

        //Vals stores the location of every value in the array
        //The keys are values and they map to locations.
        boolean Answer_Found = false;
        HashMap<Integer, Integer> vals = new HashMap<>();
        for(int i = 0; i < n; i++){
            //checking if we have seen the value x - a[i] before
            if(vals.containsKey(x - a[i])){
                //Print answer and terminate program if we find one
                System.out.println((i + 1) + " " + vals.get(x - a[i]));
                Answer_Found = true;
                break;
            }
            //adding new element to our map
            vals.put(a[i], i + 1);
        }
        //If no solution, print "IMPOSSIBLE"
        if(!Answer_Found)
            System.out.println("IMPOSSIBLE");
    }
}