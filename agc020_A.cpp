#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N, A, B; cin >> N >> A >> B;

    if((B - A - 1) % 2 == 0) {
        cout << "Borys" << endl;
    } else {
        cout << "Alice" << endl;
    }

    /* 
    while(true) {
        if(A == 1 || A == N) {
            cout << "Borys" << endl;
            break;
        } else if(A == 1 || A == N) {
            cout << "Alice" << endl;
            break;
        } else {
            // TODO 引き分けってどういう状態?
            cout << "Draw" <<  endl;
            break;
        }
    } */
}