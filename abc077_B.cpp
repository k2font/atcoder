#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    ll N; cin >> N;

    ll res = floor(sqrt(N)) * floor(sqrt(N));

    cout << res << endl;
}