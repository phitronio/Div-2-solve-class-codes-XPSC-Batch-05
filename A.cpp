#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    cout << max(n, m) + 1 << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--)
        solve();
}