#include<bits/stdc++.h>

using namespace std;

int query(int i, int j) {

    cout << "? " << i << " " << j << endl;

    int ret;
    cin >> ret;

    return ret;
}

void printA() {
    cout << "! A" << endl;
}

void printB() {
    cout << "! B" << endl;
}


int main() {

    int t;
    cin >> t;

    for(int cs = 0; cs < t; cs++) {

        int n;
        cin >> n;


        int x[n + 1], freq[n + 1];
        memset(freq, 0, sizeof(freq));

        for(int i = 1; i <= n; i++) {

            cin >> x[i];
            freq[x[i]] = 1;

        }

        int missing = -1;

        for(int i = 1; i <= n; i++) {
            if(freq[i] == 0) {
                missing = i;
                break;
            }
        }

        if(missing != -1) {
            int res = query(missing, missing == 1 ? 2 : 1);

            if(res == 0) {
                printA();
            }
            else {
                printB();
            }
        }
        else {
            int idx_1, idx_n;

            for(int i = 1; i <= n; i++) {
                if(x[i] == 1) idx_1 = i;
                if(x[i] == n) idx_n = i;
            }

            int res1 = query(idx_1, idx_n);
            int res2 = query(idx_n, idx_1);

            if(min(res1, res2) >= n - 1) {
                printB();
            }
            else{
                printA();
            }
        }
    }

    return 0;
}
