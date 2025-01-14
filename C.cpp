#include<bits/stdc++.h>
using namespace std;

using LL = long long;

void solve()
{
    LL l, r;
    cin >> l >> r;
    //11101110 = r
    //11101010 = l
    //11101010 = l & r
    //11111000
    //11101100 = a
    //11101011 = b
    //000000000000000000000100
    // 10000000000000000000000000
    //11101000
    // 2 ^ 7 - 2 ^ 3

    // 10000000 = 2 ^ 7
    // 00001000 = 2 ^ 3
    // 01111000
    // 01111111
    // 30
    LL diff_msb = 63 - __builtin_clzll(l ^ r);
    LL a = (((l & r) >> diff_msb) << diff_msb) + (1LL << diff_msb);
    LL b = a - 1;

    LL c;
    if(b > l)
        c = b - 1;
    else
        c = a + 1;
    
    cout << a << " " << b << " " << c << "\n";
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