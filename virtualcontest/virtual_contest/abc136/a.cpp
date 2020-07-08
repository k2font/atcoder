#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int A, B, C; cin >> A >> B >> C;

    if(A > B + C) {
        cout << 0 << endl;
    } else {
        cout << C - (A - B) << endl;
    }
}