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

void solve(int csno)
{
   int n;
   cin >> n;
   vector<int> a(n);

   for (int& v : a)
      cin >> v;

   LL bad_even = 0;
   for (int lmid = 1; lmid <= 10; lmid++) {
      vector<int> b(n);
      for (int i = 0; i < n; i++)
         b[i] = (a[i] <= lmid) ? -1 : 1;

      map<int, int> cnt, nox;
      int pref = 0;
      cnt[0] = 1;
      nox[0] = 1;
      for (int i = 0; i < n; i++) {
         pref += b[i];

         if (a[i] == lmid)
            nox.clear();

         bad_even += cnt[pref] - nox[pref];
         nox[pref]++;
         cnt[pref]++;
      }
   }

   LL ans = 1LL * n * (n + 1) / 2 - bad_even;

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
