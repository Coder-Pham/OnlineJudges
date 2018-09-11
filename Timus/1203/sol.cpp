#include <bits/stdc++.h>


using namespace std;


const int MAXTIME = 30000;


struct Report {
    int s;
    int e;

    Report(int s_, int e_) {
        s = s_; e = e_;
    }
};


int endTime[MAXTIME + 1];
vector<Report> reports;


void solve() {
    int n;
    cin >> n;
    fill(endTime, endTime + MAXTIME + 1, MAXTIME + 1);
    for (int i = 0; i < n; i++) {
        int ts, te;
        cin >> ts >> te;
        if (endTime[ts] > te) {
            endTime[ts] = te;
        }
    }
    for (int ts = 1; ts <= MAXTIME; ts++) {
        if (endTime[ts] < MAXTIME + 1) {
            reports.emplace_back(ts, endTime[ts]);
        }
    }
    sort(reports.begin(), reports.end(),
        [](const Report r1, const Report r2) {
            return r1.e < r2.e;
        });
    int res = 0;
    int curEnd = 0;
    for (Report report : reports) {
        if (report.s <= curEnd) continue;
        curEnd = report.e;
        res++;
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
