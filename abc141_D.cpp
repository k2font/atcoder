#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N, M; cin >> N >> M;
    priority_queue<ll> A;
    REP(i, N) {
        int a;
        cin >> a;
        A.push(a);
    }

    for(int i = 0; i < M; ++i) {
        ll b = A.top();
        A.pop();
        A.push(b / 2);
    }

    ll res = 0;
    for(int i = 0; i < N; ++i) {
        res += A.top();
        A.pop();
    }

    cout << res << endl;
}
