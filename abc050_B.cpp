#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> T(N); REP(i, N) cin >> T[i];
    int M; cin >> M;
    vector<int> P(M), X(M); REP(i, M) cin >> P[i] >> X[i];

    int tmp = 0;
    REP(i, M) {
        tmp = T[P[i] - 1];

        T[P[i] - 1] = X[i];

        cout << accumulate(all(T), 0) << endl;

        T[P[i] - 1] = tmp;
    }
}