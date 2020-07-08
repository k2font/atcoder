#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}


int main() {
    string S; cin >> S;
    sort(all(S));
    string str = "None";

    if(S[0] != 'a') {
        str = "a";
    } else {
        for(int i = 0; i < S.size() - 1; ++i) {
            if(S[i + 1] - S[i] > 1) {
                str = S[i] + 1;
                break;
            }

            if(i == S.size() - 2 && S[i + 1] != 'z') {
                str = S[i + 1] + 1;
            }
        }
    }

    cout << str << endl;
}