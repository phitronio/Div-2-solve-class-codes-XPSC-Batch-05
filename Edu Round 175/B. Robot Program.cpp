#include<bits/stdc++.h>

using namespace std;


int check(string str, long long x) {

    int count = 0;

    for(int i = 0; i < str.size(); i++) {

        if(str[i] == 'L') x -= 1;
        else x += 1;

        count++;

        if(x == 0) 
            return count;   
    }

    return -1;
}

int main() {

    int t;
    cin >> t;

    for(int cs = 0; cs < t; cs++) {

        long long n, x, k;
        cin >> n >> x >> k;

        string str;
        cin >> str;

        int ret = check(str, x);

        if(ret == -1) {
            cout << 0 << endl;
        }
        else {

            k -= ret;
            int ret1 = check(str, 0);

            if(ret1 == -1 || ret1 > k) cout << 1 << endl;
            else cout << 1 + (long long)(k / ret1) << endl;

        }

    }

    return 0;
}
