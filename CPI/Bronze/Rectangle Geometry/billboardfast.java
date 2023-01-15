import java.io.*;
import java.util.*;

public class billboardfast{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("billboard.in"));

        StringTokenizer st = new StringTokenizer(br.readLine());
        Rectangle a = new Rectangle(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        st = new StringTokenizer(br.readLine());
        Rectangle b = new Rectangle(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        st = new StringTokenizer(br.readLine());
        Rectangle t = new Rectangle(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

        PrintWriter out = new PrintWriter(new FileWriter("billboard.out"));
        out.println(area(a) + area(b) - intersect_area(a, t) - intersect_area(b, t));
        out.close();
    }

    public static int area(Rectangle r){
        return (r.x2 - r.x1) * (r.y2 - r.y1);
    }

    public static int intersect_area(Rectangle p, Rectangle q){
        int x_overlap = Math.max(0, Math.min(p.x2, q.x2) - Math.max(p.x1, q.x1));
        int y_overlap = Math.max(0, Math.min(p.y2, q.y2) - Math.max(p.y1, q.y1));
        return x_overlap * y_overlap;
    }

    public static class Rectangle{
        int x1, y1, x2, y2;
        public Rectangle(int x1, int y1, int x2, int y2){
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
    }
}