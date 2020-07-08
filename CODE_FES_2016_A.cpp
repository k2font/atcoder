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
  string s; cin >> s;

  bool fla, flb; fla = false; flb = false;

  REP(i, s.size()) {
    if(fla == false && s[i] == 'C') fla = true;
    if(fla == true && flb == false && s[i] == 'F') {
      flb = true;
      break;
    }
  }

  if(fla == true && flb == true) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}