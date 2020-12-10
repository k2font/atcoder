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
  vector<ll> left(N + 1, 0);
  vector<ll> right(N + 1, 0);
  for(int i = 2; i < N; i += 2) {
    left[i] = left[i - 2] + H[i - 1] - H[i - 2];
    right[i] = right[i - 2] + H[N - i + 1] - H[N - i];
  }
  ll ans = pow(10, 18);
  for(auto w: W) {
    int i = lower_bound(all(H), w) - H.begin(); // wが前から何番目にいればいいか
    if(i % 2 == 0) chmin(ans, left[i] + right[N - i - 1] + H[i] - w);
    else chmin(ans, left[i - 1] + right[N - i] + w - H[i - 1]);
  }
  cout << ans << endl;
}