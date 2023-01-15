import java.io.*;
import java.util.*;

public class measurement {
    public static void main(String[]args) throws IOException{

        // Input stuff
        BufferedReader br = new BufferedReader(new FileReader("measurement.in"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int G = Integer.parseInt(st.nextToken());

        //stores the amount of milk that each cow produces
        // key = cow's id, value = cow's production
        HashMap<Integer, Integer> milk = new HashMap<>();//unordered_map

        //reading in input
        event[] events = new event[N];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            events[i] = new event(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
            milk.put(events[i].id, G);
        }

        //chronological order
        Arrays.sort(events);

        //stores the amount of cows that produce each amount of milk
        // key = amount of milk, value = # of cows that make that much milk
        TreeMap<Integer, Integer> cowcount = new TreeMap<>();// map
        cowcount.put(G, 1000000000);//1e9

        int ans = 0;

        for(event e: events){

            //store the values BEFORE the measurement
            int oldmx = cowcount.lastKey();
            int oldamt = cowcount.get(oldmx);
            boolean wastop = (milk.get(e.id) == oldmx);

            //erase our cow from the cowcount map, subtract 1 from the amount of cows that make old amt of milk
            cowcount.put(milk.get(e.id), cowcount.get(milk.get(e.id)) - 1);
            if(cowcount.get(milk.get(e.id)) == 0){
                cowcount.remove(milk.get(e.id));
            }

            //update the amount of milk of this cow
            milk.put(e.id, milk.get(e.id) + e.delta);

            //put our cow back on the cowcount map, add 1 to the amount of cows that make our NEW amt of milk
            if(!cowcount.containsKey(milk.get(e.id))){
                cowcount.put(milk.get(e.id), 1);
            }
            else{
                cowcount.put(milk.get(e.id), cowcount.get(milk.get(e.id)) + 1);
            }

            //store the values AFTER the measurement
            int newmx = cowcount.lastKey();
            int newamt = cowcount.get(newmx);
            boolean istop = (milk.get(e.id) == newmx);

            if(newamt != oldamt){
                ans++;
                continue;
            }
            //we start with only 1 cow that makes 11 units of milk, other cwos make 10 units. AFter the update, it makes 12 units of milk
            //old mx NOT EQUAL to new mx.

            //cow 10 -> 20 units, cow 10 lost 19 units of milk
            //cow 10 -> 1 unit of milk
            //Now, cow 9 is our new leader, with 19 units of milk of produciton
            //inc ans by 1

            //start with cow 10 -> 9 units
            //end with cows 10 AND 9 -> 8 units

            //all cows start w/ 10
            // cow 1 -> 12

            //all cows start with 10
            // cow 1-> 100 -> leaderboard is ONLY COW 1
            // day 2:
            //cow 1 -> 90 -> leader is STILL ONLY COW 1

            if(newmx != oldmx){
                if(wastop && oldamt == 1 && istop && newamt == 1){
                    continue;
                }
                ans++;
            }
        }

        //Output stuff
        // System.out.println(ans);
        PrintWriter out = new PrintWriter("measurement.out");
        out.print(ans);
        out.close();
        br.close();

    }

    static class event implements Comparable<event>{
        //variables
        int day, id, delta;

        //constructor
        public event(int day, int id, int delta){
            this.day = day;
            this.id = id;
            this.delta = delta;
        }

        //allows us to sort our events in chronological order
        public int compareTo(event E){
            return this.day - E.day;
        }
    }

    
}
//sort by our time

/*
Step: Simulate
What do we need to know?

How much milk each cow makes

For each amount of milk, how much cows make that much milk?
*/