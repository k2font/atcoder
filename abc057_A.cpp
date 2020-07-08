#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int A, B; cin >> A >> B;

    int C = A + B;
    if(C >= 24) {
        cout << C - 24 << endl;
    } else {
        cout << C << endl;
    }
}