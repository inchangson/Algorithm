import java.io.*;
import java.util.*;

public class boj11559 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    final static int ROW = 12;
    final static int COL = 6;
    final static char EMPTY = '.';
    final static int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    static char[][] board;
    static boolean[][] visited;

    static int ans;


    private static void initData(){
        board = new char[ROW][COL];
        visited = new boolean[ROW][COL];
    }

    private static void inputData() throws IOException{
        for(int r = 0; r < ROW; ++r){
            String str = br.readLine();
            char[] tmp = str.toCharArray();
            board[r] = tmp;
        }
    }

    private static void printAns() throws IOException {
        System.out.println(ans);
        br.close();
    }

    private static void printBoard(){
        System.out.printf("\nprintBoard\n");
        for(int r = 0; r < ROW; ++r){
            for(int c = 0; c < COL; ++c){
                System.out.printf("%2c ", board[r][c]);
            }
            System.out.println();
        }
    }
    
    static void puyo(int r, int c){
        visited[r][c] = true;
        char tmp = board[r][c];
        for(int idx = 0; idx < 4; ++idx){
            int nr = r + dir[idx][0];
            int nc = c + dir[idx][1];

            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL) continue;
            if (visited[nr][nc] == true)    continue;
            if (board[nr][nc] != tmp)   continue;
            
            visited[nr][nc] = true;
            puyo(nr, nc);
        }
        board[r][c] = EMPTY;
    }

    private static int getConnectCount(int r, int c){
        visited[r][c] = true;
        int ret = 1;

        for(int idx = 0; idx < 4; ++idx){
            int nr = r + dir[idx][0];
            int nc = c + dir[idx][1];

            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL) continue;
            if (visited[nr][nc] == true)    continue;
            if (board[nr][nc] != board[r][c])   continue;
            
            visited[nr][nc] = true;
            ret += getConnectCount(nr, nc);
        }

        return ret;
    }


    private static void initVisited(){
        for(int r = 0; r < ROW; ++r){
            for (int c = 0; c < COL; ++c){
                visited[r][c] = false;
            }
        }
    }

    private static void applyGravity(){
        for(int c = 0; c < COL; ++c){
            int wIdx = ROW - 1;
            for(int r = ROW - 1; r >= 0; --r){
                int idx;
                for (idx = 0; r - idx >= 0; ++idx){
                    if(board[r - idx][c] != EMPTY){
                        char tmp = board[r-idx][c];
                        board[r-idx][c] = EMPTY;
                        board[wIdx--][c] = tmp;
                        r -= idx;
                        break;
                    }
                }
            }
        }
    }

    private static int solution(){
        int chain;
        boolean isEnd = false;
        int initRow = 0;

        for(chain = 0; isEnd == false
        ;
         ++chain){
            isEnd = true;
            Queue<int[]> targets = new LinkedList<>();

            // 중력 적용
            applyGravity();

            // 대상 찾기
            for(int r = initRow; r < ROW; ++r){
                for(int c = 0; c < COL; ++c){
                    // 최적화 -> 시작하는 칸 번호 기록해두기
                    if(board[r][c] == EMPTY)    continue;
                    if(visited[r][c] == true)   continue;
                    if(getConnectCount(r, c) < 4) continue;
                    // initRow = Math.min(initRow, r);
                    isEnd = false;
                    targets.add(new int[]{r, c});
                }
            }
            initVisited();

            // 푸요푸요
            for(int[] target : targets){
                puyo(target[0], target[1]);
            }
            initVisited();

            
        }

        return chain - 1;
    }

    public static void main(String args[]) throws IOException{
        initData();
        inputData();
        ans = solution();
        printAns();
    }
}