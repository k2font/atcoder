#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int N; cin >> N;
    vector<ll> a(N); REP(i, N) cin >> a[i];

    int cnt_four = 0;
    int cnt_two = 0;
    int cnt_one = 0;
    for(int j = 0; j < N; ++j) {
        if(a.at(j) % 4 == 0) {
            cnt_four++;
        }

        if(a.at(j) % 2 == 0 && a.at(j) % 4 != 0) {
            cnt_two++;
        }

        if(a.at(j) % 2 != 0 && a.at(j) % 4 != 0) {
            cnt_one++;
        }
    }

    if(cnt_two == 0) {
        if(cnt_one <= cnt_four + 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if(cnt_one <= cnt_four) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}