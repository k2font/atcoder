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
  ll N, X, M; cin >> N >> X >> M;
  ll ans = 0;
  vector<P> memo(M);
  for(ll i = 0; i < N; ++i) {
    if(memo[X].first) {
      const ll t = i - memo[X].first; // ループ1周分の長さ
      const ll c = (N - i - 1) / t; // ループがあとどれくらい回るか
      i += t * c; // ワープ
      ans += (ans - memo[X].second) * c;
    } else { // まだ一度も見ていないあまり
      memo[X] = P(i, ans);
    }
    ans += X;
    X *= X; X %= M;
  }
  cout << ans << endl;
}