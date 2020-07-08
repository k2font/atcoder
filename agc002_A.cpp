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
  ll a, b; cin >> a >> b;

  string str = "";
  if(a <= 0 && b >= 0) {
    str = "Zero";
  } else if(a > 0 && b > 0) {
    str = "Positive";
  } else if(a < 0 && b < 0) {
    if((a - b + 1) % 2 == 0) {
      str = "Positive";
    } else {
      str = "Negative";
    }
  }

  cout << str << endl;
}