#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;
    vector<long long> A(N + 1); REP(i, N + 1) cin >> A[i];
    vector<long long> B(N); REP(i, N) cin >> B[i];

    long long cnt = 0;
    long long min_n = 0;
    for(int i = 0; i < N; ++i) {
        min_n = min(A[i], B[i]);
        A[i] = A[i] - min_n;
        B[i] = B[i] - min_n;
        cnt += min_n;
        
        min_n = min(A[i + 1], B[i]);
        A[i + 1] = A[i + 1] - min_n;
        B[i] = B[i] - min_n;
        cnt += min_n;
    }

    cout << cnt << endl;
}