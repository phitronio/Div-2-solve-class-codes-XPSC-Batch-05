    #include<bits/stdc++.h>

    using namespace std;



    int main() {

        int t;
        cin >> t;

        for(int cs = 0; cs < t; cs++) {

            int n, q;
            cin >> n >> q;

            vector<int> w(n + 1), cu_xor(n + 1, 0);

            for(int i = 1; i <= n; i++) {

                cin >> w[i];

                cu_xor[i] = cu_xor[i - 1];

                cu_xor[i] ^= w[i];
            }


            vector<vector<int>> last(n + 1, vector<int> (32, 0));

            for(int i = 1; i <= n; i++) 
            {
                last[i] = last[i - 1];

                int msb = __lg(w[i]);

                last[i][msb] = i;

                for(int j = 30; j >= 0; j--) 
                {
                    last[i][j] = max(last[i][j], last[i][j + 1]);
                }
            }


            while(q--) {
                int x;
                cin >> x;

                int cur = n;

                while(cur >= 1 and x > 0) {

                    int msb = __lg(x);

                    int idx = last[cur][msb];

                    x ^= (cu_xor[cur] ^ cu_xor[idx]);

                    if(w[idx] > x or idx == 0) {
                        cur = idx;
                        break;
                    }

                    x ^= w[idx];

                    cur = idx - 1;
                    
                }

                cout << n - cur << " ";
            }
            cout << endl;

        }

        return 0;
    }
