import java.io.*;

public class boj16719 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static String opening;
    static int[] strOrd;
    static int curOrd;

    private static void inputData() throws IOException{
        opening = br.readLine();
    }

    private static void initData(){
        strOrd = new int[opening.length()];
        curOrd = 0;
    }

    private static void printData() throws IOException{
        for(int leng = 1; leng <= opening.length(); ++leng){
            for(int idx = 0; idx < opening.length(); ++idx){
                if(strOrd[idx] < leng){
                    sb.append(opening.charAt(idx));
                }
            }
            sb.append("\n");
        }
        System.out.print(sb);
        br.close();
    }

    private static int findFastestIdx(int start, int end){
        char a = 'Z';
        int targetIdx = start;
        for(int idx = start; idx < end; idx++){
            char cur = opening.charAt(idx);
            if (cur < a){
                a = cur;
                targetIdx = idx;
            }
        }
        return targetIdx;
    }

    static void solution(int start, int end){
        if (end <= start)
            return;
        
        int idx = findFastestIdx(start, end);

        strOrd[idx] = curOrd++;
        if (curOrd > opening.length())
            return;
        solution(idx + 1, end);
        solution(start, idx);
    }

    public static void main(String[] args) throws IOException{
        inputData();
        initData();
        solution(0, opening.length());
        printData();
    }
}
