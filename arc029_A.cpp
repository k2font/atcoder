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
  int N; cin >> N;
  vector<int> t(N); REP(i, N) cin >> t[i];
  ll ans = 10000;
  for(int bit = 0; bit < (1 << N); ++bit) {
    int a = 0; int b = 0;
    for(int i = 0; i < N; ++i) {
      if(!(bit & (1 << i))) {
        a += t[i];
      }

      if(bit & (1 << i)) {
        b += t[i];
      }
    }
    int res = max(a, b);
    if(ans > res) ans = res;
  }
  cout << ans << endl;
}
