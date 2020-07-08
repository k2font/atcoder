#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int pool = 0; int out = 0;
    REP(i, S.size()) {
        if(S[i] == '(') {
            pool++;
        } else {
            if(pool > 0) {
                pool--;
            } else {
                out++;
            }
        } 
    }
    REP(i, out) {
        S = '(' + S;
    }
    REP(i, pool) {
        S = S + ')';
    }
    cout << S << endl;
}