import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.BufferedOutputStream;
import java.lang.Runnable;
import java.util.StringTokenizer;


public class Main implements Runnable {
    class UnionFindSet {
        int n;
        int[] parent;
        int[] rank;

        UnionFindSet(int n_) {
            n = n_;
            parent = new int[n];
            rank = new int[n];

            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int u) {
            if (parent[u] == u) return u;
            return find(parent[u]);
        }

        void union(int u, int v) {
            int root_u = find(u);
            int root_v = find(v);
            if (root_u  == root_v) return;
            if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            }
            else if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            }
            else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }

        int numComponents() {
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (parent[i] == i) {
                    res++;
                }
            }
            return res;
        }
    }

    public void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int q = in.nextInt();
        UnionFindSet ufs = new UnionFindSet(n + m); 

        for (int i = 0; i < q; i++) {
            int r = in.nextInt() - 1;
            int c = in.nextInt() - 1;
            ufs.union(r, n + c);
        }
        
        out.println(ufs.numComponents() - 1);
    }


/*___________________________________________________________________________*/

    public static void main (String[] args) {
        new Main().run();
    }

    public void run() {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer tokenizer = null;
            InputReader in = new InputReader(reader, tokenizer);
            PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
            solve(in, out);
            out.close();
        }
        catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    class InputReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;
        public int lineNumber = -1;

        public InputReader(BufferedReader reader, StringTokenizer tokenizer) {
            this.reader = reader;
            this.tokenizer = tokenizer;
        }

        public String next() {
            while ((tokenizer == null) || (!tokenizer.hasMoreTokens())) {
                try {
                    String line = reader.readLine();
                    if (line == null) return "EndOfStream";
                    lineNumber++;
                    tokenizer = new StringTokenizer(line);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public char nextChar() {
            return next().charAt(0);
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }
    }
}