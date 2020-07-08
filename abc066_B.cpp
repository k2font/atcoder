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

    string tmp1, tmp2;
    ll siz = S.size();
    for(int i = 0; i < siz; ++i) {
        S.pop_back();
        if(S.size() % 2 == 0) {
            tmp1 = S.substr(0, S.size() / 2);
            tmp2 = S.substr(S.size() / 2);
            if(tmp1 == tmp2) break;
        } else {
            continue;
        }
    }
    cout << tmp1.size() + tmp2.size() << endl;
}
