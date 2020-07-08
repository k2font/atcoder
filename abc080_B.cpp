#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N; cin >> N;
    vector<int> a(N); REP(i, N) cin >> a[i];

    sort(all(a));

    int alice = 0;
    int bob = 0;
    for(int i = N; i > 0; --i) {
        if(i % 2 == 0) alice += a[i - 1];
        if(i % 2 == 1) bob += a[i - 1];
    }

    cout << abs(alice - bob) << endl;
}