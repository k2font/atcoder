#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int A, B; cin >> A >> B;

    int res = A + B;
    if(res < 10) {
        cout << res << endl;
    } else {
        cout << "error" << endl;
    }
}