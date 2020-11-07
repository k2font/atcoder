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

// 最大公約数
int gcd(int a, int b) {
  if (a % b == 0) {
    return(b);
  } else {
    return(gcd(b, a % b));
  }
}

int main() {
  int K; cin >> K;
  ll ans = 0;
  REP(i, K) {
    REP(j, K) {
      REP(k, K) {
        ans += gcd((i + 1), gcd((j + 1), (k + 1)));
      }
    }
  }
  cout << ans << endl;
}