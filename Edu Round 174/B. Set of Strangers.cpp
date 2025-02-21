    #include<bits/stdc++.h>

    using namespace std;


    int main() {

        int t;
        cin >> t;

        for(int cs = 0; cs < t; cs++) {

            int n, m;
            cin >> n >> m;


            int a[n][m];
            vector<int> mv(n * m + 2, 0);

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cin >> a[i][j];
                    mv[a[i][j]] = 1;
                }
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(i > 0 and a[i - 1][j] == a[i][j]) {
                        mv[a[i][j]] = 2;
                    }
                    if(j > 0 and a[i][j - 1] == a[i][j]) {
                        mv[a[i][j]] = 2;
                    } 
                }
            }

            int tot = 0, mx = 0;

            for(int i = 0; i <= n * m; i++) {
                tot += mv[i];
                mx = max(mv[i], mx);
            }

            cout << tot - mx << endl;


        }

        return 0;
    }
