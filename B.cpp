#include<bits/stdc++.h>
using namespace std;



void solve()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    map<int, int> tmp;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        tmp[a[i]]++;
    }
    
    vector<pair<int, int>> cnt;
    for(auto [ai, c]: tmp){
        cnt.emplace_back(c, ai);
    }

    sort(cnt.begin(), cnt.end());
    
    reverse(cnt.begin(), cnt.end());

    while(true){
        if(cnt.back().first <= k and cnt.size() > 1){
            k -= cnt.back().first;
            cnt.pop_back();
        }
        else
            break;
    }

    cout << cnt.size() << "\n";
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