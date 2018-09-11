#include <bits/stdc++.h>


using namespace std;


const int N = (int) (2 * 1e5);
const int MAX_COST = (int) (1e4);
int n;
int cost[N + 1];
int nxt[N + 1];
int mark[N + 1];
bool traced[N + 1];


void dfs(int u) {
    if (mark[u] > 1) return;
    mark[u]++;
    dfs(nxt[u]);
    mark[u]++;
}


void traceCycle(int u, vector<int> &cycle) {
    if (traced[u]) return;
    cycle.push_back(u);
    traced[u] = true;
    traceCycle(nxt[u], cycle);
}


void solve() {
    int n;
    cin >> n;
    for (int u = 1; u <= n; u++) {
        cin >> cost[u];
    }
    for (int u = 1; u <= n; u++) {
        cin >> nxt[u];
    }

    fill(mark, mark + n + 1, 0);
    for (int u = 1; u <= n; u++) {
        dfs(u);
    }

    fill(traced, traced + n + 1, false);
    int res = 0;

    for (int u = 1; u <= n; u++) {
        if (mark[u] == 4 && !traced[u]) {
            vector<int> cycle;
            traceCycle(u, cycle);
            int minCost = MAX_COST + 1;
            for (int &v : cycle) {
                minCost = min(minCost, cost[v]);
            }
            res += minCost;
        }
    }

    cout << res << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
    solve();
    return 0;
}
