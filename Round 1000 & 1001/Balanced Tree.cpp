#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt")
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define edl '\n'
#ifdef LOCAL
#include "../cp-template/Basic/debug.h"
#else
#define dbg1(args...)
#define dbg2(x)
#define stop
#endif
typedef long long LL;
typedef unsigned long long uLL;
// typedef __int128_t LLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
const int INF = 1e9;
const LL MOD = 998244353;
const int N = 2e5 + 5;

vector<int> g[N];
int a[N], l[N], r[N];
LL ans;
void dfs(int u, int p)
{
   a[u] = l[u];

   for (int v : g[u]) {
      if (v == p) continue;

      dfs(v, u);
      a[u] = max(a[u], a[v]);
   }

   a[u] = min(r[u], a[u]);

   // v = u, u = fu
   for (int v : g[u]) {
      if (v == p) continue;
      ans += max(a[v] - a[u], 0);
   }


   // cout << u << " " << ans << endl;
}
void solve(int csno)
{
   int n;
   cin >> n;
   for (int i = 1; i <= n; i++)
      cin >> l[i] >> r[i];

   for (int i = 1; i <= n; i++)
      g[i].clear();

   for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }

   ans = 0;
   dfs(1, 0);

   // for(int i = 1; i <= n; i++)
   //     cout << a[i] << " ";
   // cout << endl;

   ans += a[1];

   cout << ans << edl;
}
signed main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int T = 1;
   cin >> T;
   for (int csno = 1; csno <= T; csno++)
      solve(csno);
}
