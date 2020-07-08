#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    vector<vector<int>> c(3, vector<int>(3));
    REP(i, 3) {
        REP(k, 3) {
            cin >> c[i][k];
        }
    }

    string res = "Yes";

    if(c[1][0] - c[0][0] == c[1][1] - c[0][1] &&
    c[1][0] - c[0][0] == c[1][2] - c[0][2]) {
    } else {
        res = "No";
    }

    if(c[2][0] - c[1][0] == c[2][1] - c[1][1] &&
    c[2][0] - c[1][0] == c[2][2] - c[1][2]) {
    } else {
        res = "No";
    }

    cout << res << endl;
}