import java.io.*;
import java.util.*;

// 23:15 ~
public class boj16926 {
    static final InputStreamReader isr = new InputStreamReader(System.in);
    static final BufferedReader br = new BufferedReader(isr);

    static StringTokenizer st;
    
    static final int[][] dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    static final int mx_nm = 300;

    static int n, m, rotate;
    static int[][] board = new int[mx_nm][mx_nm];
    static int[][] ansBoard = new int[mx_nm][mx_nm];
    static int[] memo = new int[4 * mx_nm];

    static int memoWp;
    static int memoRp;

    static int curStartRow;
    static int curStartCol;

    static int cellCnt;
    static int modR;

    static int curMinR;
    static int curMinC;
    static int curMaxR;
    static int curMaxC;
    
    static void inputData() throws IOException{
        st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        rotate = Integer.parseInt(st.nextToken());
        
        for(int r = 0; r < n; ++r){
            st = new StringTokenizer(br.readLine(), " ");
            for(int c = 0; c < m; ++c){
                board[r][c] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static void printBoard(){
        System.out.println("printBoard=========================");
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                System.out.printf("%2d ", board[r][c]);
            }
            System.out.println();
        }
        System.out.println("===================================");
    }

    static void printAnsBoard(){
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                System.out.printf("%d ", ansBoard[r][c]);
            }
            System.out.println();
        }
    }
    
    static void printAns() throws IOException{
        printAnsBoard();
        br.close();
    }

    static void initMemo(){
        memoWp = 0;
        memoRp = 0;
    }

    static void updateBoundaries(int ord){
        curMinR = ord;
        curMaxR = n - 1 - ord;
        curMinC = ord;
        curMaxC = m - 1 - ord;
    }

    static boolean isInBoundary(int r, int c){
        if (r < curMinR || r > curMaxR) return false;
        if (c < curMinC || c > curMaxC) return false;
        return true;
    }

    static void getMemo(int r, int c, int dIdx, int left){
        if(left <= 0) return;
        
        memo[memoWp++] = board[r][c];

        int candNextR = r + dirs[dIdx][0];
        int candNextC = c + dirs[dIdx][1];

        if(isInBoundary(candNextR, candNextC) == false){
            dIdx = (dIdx + 1) % 4;
        }

        getMemo(r + dirs[dIdx][0], c + dirs[dIdx][1], dIdx, left - 1);
    }
    
    static void printMemo(){
        System.out.println("printMemo=========================");
        System.out.printf("memoWp %d\n", memoWp);
        for(int r = 0; r < memoWp; ++r){
            System.out.printf("%2d ", memo[r]);
        }
        System.out.println("\n===================================");
    }

    // static void getStartPoint(int r, int c, int dIdx, int left){
    //     if (left <= 0) return;
    // }

    static void move(int r, int c, int curIdx, int dIdx, int stride){
        if (curIdx == cellCnt)  return;

        ansBoard[r][c] = memo[(curIdx - stride + cellCnt) % cellCnt];

        int candNextR = r + dirs[dIdx][0];
        int candNextC = c + dirs[dIdx][1];

        if(isInBoundary(candNextR, candNextC) == false){
            dIdx = (dIdx + 1) % 4;
        }

        move(r + dirs[dIdx][0], c + dirs[dIdx][1], curIdx + 1, dIdx, stride);
    }

    static void solution(){
        int cnt = Math.min(n, m) / 2;
        for(int peak = 0; peak < cnt; ++peak){

            cellCnt = 2 * (n - peak * 2) + 2 * (m - peak * 2) - 4;
            modR = rotate % cellCnt;
            updateBoundaries(peak);

            initMemo();
            getMemo(peak, peak, 0, cellCnt);
            // printMemo();
            
            // getStartPoint(peak, peak, modR);
            move(peak, peak, 0,  0, modR);
        }
    }

    public static void main(String[] args) throws IOException{
        inputData();
        // printBoard();
        solution();
        printAns();
    }
}
