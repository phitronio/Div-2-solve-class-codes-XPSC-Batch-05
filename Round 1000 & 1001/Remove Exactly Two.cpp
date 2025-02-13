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
void solve(int csno)
{
   int n;
   cin >> n;
   vector<int> d(n, 0);

   for (int i = 0; i < n; i++)
      g[i].clear();

   for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      d[--u]++, d[--v]++;
      g[u].push_back(v);
      g[v].push_back(u);
   }

   multiset<int> md;
   for (int i = 0; i < n; i++)
      md.insert(d[i]);

   dbg2(d);

   int ans = 1;
   for (int u = 0; u < n; u++) {
      // cout << u << endl;
      md.erase(md.find(d[u]));
      for (int v : g[u])
         md.erase(md.find(d[v]));

      if (!md.empty())
         ans = max(ans, d[u] + *md.rbegin());

      md.insert(d[u]);
      for (int v : g[u])
         md.insert(d[v]);
   }

   //du + dv - 2

   sort(d.begin(), d.end(), greater<int>());

   ans = max(ans - 1, d[0] + d[1] - 2);

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
