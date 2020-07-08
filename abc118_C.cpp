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
    vector<ll> A(N); REP(i, N) cin >> A[i];

    ll res = 0;
    int cnt = 0;
    while(true) {
        ll min_num = *min_element(A.begin(), A.end(), [](int a, int b) {
            return (a == 0) ? false : (b == 0) || a < b;
        });
        cnt = 0;
        res = 0;
        bool flag = false;
        for(int i = 0; i < N; ++i) {
            if(A[i] == 0) {
                cnt++;
            } else {
                res = A[i];
                if(min_num == A[i] && flag == false) {
                    flag = true;
                    continue;
                }
                A[i] = A[i] % min_num;
            }
        }

        if(cnt == N - 1) break;
    }

    cout << res << endl;
}