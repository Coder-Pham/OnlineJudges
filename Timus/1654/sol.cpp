#include <bits/stdc++.h>


using namespace std;


const int N = 200000;
char s[N + 1];
int n;
int px[N + 1];
int nx[N + 1];


void removePair(int x) {
    int y = nx[x];
    nx[px[x]] = nx[y];
    px[nx[y]] = px[x];
}


void solve() {
    s[0] = ' ';
    scanf("%s", s + 1);
    
    int n = strlen(s) - 1;

    for (int i = 0; i <= n; i++) {
        px[i] = i - 1;
        nx[i] = i + 1;
    }

    int x = 1;

    while (x <= n) {
        if (s[x] == s[nx[x]]) {
            removePair(x);
            x = (px[x] != 0) ? (px[x]) : (nx[nx[x]]);
        }
        else {
            x = nx[x];
        }
    }

    x = 0;

    string res = "";
    while (nx[x] <= n) {
        res += s[nx[x]];
        x = nx[x];
    }

    printf("%s\n", res.c_str());
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
    solve();
    return 0;
}
