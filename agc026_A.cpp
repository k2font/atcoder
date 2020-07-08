#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> a(N); REP(i, N) cin >> a[i];

    int color = 10000;
    int cnt = 0;
    REP(i, N - 1) {
        if(a[i] == a[i + 1]) {
            a[i + 1] = color;
            color--;
            cnt++;
        }
    }

    cout << cnt << endl;
}