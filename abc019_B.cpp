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

    char res = 'a';
    int cnt = 0;
    string result;
    string tmp;
    for(int i = 0; i < s.size(); ++i) {
        if(i == 0) {
            res = s[0];
            cnt++;
            continue;
        }

        if(s[i - 1] != s[i]) {
            tmp += char_to_string(res);
            tmp += to_string(cnt);
            result = result + tmp;

            tmp = "";
            res = s[i];
            cnt = 1;
        } else {
            cnt++;
        }

        if(i == s.size() - 1) {
            tmp += char_to_string(res);
            tmp += to_string(cnt);
            result = result + tmp;
        }
    }

    cout << result << endl;
}