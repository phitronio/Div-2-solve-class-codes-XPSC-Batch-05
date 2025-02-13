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
const int N = 1e3 + 5;

string adj[N];
void solve(int csno)
{
   int n;
   cin >> n;
   for (int i = 0; i < n; i++)
      cin >> adj[i];

   vector<int> perm(n);
   for (int i = 1; i <= n; i++) {
      int pos = 0;
      for (int j = 0; j < i - 1; j++)
         pos += (adj[i - 1][j] - '0');

      for (int j = i; j < n; j++)
         pos += !(adj[i - 1][j] - '0');

      dbg1(pos);

      perm[pos] = i;
   }

   for (int v : perm)
      cout << v << " ";
   cout << edl;
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
