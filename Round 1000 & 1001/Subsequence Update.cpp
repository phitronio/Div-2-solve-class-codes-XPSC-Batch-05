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
   int n, l, r;
   cin >> n >> l >> r;
   vector<int> a(n);

   for (int& v : a)
      cin >> v;

   int m = r - l + 1;
   vector<int> pref;
   for (int i = 0; i < r; i++)
      pref.push_back(a[i]);

   sort(pref.begin(), pref.end());

   vector<int> suff;
   for (int i = l - 1; i < n; i++)
      suff.push_back(a[i]);

   sort(suff.begin(), suff.end());

   LL pref_sum = 0, suff_sum = 0;

   for (int i = 0; i < m; i++)
      pref_sum += pref[i];

   for (int i = 0; i < m; i++)
      suff_sum += suff[i];

   cout << min(pref_sum, suff_sum) << edl;
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
