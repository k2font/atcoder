#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    string s, t; cin >> s >> t;

    string s_d = s;
    string t_d = t;
    bool res; res = false;

    sort(all(s_d));
    sort(all(t_d), std::greater<int>());

    if(s_d.size() < t_d.size()) {
        for(int i = 0; i < s_d.size(); ++i) {
            if(s_d[i] != t_d[i]) {
                break;
            }

            if(i == s_d.size() - 1) {
                res = true;
            }
        }
    }

    for(int i = 0; i < s_d.size(); ++i) {
        if(s_d[i] != t_d[i]) {
            if(s_d[i] < t_d[i]) {
                res = true;
                break;
            }
        }
    }

    if(res == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}