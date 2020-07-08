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

    for(int i = 0; i < s.size(); ++i) {
        if(i == 5 || i == 13) {
            cout << " ";
            continue;
        }
        cout << s[i];
    }
    cout << endl;
}