#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
  string S, T; cin >> S >> T;
  int ans = pow(10, 9) + 7;
  for(int i = 0; i < S.size() - T.size() + 1; ++i) {
    int res = 0;
    for(int k = 0; k < T.size(); ++k) {
      if(S[i + k] != T[k]) res++;
    }
    if(ans > res) ans = res;
  }
  cout << ans << endl;
}