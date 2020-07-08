#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> A(N); REP(i, N) cin >> A[i];

    int cnt = 0;
    REP(i, N) {
        if(A[i] % 2 == 1) {
            cnt++;
        }
    }

    // 奇数の数値が偶数個あればYES
    if(cnt % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}