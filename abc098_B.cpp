#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int check(string a, string b) {
    int cnt = 0;
    sort(all(a));
    sort(all(b));
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] == a[i - 1]) continue;
        for(int j = 0; j < b.size(); ++j) {
            if(a[i] == b[j]) {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main(){
    int N; cin >> N;
    string S; cin >> S;

    int res = 0;
    for(int i = 1; i < N; ++i) {
        string suba = S.substr(0, i);
        string subb = S.substr(i);
        int cnt = check(suba, subb);
        if(res < cnt) res = cnt;
    }

    cout << res << endl;
}