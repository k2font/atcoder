#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;

    vector<char> S(N); REP(i, N) cin >> S[i];

    sort(S.begin(), S.end());

    int cnt = 1;
    REP(i, N - 1) {
        if(S[i] != S[i + 1]) {
            cnt++;
        }

        if(i == N - 1) {
            if(S[i] != S[i + 1]) {
                cnt++;
            }
        }
    }

    if(cnt == 3) {
        cout << "Three" << endl;
    } else {
        cout << "Four" << endl;
    }
}