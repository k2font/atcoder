#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int X, A, B; cin >> X >> A >> B;

    if(X >= B - A && B - A <= 0) {
        cout << "delicious" << endl;
    } else if(X >= B - A && B - A > 0){
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }
}