#include<bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    for(int cs = 0; cs < t; cs++) {

        int n;
        cin >> n;

        long long cur = 0, res = 20;

        for(int i = 0; i < 10; i++) {

            long long m = n;

            cur *= 10;
            cur += 9;

            long long mv = 0;

            for(int j = 0; j < 10; j++) {

                long long temp = m, flag = 0;
                
                while(temp) {
                    int d = temp % 10;
                    if(d == 7) {
                        flag = 1;
                        break;
                    }
                    temp /= 10;
                }

                if(flag) res = min(res, mv);

                m += cur;
                mv++;

            }
        }

        cout << res << endl;

    }

    return 0;
}
