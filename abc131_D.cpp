#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N; cin >> N;
    vector<int> A(N), B(N);
    vector<pair<ll, ll>> p(N);
    REP(i, N) {
        cin >> A[i] >> B[i];
        p[i] = make_pair(B[i], A[i]);
    }

    sort(all(p), greater<pair<int,int>>());
    ll sum_num = accumulate(all(A), 0);

    string res = "No";
    for(int i = 0; i < N; ++i) {
        if(i == 0) {
            if(p[i].first < sum_num) {
                break;
            }
        } else {
            sum_num = sum_num - p[i - 1].second;
            if(p[i].first < sum_num) {
                break;
            }
        }

        if(i == N - 1) {
            res = "Yes";
        }
    }

    cout << res << endl;
}