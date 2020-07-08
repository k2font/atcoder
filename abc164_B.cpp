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
  int A, B, C, D; cin >> A >> B >> C >> D;

  string str = "No";
  while(true) {
    C = C - B;
    if(C <= 0) {
      str = "Yes";
      break;
    }

    A = A - D;
    if(A <= 0) {
      str = "No";
      break;
    }
  }

  cout << str << endl;
}