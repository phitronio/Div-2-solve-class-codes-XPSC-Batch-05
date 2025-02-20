#include<bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    for(int cs = 0; cs < t; cs++) {

        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);

        string res = "YES";

        for(int i = 0; i < n; i += 2) {

            if(a[i] != a[i + 1]) {
                res = "NO";
                break;
            }

            if(i + 3 < n) {

                a[i + 2] = max(a[i], a[i + 2]);
                a[i + 3] = max(a[i], a[i + 3]);
                
                if(a[i + 2] == a[i]) a[i + 2]++;
                if(a[i + 3] == a[i]) a[i + 3]++;
            }

        }

        cout << res << endl;
    }

    return 0;
}
