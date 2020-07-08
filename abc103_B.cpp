#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    string S, T; cin >> S >> T;
    deque<char> s, t;

    REP(i, S.size()) {
        s.push_back(S[i]);
    }

    string str = "";
    char res = 'a';
    REP(i, S.size()) {
        res = s[S.size() - 1];
        s.pop_back();
        s.push_front(res);

        string st(s.begin(), s.end());
        if(st == T) {
            str = "Yes";
            break;
        }

        if(i == S.size() - 1) {
            str = "No";
        }
    }

    cout << str << endl;
}