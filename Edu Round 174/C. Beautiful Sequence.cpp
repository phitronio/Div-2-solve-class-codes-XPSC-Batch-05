    #include<bits/stdc++.h>

    using namespace std;

    const int MOD = 998244353;

    int add(int x, int y) {

        x += y;

        while(x > MOD) x -= MOD;

        if(x < 0) x += MOD;

        return x;
    }


    int main() {

        int t;
        cin >> t;

        for(int cs = 0; cs < t; cs++) {

            int n;
            cin >> n;


            vector<int> dp(4, 0);

            for(int i = 0; i < n; i++) {
                int x;
                cin >> x;

                if(x == 1) dp[1] = add(dp[1], 1);
                else if(x == 2) dp[2] = add(dp[2], add(dp[1], dp[2]));
                else dp[3] = add(dp[3], dp[2]);
            }

            cout << dp[3] << endl;

        }

        return 0;
    }
