import java.util.*;
import java.io.*;

public class boj1491 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int n;
    static int m;

    static int curRow, curCol;
    static int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    static int[][] board;

    private static void initData(){
        board = new int[n][m];
    }

    private static void inputData() throws IOException{
        st = new StringTokenizer(br.readLine(), " ");
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
    }

    private static void printAns() throws IOException {
        System.out.println(sb);
        br.close();
    }

    private static void printBoard(){
        sb.append("\n");
        for(int r = n - 1; r >= 0; r--){
            for(int c = 0; c < m; c++){
                System.out.printf("%2d ", board[r][c]);
                // sb.append(Integer.toString(board[r][c])+" ");
            }
            System.out.println();
        }
    }

    private static boolean checkBoundary(int r, int c){
        if(r < 0 || r >= n || c < 0 || c >= m){
            return false;
        }
        return true;
    }

    private static int getNextDirIdx(int cr, int cc, int cd){
        int nd, nr, nc;

        for(int idx = 0; idx < 4; ++idx){
            nd = (cd + idx) % 4;
            nr = cr + dir[nd][0];
            nc = cc + dir[nd][1];
            if (checkBoundary(nr, nc) == false) continue;
            if (board[nr][nc] != 0) continue;

            return nd;
        }
        return -1;
    }

    private static void solution(){
        int dirIdx = 0;
        curRow = 0;
        curCol = 0;
        for(int cnt = 0; cnt < n * m; cnt++){
            board[curRow][curCol] = cnt + 1;
            // System.out.printf("\ncurRow %d curCol %d \n\n", curRow, curCol);
            // printBoard();
            
            dirIdx = getNextDirIdx(curRow, curCol, dirIdx);
            
            if (dirIdx == -1){
                sb.append(curCol).append(" ").append(curRow);
                return;
            }
            
            curRow += dir[dirIdx][0];
            curCol += dir[dirIdx][1];
        }
    }

    public static void main(String args[]) throws IOException{
        inputData();
        initData();
        solution();
        printAns();
    }
}