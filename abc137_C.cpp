#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    long long N; cin >> N;
    vector<string> s(N); REP(i, N) cin >> s[i];

    map<string, long long> um;

    // まずは要素ごとにソートする
    long long result = 0;
    REP(i, N) {
        sort(s[i].begin(), s[i].end());
        if(um[s[i]] > 0) {
            result += um[s[i]];
            um[s[i]]++;
        } else {
            um[s[i]] = 1;
        }
    }

    cout << result << endl;
}