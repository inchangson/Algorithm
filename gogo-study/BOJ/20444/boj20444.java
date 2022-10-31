import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj20444 {
    static InputStreamReader isr = new InputStreamReader(System.in);
    static BufferedReader br = new BufferedReader(isr);

    static int n;
    static long k;
    static boolean ans;

    static void inputData() throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Long.parseLong(st.nextToken());
        // System.out.println(n + " " + k);
    }

    static void printAns(){
        if (ans){
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    static void closeProgram() throws IOException{
        br.close();
    }

    static boolean solution(){
        long l = 0;
        long r = n;

        long m;
        long curCnt;
        while ( l <= r ) {
            m = (l + r) / 2;
            curCnt = (m + 1) * (n - m + 1);

            if (curCnt == k){
                return true;
            } else if (curCnt < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException{
        inputData();
        ans = solution();
        printAns();
        closeProgram();
    }
}
