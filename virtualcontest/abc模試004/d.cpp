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

    int cnt = 0;
    int res = -1;

    int b = 1;
    for(int i = 0; i < 100000; ++i) {
        b = a[b - 1];
        cnt++;
        if(b == 2) {
            res = cnt;
            break;
        }
    }

    cout << res << endl;
}