#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int A, B, C; cin >> A >> B >> C;

    if(A <= C && C <= B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}