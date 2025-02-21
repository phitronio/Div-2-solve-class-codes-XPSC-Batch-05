    #include<bits/stdc++.h>

    using namespace std;


    bool check_middle(string s, int l, int r) {

        while(l <= r) {
            if(s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }


    bool check_prefix(string s, int l, int r, int limit) {

        vector<int> cnt(26, 0);

        for(int i = 0; i < limit; i++) {
            char ch = s[l + i];

            cnt[ch - 'a']++;
        }

        for(int i = 0; i < limit and r - i > l + limit - 1; i++) {
            char ch = s[r - i];

            if(cnt[ch - 'a'] <= 0) return false;
            cnt[ch - 'a']--; 
        }

        return true;
    }


    int solve(string s) {

        int n = s.size();

        int l = 0, r = n - 1;

        while(s[l] == s[r] and l < r) l++, r--;

        if(l > r) return 0; // already palindrome

        int lo = 0, hi = r - l + 1, res;

        while(lo <= hi) {

            int mid = (lo + hi) / 2;

            int mid_l = l + mid, mid_r = r - mid;

            int mid_palin = check_middle(s, mid_l, mid_r);

            int valid_prefix = check_prefix(s, l, r, mid);

            if(mid_palin and valid_prefix) {
                res = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }


        return res;
    }



    int main() {

        int t;
        cin >> t;

        for(int cs = 0; cs < t; cs++) {

            string s;
            cin >> s;

            int res = solve(s);

            reverse(s.begin(), s.end());

            res = min(res, solve(s));

            cout << res << endl;

        }

        return 0;
    }
