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

    int tmp, cnt; tmp = 0; cnt = 0;
    vector<int> a(S.size() + 1); a[0] = 0;
    bool flag = false;

    REP(i, S.size()) {
        if(S[i] == '<') {
            if(i == 0) {
                a[i] = 0;
                continue;
            }

            if(flag == false) {
                a[i] = a[i - 1] + 1;
            } else if(flag == true) {
                for(int k = tmp; k <= i; ++k) {
                    a[k] = a[tmp - 1] + cnt;
                    cnt--;
                    if(k == i) {
                        a[k] = 0;
                        flag = false;
                        cnt = 0;
                    }
                }
            }
        } else if(S[i] == '>') {
            if(flag == false) {
                tmp = i;
                flag = true;
            }
            cnt++;

            if(i == S.size() - 1) {
                for(int k = tmp; k <= i; ++k) {
                    a[k] = cnt;
                    cnt--;
                    if(k == i) flag = false;
                }
            }
        }
    }

    REP(i, S.size()) cout << a[i] << endl;

    cout << accumulate(all(a), 0) << endl;
}