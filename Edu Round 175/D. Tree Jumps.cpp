#include<bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, MOD = 998244353;

int p[N], dist[N], level[N], dp[N];

bool comp(int x, int y) {
    return dist[x] < dist[y];
}

int add(int x, int y) {

    x += y;

    while(x >= MOD) x -= MOD;

    if(x < 0) x += MOD;

    return x;
}

int main() {

    int t;
    cin >> t;

    for(int cs = 0; cs < t; cs++) {

        int n;
        cin >> n;

        vector<int> v(1, 1);

        for(int i = 2; i <= n; i++) {

            cin >> p[i];
            
            dist[i] = dist[p[i]] + 1;

            v.push_back(i);
        }

        sort(v.begin(), v.end(), comp);

        dp[1] = 1, level[dist[1]] = 1;

        for(int i = 1; i < n; i++) {

            int node = v[i];

            dp[node] = add(dp[node] , level[dist[node] - 1]);
            dp[node] = add(dp[node], p[node] == 1 ? 0 : -dp[p[node]]);

            level[dist[node]] = add(level[dist[node]], dp[node]);
        }

        int res = 0;

        for(int i = 1; i <= n; i++) {
            res = add(res, dp[i]);
        }

        cout << res << endl;


        for(int i = 0; i <= n; i++) {
            dist[i] = level[i] = dp[i] = 0;
        }

    }

    return 0;
}
