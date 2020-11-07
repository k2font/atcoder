#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
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
  int N, M; cin >> N >> M;
  vector<ll> H(N); REP(i, N) cin >> H[i];
  vector<ll> W(M); REP(i, M) cin >> W[i];
  sort(all(H)); // 身長はソートしておく
  sort(all(W)); // 変形形態もソートしておく
  // Wからどれを選ぶかは二分探索で求める
  // 各Hとの差が最も小さいもの
  ll res = pow(10, 10); ll p = -1;
  REP(i, N) {
    bool f = false;
    ll tmp = *lower_bound(all(W), H[i]);
    if(tmp - H[i] > H[i + 1] - H[i]) {
      f = true;
    } else {
      if(res > tmp - H[i]) {
        res = tmp - H[i];
        p = tmp;
      }
    }
    if(f) i++; // Wから取らなかったら飛ばす
  }
  H.push_back(p);
  sort(all(H));
  ll ans = 0;
  REP(i, N + 1) {
    if(i % 2 == 1) continue;
    ans += (H[i + 1] - H[i]);
  }
  cout << ans << endl;
}