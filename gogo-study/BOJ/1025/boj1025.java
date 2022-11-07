import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class boj1025 {
    static InputStreamReader isr = new InputStreamReader(System.in);
    static BufferedReader br = new BufferedReader(isr);

    static int n;
    static int m;
    static int ans;

    static char[][] nums;

    static HashSet<String> targets;

    static void printData(){
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                System.out.printf("%2c", nums[r][c]);
            }
            System.out.println();
        }
    }

    static void inputData(){
        try{
            String[] nm = br.readLine().split(" ");
            n = Integer.parseInt(nm[0]);
            m = Integer.parseInt(nm[1]);

            nums = new char[n][m];
            for(int r =0; r < n; ++r){
                String inp = br.readLine();
                for(int c = 0; c < m; ++c){
                    nums[r][c] = inp.charAt(c);
                }
            }

        } catch(Exception e){
        }
        
    }

    static void initData(){
        targets = new HashSet<>();
        for (int src = 0; src * src < 1000000000; ++src) {
            // System.out.println(Integer.toString(src * src));
            targets.add(Integer.toString(src * src));
        }
    }

    static void updateAns(int cand){
        ans = Math.max(ans, cand);
    }

    static void checkMemoJaeGop(String num){

        String memo2 = String.valueOf(Integer.valueOf(num));

        if ( targets.contains(memo2)){
            updateAns(Integer.valueOf(memo2));
        }
    }

    static void makeNumber(String memo, int r, int c, int stepR, int stepC, boolean[][] visited){
        if (visited[r][c]){
            return;
        }
        
        r = (r + stepR) % n;
        c = (c + stepC) % m;

        visited[r][c] = true;

        memo += String.valueOf(nums[r][c]);
        // System.out.println(memo);
        checkMemoJaeGop(memo);
        makeNumber(memo, r, c, stepR, stepC, visited);
    }

    static void solution(){
        for(int r = 0; r < n; ++r){
            for (int c = 0; c < m; ++c){
                for(int stepR = 0; stepR < n; ++stepR){
                    for(int stepC = 0; stepC < m; ++stepC){
                        for (int leng = 0; leng < Math.max(n, m); ++leng){
                            boolean[][] visited = new boolean[n][m];
                            String cur = String.valueOf(nums[r][c]);
                            makeNumber(cur, r, c, stepR, stepC, visited);
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        inputData();
        initData();
        // printData();
        solution();
        System.out.println(ans);
    }
}

