#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main() {
    int N; cin >> N;
    vector<int> s(N); REP(i, N) cin >> s[i];

    sort(all(s));
    int ans = accumulate(all(s), 0);
    if(ans % 10 == 0) {
        REP(i, N) {
            int a = ans - s[i];
            if(a % 10 != 0) {
                ans = a;
                break;
            }

            if(i == N - 1) {
                ans = 0;
            }
        }
    }

    cout << ans << endl;
}