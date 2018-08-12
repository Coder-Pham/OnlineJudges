#include <bits/stdc++.h>


using namespace std;


const int MAX = (int) (2 * 1e5 + 1);
int deg[MAX];


struct UnionFindSet {
    int parent[MAX];
    int depth[MAX];

    UnionFindSet() {
        for (int i = 0; i < MAX; i++) {
            parent[i] = i;
            depth[i] = 0;
        }
    }

    int find(int u) {
        while (parent[u] != u) {
            u = parent[u];
        }
        return u;
    }

    void merge(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u == root_v) {
            return;
        }
        if (depth[root_u] < depth[root_v]) {
            parent[root_u] = root_v;
        }
        else if (depth[root_u] > depth[root_v]) {
            parent[root_v] = root_u;
        }
        else {
            parent[root_u] = root_v;
            depth[root_v]++;
        }
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int nNodes, nEdges;
    cin >> nNodes >> nEdges;

    fill(deg, deg + nNodes + 1, 0);

    vector<pair<int, int> > edges;

    for (int i = 0; i < nEdges; i++) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        deg[u]++, deg[v]++;
    }

    UnionFindSet ufs;

    for (pair<int, int> edge : edges) {
        ufs.merge(edge.first, edge.second);
    }

    map<int, vector<int> > components;

    for (int u = 1; u <= nNodes; u++) {
        int root = ufs.find(u);
        if (components.find(root) == components.end()) {
            components.emplace(root, vector<int>());
        }
        components[root].push_back(u);
    }

    int ans = 0;

    for (auto& component : components) {
        vector<int> nodes = component.second;
        bool flag = true;
        for (int node : nodes) {
            if (deg[node] != 2) {
                flag = false;
                break;
            }
        }
        if (flag == true) ans++;
    }

    cout << ans << '\n';

    return 0;
}