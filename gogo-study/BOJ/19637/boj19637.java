import java.io.*;
import java.util.*;

public class boj19637 {
    static InputStreamReader isr = new InputStreamReader(System.in);
    static BufferedReader br = new BufferedReader(isr);
    static StringBuilder sb = new StringBuilder();

    static int n;
    static int m;

    static Grade[] grades;
    static int[] warriors;
    
    static void inputData() throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        grades = new Grade[n];
        warriors = new int[m];

        for(int idx = 0; idx < n; ++idx){
            st = new StringTokenizer(br.readLine());
            grades[idx] = new Grade(st.nextToken(), Integer.parseInt(st.nextToken()));
        }
        for(int idx = 0; idx < m; ++idx){
            warriors[idx] = Integer.parseInt(br.readLine());
        }
    }

    static void printData() {
        sb.append("printData=========================\n");
        sb.append(String.format("n %d m %d\n", n, m));
        for (Grade g : grades){
            sb.append(g.name + " ").append(String.valueOf(g.value)).append("\n");
        }
        sb.append("==================================\n");

        for(int v : warriors){
            sb.append(String.valueOf(v)).append(" ");
        }
        sb.append("\nEND===============================\n");
    }

    static void printAns() throws IOException{
        System.out.println(sb);
        // isr.close();
        br.close();
    }

    static String getWarriorGrade(int strength){
        int left = 0;
        int right = n - 1;

        int mid = (left + right) / 2;;
        int curVal;
        
        while (left <= right){
            mid = (left + right) / 2;
            curVal = grades[mid].value;

            if (strength > curVal){
                left = mid + 1;
            } else if (strength <= curVal){
                right = mid;
            }
        }

        return grades[mid].name;
    }

    static void solution(){
        for (int warrior : warriors){
            sb.append(getWarriorGrade(warrior) + "\n");
        }
    }

    public static void main(String[] args) throws IOException{
        inputData();
        // printData();
        solution();
        printAns();
    }
}

class Grade{
    public String name;
    public int value;
    public Grade(String n, int v){
        this.name = n;
        this.value = v;
    }
}