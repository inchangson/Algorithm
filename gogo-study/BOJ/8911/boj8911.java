import java.util.*;
import java.io.*;

public class boj8911{
    static InputStreamReader isr = new InputStreamReader(System.in);
    static BufferedReader br = new BufferedReader(isr);
    static StringBuilder sb = new StringBuilder();

    static final int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    static final int R = 0;
    static final int C = 1;

    static int curMinR;
    static int curMinC;
    static int curMaxR;
    static int curMaxC;

    static int d;// north
    static int r;
    static int c;
    
    static void updateMinMax(){
        curMinR = Math.min(r, curMinR);
        curMinC = Math.min(c, curMinC);
        curMaxR = Math.max(r, curMaxR);
        curMaxC = Math.max(c, curMaxC);
    }

    static void initData(){
        curMinR = 0;
        curMinC = 0;
        curMaxR = 0;
        curMaxC = 0;
        r = 0;
        c = 0;
        d = 2;
    }

    static void move(){
        r += dir[d][R];
        c += dir[d][C];
        updateMinMax();
    }
    
    static void solution(char[] ords){
        for (char ord : ords){
            switch (ord) {
                case 'R':
                    d = (d + 3) % 4;
                    break;
                case 'L':
                    d = (d + 1) % 4;
                    break;
                case 'F':
                    move();
                    break;
                case 'B':
                    d = (d + 2) % 4;
                    move();
                    d = (d + 2) % 4;
                    break;
            }
        }
    }

    static int getSquareSize(){
        return (curMaxR - curMinR) * (curMaxC - curMinC);
    }

    public static void main(String[] args) throws IOException{
        int T;
        T = Integer.parseInt(br.readLine());
        
        while(T-- > 0){
            initData();
            solution(br.readLine().toCharArray());
            sb.append(getSquareSize() + "\n");
        }
        System.out.println(sb);
    }
}