#include<bits/stdc++.h>

using namespace std;



int main() {

    int t;
    cin >> t;

    for(int cs = 0; cs < t; cs++) {

        int n;
        cin >> n;

        vector<int> a(n), fr(n + 1, 0);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            fr[a[i]]++;
        }

        int res = 0, cnt = 0, l = 0, r = 0;

        for(int i = 0; i < n; i++) {

            if(fr[a[i]] == 1) cnt++;
            else cnt = 0;

            if(cnt > res) {
                res = cnt;

                r = i + 1;
                l = r - cnt + 1;
            }
        }

        if(res == 0) cout << 0 << endl;
        else cout << l << ' ' << r << endl;
    }

    return 0;
}
