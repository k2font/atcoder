#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int A, B; cin >> A >> B;
    string S; cin >> S;

    string res = "Yes";
    
    if(S[A] != '-') res = "No";
    
    for(int i = 0; i < A; ++i) {
        if(S[i] == '-') {
            res = "No";
        }
    }

    for(int i = A + 1; i < A + B + 1; ++i) {
        if(S[i] == '-') {
            res = "No";
        }
    }

    cout << res << endl;
}