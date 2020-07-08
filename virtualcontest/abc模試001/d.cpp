#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    ll N, A, B, C, D, E; cin >> N >> A >> B >> C >> D >> E;

    ll res = min({A, B, C, D, E});

    if(N % res > 0) {
        cout << (N / res) + 1 + 4 << endl;
    } else if (N % res == 0) {
        cout << (N / res) + 4 << endl;
    }
}