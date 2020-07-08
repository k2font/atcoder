#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    string A, B, C; cin >> A >> B >> C;

    if(A[A.size() - 1] == B[0] && B[B.size() - 1] == C[0]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}