import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj2470 {
    static InputStreamReader isr = new InputStreamReader(System.in);
    static BufferedReader br = new BufferedReader(isr);
    static StringBuilder sb = new StringBuilder();

    static final int INF = 2000000001;
    static int N;
    static ArrayList<Integer> liquids = new ArrayList<>();
    static Integer curMin = INF;
    static Integer ansA = 0;
    static Integer ansB = 0;

    static void inputData() throws IOException{
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i){
            liquids.add(Integer.parseInt(st.nextToken()));
        }
    }

    static void printData(){
        sb.append("\nstartPrintData=========================\n");
        for(Integer elem : liquids){
            sb.append(elem + " ");
        }
        sb.append("\nendPrintData=========================\n");
    }

    static void printAns()throws IOException {
        sb.append(ansA + " " + ansB);
        br.close();
        System.out.println(sb);
    }


    static void updateAns(int a, int b){
        if (Math.abs(a + b) < curMin){
            curMin = Math.abs(a + b);
            if( a < b){
                ansA = a;
                ansB = b;
            } else {
                ansA = b;
                ansB = a;
            }
        }
    }
    
    static int getSameOrBigger(int idx, int target){
        int left = idx + 1;
        int right = N - 1;
        int mid = (left + right) / 2;
        int ret = -1;
        while( left <= right ){
            mid = (left + right) / 2;
            if ( target == liquids.get(mid) ) {
                return target;
            }
            if ( target >= liquids.get(mid) ){
                left = mid + 1;
            } else {
                right = mid - 1;
                ret = liquids.get(mid);
            }
        }

        return ret;
    }

    static int getSameOrSmaller(int idx, int target){
        int left = idx + 1;
        int right = N - 1;
        int mid = (left + right) / 2;
        int ret = -1;
        while(left <= right){
            mid = (left + right) / 2;

            if ( target == liquids.get(mid) ) {
                return target;
            }
            if (target <= liquids.get(mid)){
                right = mid - 1;
            } else {
                left = mid + 1;
                ret = liquids.get(mid);
            }
        }

        return ret;
    }

    static void solution(){
        Collections.sort(liquids);

        int cand1, cand2;
        for (int cur = 0; cur < liquids.size() - 1; ++cur) {
            cand1 = getSameOrBigger(cur, -liquids.get(cur));
            cand2 = getSameOrSmaller(cur, -liquids.get(cur));
            // System.out.println(String.format("cur %d cand1 %d cand2 %d\n", liquids.get(cur), cand1, cand2));
            
            if (cand1 != -1)
                updateAns(liquids.get(cur), cand1);
            if (cand2 != -1)
                updateAns(liquids.get(cur), cand2);
        }
    }

    public static void main(String[] args) throws IOException{
        inputData();
        // printData();
        solution();
        // printData();
        printAns();
    }
}
