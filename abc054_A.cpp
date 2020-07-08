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

    string res = "Draw";

    if(A > B) {
        res = "Alice";
    } else if(A < B) {
        res = "Bob";
    }

    if(A == 1) {
        res = "Alice";
    } else if(B == 1) {
        res = "Bob";
    }

    if(A == B) res = "Draw";

    cout << res << endl;
}