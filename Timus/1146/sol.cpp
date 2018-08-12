#include <bits/stdc++.h>


using namespace std;


#ifdef LOCAL
#define debug(X) { cerr << #X << " = " << (X) << endl; }
#else
#define debug(X) 27
#endif // LOCAL


template<class T>
T maxm(initializer_list<T> list) {
    T res = - numeric_limits<T>::max();
    for (auto elem : list) { res = max(res, elem); }
    return res;
}

template<class T>
T minm(initializer_list<T> list) {
    T res = numeric_limits<T>::max();
    for (auto elem : list) { res = min(res, elem); }
    return res;
}


const int N = 100;
int n;
int a[N + 1][N + 1];
int dp[N + 1];
int sumRow[N + 1][N + 1];
int sumCol[N + 1][N + 1];


inline int sumRowSegment(int row, int startCol, int endCol) {
    return sumRow[row][endCol] - sumRow[row][startCol - 1];
}


inline int sumColSegment(int col, int startRow, int endRow) {
    return sumCol[col][endRow] - sumCol[col][startRow - 1];
}


void solve() {
    cin >> n;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            cin >> a[row][col];
        }
    }

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            sumRow[row][col] = sumRow[row][col - 1] + a[row][col];
        }
    }
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            sumCol[col][row] = sumCol[col][row - 1]  + a[row][col];
        }
    }

    int ans = -numeric_limits<int>::max();

    for (int startRow = 1; startRow <= n; startRow++) {
        for (int endRow = startRow; endRow <= n; endRow++) {
            dp[1] = sumColSegment(1, startRow, endRow);
            for (int col = 2; col <= n; col++) {
                int sumCol = sumColSegment(col, startRow, endRow);
                if (dp[col - 1] > 0) {
                    dp[col] = dp[col - 1] + sumCol;
                }
                else {
                    dp[col] = sumCol;
                }
            }
            for (int col = 1; col <= n; col++) {
                ans = max(ans, dp[col]);
            }
        }
    }

    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif // LOCAL
    cout << fixed << setprecision(10);
    solve();
    return 0;
}

