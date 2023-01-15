import java.io.*;
import java.util.*;
public class promote{
    public static void main(String[]args) throws IOException{
        
        Scanner in = new Scanner(new File("promote.in"));
        PrintWriter out = new PrintWriter("promote.out");

        //bronze
        int initialBronze = in.nextInt();
        int finalBronze = in.nextInt();

        //silver
        int initialSilver = in.nextInt();
        int finalSilver = in.nextInt();

        //gold
        int initialGold = in.nextInt();
        int finalGold = in.nextInt();

        //plat
        int initialPlat = in.nextInt();
        int finalPlat = in.nextInt();
        //cin >> finalPlat

        //SOLVE!!!
        int goldtoPlat = finalPlat - initialPlat;
        int silvertoGold = (finalPlat + finalGold) - (initialPlat + initialGold);
        int bronzetoSilver = (finalPlat + finalGold + finalSilver) - (initialPlat + initialGold + initialSilver);

        //Output
        //cout << ans
        out.println(bronzetoSilver);
        out.println(silvertoGold);
        out.println(goldtoPlat);
        out.close();
    }

}

