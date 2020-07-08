#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    string S; cin >> S;
    string res = "";

    sort(all(S));

    REP(i, S.size() - 1) {
        if(S[i] == S[i + 1]) {
            res = "no";
            break;
        }

        if(i == S.size() - 2) {
            res = "yes";
        }
    }

    cout << res << endl;
}