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
    vector<pair<long long, string>> p(N);
    int X;
    string C;
    REP(i, N) {
        cin >> X >> C;
        p[i] = make_pair(X, C);
    }

    sort(all(p));

    for(int i = 0; i < N; ++i) {
        if(p[i].second == "R") cout << p[i].first << endl;
    }

    for(int i = 0; i < N; ++i) {
        if(p[i].second == "B") cout << p[i].first << endl;
    }
}