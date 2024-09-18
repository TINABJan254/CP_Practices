#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
const ll INF = LLONG_MAX;

struct Point {
    int x, y;
};

ll distanceSquared(const Point &a, const Point &b) {
    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Point> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].x >> b[i].y;
    }

    vector<vector<ll>> dpA(n, vector<ll>(m + 1, INF));
    vector<vector<ll>> dpB(m + 1, vector<ll>(n, INF));

    dpA[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i + 1 < n) {
                dpA[i + 1][j] = min(dpA[i + 1][j], dpA[i][j] + distanceSquared(a[i], a[i + 1]));
            }
            if (j < m) {
                dpB[j + 1][i] = min(dpB[j + 1][i], dpA[i][j] + distanceSquared(a[i], b[j]));
            }
        }
    }

    for (int j = 0; j <= m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (j < m) {
                dpB[j + 1][i] = min(dpB[j + 1][i], dpB[j][i] + distanceSquared(b[j], b[j + 1]));
            }
            if (i + 1 < n) {
                dpA[i + 1][j + 1] = min(dpA[i + 1][j + 1], dpB[j][i] + distanceSquared(b[j], a[i + 1]));
            }
        }
    }

    ll result = INF;
    for (int j = 0; j <= m; ++j) {
        result = min(result, dpA[n - 1][j]);
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}

