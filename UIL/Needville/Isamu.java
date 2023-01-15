import java.io.*;
import java.util.*;

public class Isamu{
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("isamu.dat"));

        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int it = 0; it < T; it++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int C = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());
            HashMap<String, Integer> ntoi = new HashMap<>();
            ArrayList<edge>[] adj = new ArrayList[C];
            for(int i = 0; i < C; i++){
                adj[i] = new ArrayList<>();
            }
            String[]names = new String[C];
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < C; i++){
                names[i] = st.nextToken();
                ntoi.put(names[i], i);
            }
            for(int i = 0; i < R; i++){
                st = new StringTokenizer(br.readLine());
                int a = ntoi.get(st.nextToken());
                int b = ntoi.get(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                adj[a].add(new edge(b, w));
                adj[b].add(new edge(a, w));
            }
            int[][] dp = new int[(1 << (C))][C];
            for(int i = 0; i < (1 << (C)); i++){
                for(int j = 0; j < C; j++){
                    dp[i][j] = -1;
                }
            }
            int[][] dist = new int[C][C];
            for(int i = 0; i < C; i++){
                for(int j = 0; j < C; j++){
                    dist[i][j] = -1;
                }
            }
            for(int i = 0; i < C; i++){
                PriorityQueue<state> PQ = new PriorityQueue<>();
                PQ.add(new state(i, 0, 0));
                while(!PQ.isEmpty()){
                    state temp = PQ.poll();
                    if(dist[i][temp.loc] != -1)
                        continue;
                    dist[i][temp.loc] = temp.w;
                    for(edge v: adj[temp.loc]) if(dist[i][v.to] == -1){
                        PQ.add(new state(v.to, temp.w + v.w, 0));
                    }
                }
            }
            PriorityQueue<state> PQ = new PriorityQueue<>();
            // for(int i = 0; i < C; i++){
                PQ.add(new state(0, 0, (1 << 0)));
            // }
            while(!PQ.isEmpty()){
                state temp = PQ.poll();
                if(dp[temp.mask][temp.loc] != -1)
                    continue;
                dp[temp.mask][temp.loc] = temp.w;
                for(int i = 0; i < C; i++){
                    if(((1 << i) & temp.mask) == 0){
                        if(dp[temp.mask + (1 << i)][i] == -1){
                            PQ.add(new state(i, temp.w + dist[temp.loc][i], temp.mask ^ (1 << i)));
                        }
                    }
                }
            }
            int ans = (int)1e9;
            for(int i = 0; i < C; i++){
                if(dp[(1 << C) - 1][i] != -1){
                    ans = Math.min(ans, dp[(1 << C) - 1][i]);
                }
            }
            System.out.println("Case #" + (it + 1) + ": " + ans);
            // for(int i = 0; i < (1 << (C)); i++){
            //     for(int j = 0; j < C; j++){
            //         System.out.println(i + " " + j + " " + dp[i][j]);
            //     }
            // }
        }

    }

    static class edge{
        int to, w;
        public edge(int to, int w){
            this.to = to;
            this.w = w;
        }
    }

    static class state implements Comparable<state>{
        int loc, w, mask;
        public state(int loc, int w, int mask){
            this.w = w;
            this.loc = loc;
            this.mask = mask;
        }

        public int compareTo(state o) {
            return this.w - o.w;
        }
    }
}