import java.util.*;
import java.io.*;

public class test{
    public static void main(String[]args){
        System.out.println(A.x + " " + A.y);
        System.out.println(new A().x);
    }
    static class A{
        static int x;
        static int y = x + 2;
        A(){
            x  = 5;
        }
        static{
            x = 6;
        }
    }
}