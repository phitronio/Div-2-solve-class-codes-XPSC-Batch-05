    #include<bits/stdc++.h>

    using namespace std;



    int main() {

        int t;
        cin >> t;

        for(int cs = 0; cs < t; cs++) {

            int n;
            cin >> n;

            vector<long long> a(n + 2), pre_sum(n + 2, 0), suf_sum(n + 2, 0);

            for(int i = 1; i <= n; i++) {

                cin >> a[i];

                pre_sum[i] = pre_sum[i - 1];

                if(a[i] > 0) pre_sum[i] += a[i];
            }

            for(int i = n; i >= 1; i--) {

                suf_sum[i] = suf_sum[i + 1];

                if(a[i] < 0) suf_sum[i] += abs(a[i]);
            }

            long long res = 0;

            for(int i = 1; i <= n; i++) {

                long long cur = pre_sum[i] + suf_sum[i];

                res = max(res, cur);
            }

            cout << res << endl;
        }

        return 0;
    }
