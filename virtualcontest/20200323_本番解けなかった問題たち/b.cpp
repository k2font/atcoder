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
    vector<int> P(N); REP(i, N) cin >> P[i];

    int cnt = 0;
    int min_num = P[0];
    for(int i = 0; i < N; ++i) {
        if(min_num >= P[i]) {
            cnt++;
            min_num = P[i];
        } else {
            continue;
        }
    }

    cout << cnt << endl;
}