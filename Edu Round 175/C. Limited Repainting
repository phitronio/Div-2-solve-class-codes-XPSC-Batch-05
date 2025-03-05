#include<bits/stdc++.h>

using namespace std;

int a[300000 + 5];

int fun(string str, int penalty) {

    string s = "";

    for(int i = 0; i < str.size(); i++) {

        if(a[i] > penalty) s += str[i];
    }

    int seg = s[0] == 'B' ? 1 : 0;

    for(int i = 1; i < s.size(); i++) {

        if(s[i] == 'B' && s[i - 1] == 'R')
            seg++;
    }


    return seg;
}


int main() {

    int t;
    cin >> t;

    for(int cs = 0; cs < t; cs++) {

        long long n, k;
        cin >> n >> k;

        string str;
        cin >> str;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int lo = 0, hi = 1e9, res;

        while(lo <= hi) {

            int mid = (lo + hi) / 2;

            int seg = fun(str, mid);

            if(seg <= k) {

                res = mid;

                hi = mid - 1;
            }
            else {

                lo = mid + 1;
            }
        }

        cout << res << endl;

    }

    return 0;
}
