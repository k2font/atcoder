#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    string S; cin >> S;

    int cnt = 0;
    int trig = 0;
    int r_cnt = 0;
    vector<int> res(S.size()); REP(i, S.size()) res[i] = 0;

    REP(i, S.size()) {
        if((S[i] == 'R' && S[i - 1] == 'R') || i == 0) {
            cnt++;
        } else if(S[i - 1] == 'R' && S[i] == 'L') {
            trig = i - 1;
            r_cnt = cnt - 1;
            cnt++;
        } else if(S[i - 1] == 'L' && S[i] == 'L') {
            cnt++;
        } else if(S[i] == 'R' && S[i - 1] == 'L') {
            if(cnt % 2 == 0) {
                res[trig] = cnt / 2;
                res[trig + 1] = cnt / 2;
            } else {
                if(r_cnt % 2 == 1) {
                    res[trig] = cnt / 2;
                    res[trig + 1] = cnt / 2 + 1;
                } else {
                    res[trig] = cnt / 2 + 1;
                    res[trig + 1] = cnt / 2;
                }
            }
            cnt = 1;
            trig = 0;
        }

        // ラストLのとき
        if(i == S.size() - 1) {
            if(cnt % 2 == 0) {
                res[trig] = cnt / 2;
                res[trig + 1] = cnt / 2;
            } else {
                if(r_cnt % 2 == 1) {
                    res[trig] = cnt / 2;
                    res[trig + 1] = cnt / 2 + 1;
                } else {
                    res[trig] = cnt / 2 + 1;
                    res[trig + 1] = cnt / 2;
                }
            }
            cnt = 1;
            trig = 0;
        }
    }

    REP(i, S.size()) cout << res[i] << " ";
    cout << endl;
}