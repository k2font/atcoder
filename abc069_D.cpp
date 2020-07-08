#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}


int main() {
    int H, W; cin >> H >> W;
    int N; cin >> N;
    vector<int> a(N); REP(i, N) cin >> a[i];

    int h = 0;
    int w = 0;
    bool flag = true;
    vector<deque<ll>> ans(H);

    for(int i = 0; i < N; ++i) {
        for(int k = 0; k < a[i]; ++k) {
            if(flag) ans[h].push_back(i + 1);
            if(!flag) ans[h].push_front(i + 1);

            if(ans[h].size() == W) {
                h++;
                flag = !flag;
            }
        }
    }

    REP(i, H) {
        REP(k, W) {
            cout << ans[i][k] << " ";
        }
        cout << endl;
    }
}