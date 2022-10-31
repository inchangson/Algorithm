import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj6987 {
    static InputStreamReader isr = new InputStreamReader(System.in);
    static BufferedReader br = new BufferedReader(isr);
    static StringBuilder sb = new StringBuilder();

    static final int R = 6;
    static final int C = 3;

    static final int W = 0;
    static final int D = 1;
    static final int L = 2;

    static final int oppositeCnt = 5;

    static int[][] result;

    static void printRslt(int[][] rslt){
        sb.append("\n");
        sb.append("PRINT START===================\n");
        for(int r = 0; r < R; ++r){
            for(int c = 0; c < C; ++c){
                sb.append(String.format("%d ", rslt[r][c]));
            }
            sb.append("\n");
        }
        sb.append("PRINT END===================\n");
        sb.append("\n");
    }
    
    static int getOppositeKind(int k) {
        int ret = -1;
        switch (k) {
            case W : ret = L;
            case D : ret = D;
            case L : ret = W;
        }
        return ret;
    }

    static int isAllZero(int[][] result){
        for(int r = 0; r < R; ++r){
            for(int c = 0; c < C; ++c){
                if (result[r][c] != 0){
                    return 0;
                }
            }
        }
        return 1;
    }
    
    static int checkPossibility(int cur, int next){
        if (cur == R){
            return isAllZero(result);
        }

        if (next == R){
            return checkPossibility(cur + 1, cur + 2);
        }

        int ret = 0;
        //이번팀이랑 붙어서 이길지
        if ( result[cur][W] > 0 ) {
            if ( result[next][L] > 0 ) {

                result[next][L]--;
                result[cur][W]--;
                ret += checkPossibility(cur, next + 1);
                result[next][L]++;
                result[cur][W]++;

            }
        }

        //이번팀이랑 붙어서 비길지
        if ( result[cur][D] != 0 ) {
            if ( result[next][D] != 0 ) {
                
                result[next][D]--;
                result[cur][D]--;
                ret += checkPossibility(cur, next + 1);
                result[next][D]++;
                result[cur][D]++;
            }
        }

        //이번팀이랑 붙어서 질지
        if ( result[cur][L] != 0 ) {
            if ( result[next][W] != 0 ) {
                
                result[next][W]--;
                result[cur][L]--;
                ret += checkPossibility(cur, next + 1);
                result[next][W]++;
                result[cur][L]++;
            }
        }

        return ret;
    }

    static int solution(String userInput){
        result = new int[R][C];
        for(int idx = 0; idx < userInput.length(); idx += 2){
            int rIdx = idx / 2;
            result[rIdx / C][rIdx % C] = (userInput.charAt(idx) - '0');
        }
        return checkPossibility(0, 1);
    }

    public static void main(String[] args) throws IOException{
        for(int t = 0; t < 4; ++t){
            int ans = solution(br.readLine());
            if (ans > 0){
                ans = 1;
            } else {
                ans = 0;
            }
            sb.append(ans + " ");
        }
        System.out.println(sb);
    }
}
