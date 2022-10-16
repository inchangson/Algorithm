import java.io.*;
import java.util.*;

public class boj20291 {
    static InputStreamReader isr = new InputStreamReader(System.in);
    static BufferedReader br = new BufferedReader(isr);
    static StringBuilder sb = new StringBuilder();

    static HashMap<String, Integer> exHist;
    static List<String> extensions;

    static void solution() throws IOException{
        int fileNo = Integer.parseInt(br.readLine());
        String extension;
        exHist = new HashMap<>();
        while (fileNo-- > 0){
            extension = br.readLine().split("[.]")[1];
            if (exHist.containsKey(extension)){
                exHist.put(extension, exHist.get(extension) + 1);
            } else {
                exHist.put(extension, 1);
            }
        }
        extensions = new ArrayList<>(exHist.keySet());
		Collections.sort(extensions);

        for (String elem : extensions){
            sb.append(elem + " " + exHist.get(elem) + "\n");
        }
    }

    static void printAns(){
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException{
        solution();
        printAns();
    }
}
