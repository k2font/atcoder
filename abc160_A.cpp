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
    if(S[2] == S[3] && S[4] == S[5]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}