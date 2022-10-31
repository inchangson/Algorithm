import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj2412 {
    static InputStreamReader isr = new InputStreamReader(System.in);
    static BufferedReader br = new BufferedReader(isr);
    
    static int n;
    static int top;
    static int ans;

    static ArrayList<Node> nodes;
    static ArrayList<ArrayList<Integer>> graph;

    static boolean[] visited;

    static void inputData() throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        top = Integer.parseInt(st.nextToken());

        nodes = new ArrayList<>(n + 1);

        int x, y;
        nodes.add(new Node(0, 0));
        for(int i = 0; i < n; ++i){
            st = new StringTokenizer(br.readLine());
            
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());

            nodes.add(new Node(x, y));
        }
    }

    static void printData(){
        System.out.printf("n %d top %d\n", n, top);

        for (Node node : nodes){
            System.out.printf("x %d y %d\n", node.x, node.y);
        }

        for (int n1 = 0; n1 < graph.size(); ++n1){
            System.out.println("n1:" + n1 + " " + graph.get(n1));
        }
    }

    static void printAns() throws IOException{
        System.out.println(ans);
        br.close();
    }

    static void initGraph(){
        int nxt, dist;

        graph = new ArrayList<ArrayList<Integer>>();
        for (int cur = 0; cur < nodes.size(); ++cur){
            nxt = cur + 1;

            ArrayList<Integer> canGo = new ArrayList<Integer>();
            while(nxt < nodes.size()){
                // y dist check
                dist = nodes.get(nxt).y - nodes.get(cur).y;
                if (dist > 2){
                    break;
                }
                // x dist check
                dist = nodes.get(nxt).x - nodes.get(cur).x;
                dist = dist < 0 ? - dist : dist;

                if (dist <= 2){
                    canGo.add(nxt);
                }
                nxt++;
            }
            graph.add(canGo);
        }
        
        for (int n1 = 0; n1 < graph.size(); ++n1){
            for (int n2 : graph.get(n1)){
                if (!graph.get(n2).contains(n1)){
                    graph.get(n2).add(n1);
                }
            }
        }
    }

    static void sortGraph(){
        for (int n1 = 0; n1 < graph.size(); ++n1){
            final int pivot = n1;
            Collections.sort(graph.get(n1), new Comparator<Integer>() {
                int getDist(int i1, int i2){
                    int x = nodes.get(i1).x - nodes.get(i2).x;
                    int y = nodes.get(i1).y - nodes.get(i2).y;

                    x = x < 0 ? -x : x;
                    y = y < 0 ? -y : y;

                    return x + y;
                }

                @Override
                public int compare(Integer n2, Integer n3){
                    return getDist(pivot, n2) - getDist(pivot, n3);
                }
            });
        }
    }


    static void initData(){
        Collections.sort( nodes );
        visited = new boolean[n + 1];
        initGraph();
        sortGraph();
    }

    static int solution(){

        Queue<Integer[]> q = new LinkedList<>();

        q.offer(new Integer[] {0, 0});
        visited[0] = true;
        final int IDX = 0;
        final int DIST = 1;
        while(!q.isEmpty()){
            Integer[] cur = q.poll();

            // System.out.printf("cur idx %d dist %d\n", cur[IDX], cur[DIST]);

            if ( nodes.get(cur[IDX]).y == top) {
                return cur[DIST];
            }


            // System.out.println("nxtList " + graph.get(cur[IDX]));

            for(Integer nxt : graph.get(cur[IDX])){
                if (visited[nxt]){
                    continue;
                }

                visited[nxt] = true;
                q.offer(new Integer[] {nxt, cur[DIST] + 1});
            }

        }

        return -1;
    }

    public static void main(String[] args) throws IOException{
        inputData();
        initData();
        // printData();
        ans = solution();
        printAns();
    }
}

class Node implements Comparable{
    public int x;
    public int y;

    public Node(int x, int y){
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Object obj){
        Node node = (Node)obj; 
        if ( node.y == this.y){
            return (this.x - node.x);
        } else {
            return (this.y - node.y);
        }
    }
}
