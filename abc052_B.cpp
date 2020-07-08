#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N; cin >> N;
    string S; cin >> S;

    int res = 0;
    int result = 0;
    for(int i = 0; i < N; ++i) {
        if(S[i] == 'I') {
            res++;
        } else {
            res--;
        }

        if(res > result) {
            result = res;
        }
    }

    cout << result << endl;
}
