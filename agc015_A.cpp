#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    ll N, A, B; cin >> N >> A >> B;

    if(A > B) {
        cout << 0 << endl;
    } else if(N == 1 && B - A != 0) {
        cout << 0 << endl;
    } else if(N == 1 && B - A == 0) {
        cout << 1 << endl;
    } else {
        // cout << pow(B - A + 1, N - 2) << endl;
        cout << (B - A + 1) * (N - 2) - ((N - 2) - 1) << endl;
    }
}