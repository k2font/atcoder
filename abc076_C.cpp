#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

int main() {
  string sd, T; cin >> sd >> T;

  bool flag = false;
  REP(i, sd.size()) {
    if(sd.at(i) == T.at(0)) {
      REP(j, T.size()) {
        if(j == 0) continue;
        if(sd.at(i + j) == '?') {
          if(j == T.size() - 1) {
            REP(k, T.size()) {
              sd.at(i + k) = T.at(k);
              flag = true;
            }
          }
        } else {
          break;
        }
      }
    }
  }

  REP(i, sd.size()) {
    if(sd.at(i) == '?') {
      sd.at(i) = 'a';
    }
  }

  if(flag) {
    cout << sd << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
}