#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    string s; cin >> s;

    int zero = 0;
    int one = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '0') {
            zero++;
        } else {
            one++;
        }
    }

    cout << 2 * min(zero, one) << endl;
}