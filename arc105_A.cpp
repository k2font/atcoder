#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int, int>;
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
struct edge {
  ll to, cost;
};

int main() {
  ll A, B, C, D; cin >> A >> B >> C >> D;
  string ans = "No";
  int n = 4;
  for(int bit = 0; bit < (1 << n); bit++) {
    if(bit == 0) continue;
    ll a = 0;
    for(int i = 0; i < n; ++i) {
      if(bit & (1 << i)) {
        if(i == 0) a += A;
        else if(i == 1) a += B;
        else if(i == 2) a += C;
        else if(i == 3) a += D;
      }
    }
    ll b = 0;
    for(int i = 0; i < n; ++i) {
      if(!(bit & (1 << i))) {
        if(i == 0) b += A;
        else if(i == 1) b += B;
        else if(i == 2) b += C;
        else if(i == 3) b += D;
      }
    }
    if(a == b) ans = "Yes";
  }
  cout << ans << endl;
}