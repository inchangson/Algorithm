import java.io.*;
import java.util.*;

public class boj11021 {
	public static void main(String args[]) throws IOException {
 
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int a = Integer.parseInt(br.readLine());
 
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
        
		for (int i = 1; i <= a; i++) {
			st = new StringTokenizer(br.readLine()," ");
			sb.append("Case #").append(i).append(": ")
			.append(Integer.parseInt(st.nextToken())
			+Integer.parseInt(st.nextToken())).append('\n');
		}
		br.close();
		System.out.println(sb);
	}
 
}