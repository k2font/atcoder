#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int K, N; cin >> K >> N;
    vector<int> A(N); REP(i, N) cin >> A[i];

    int max_n = 0;
    for(int i = 0; i < N; ++i) {
        int b = A[i] - A[i - 1];
        if(max_n < b) {
            max_n = b;
        }
    }

    int b = 0;
    if(A[0] == 0) {
        b = K - A[N - 1];
    } else {
        b = A[0] + (K - A[N - 1]);
    }
    if(max_n < b) {
        max_n = b;
    }

    cout << K - max_n << endl;
}