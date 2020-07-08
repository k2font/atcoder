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
    string S; cin >> S;

    sort(all(S));

    int r = 0;
    int b = 0;
    REP(i, N) {
        if(S[i] == 'R') {
            r++;
        } else {
            b++;
        }
    }

    if(r > b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}