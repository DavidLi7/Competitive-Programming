import java.util.*;
import java.io.*;
public class test
{
  public static void main (String[]args) throws Exception
  {
    BufferedReader br =  new BufferedReader (new InputStreamReader (System.in));
    //BufferedReader br= new BufferedReader(new FileReader("mouses.in"));
    //PrintWriter pw= new PrintWriter(new FileWriter("mouses.out"));
    StringTokenizer st = new StringTokenizer (br.readLine ());
    int a = Integer.parseInt (st.nextToken ());
    int b = Integer.parseInt (st.nextToken ());
    int c = Integer.parseInt (st.nextToken ());
    int m = Integer.parseInt (br.readLine ());
    long[][] prices = new long[m][2];
    for (int i = 0; i < m; i++){
      st = new StringTokenizer (br.readLine ());
      prices[i][0] = Long.parseLong (st.nextToken ());
      if (st.nextToken ().equals ("USB")){
        prices[i][1] = 0;
      }
      else{
        prices[i][1] = 1;
      }
    }
    Arrays.sort (prices, (x, y)->Double.compare (x[0], y[0]));
    int check = 0;
    int count = 0;
    long total = 0;
    while (check < m && (a > 0 || b > 0 || c > 0)){
      if (prices[check][1] == 0 && a > 0){
        a--;
        count++;
        total += prices[check][0];
      }
      else if (prices[check][1] == 1 && b > 0){
        b--;
        count++;
        total += prices[check][0];
      }
      else if (c > 0){
        c--;
        count++;
        total += prices[check][0];
      }
      check++;
    }
    /*
    pw.print(count+" "+total);
       pw.close();
       */
    System.out.print (count + " " + total);
  }
  /*public static void printArray(int[][] array){
     for(int i=array.length-1;i>=0;i--){
     for(int j=0;j<array.length;j++){
     System.out.print(array[j][i]+" ");
     }
     System.out.print("\n");
     }
     }//printing an array */
}
