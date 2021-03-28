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
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
  ll H, W; cin >> H >> W;
  // 4パターンのうち2パターンを計算して、後でHとWを入れ替える
  // 横方向に切る
  ll ans = 10000000000000;
  for(int i = 1; i < H; ++i) {
    ll tmp = (H - i) / 2;
    ll minn = min(min(W * tmp, W * (H - i - tmp)), W * i);
    ll maxn = max(max(W * tmp, W * (H - i - tmp)), W * i);
    ans = min(ans, maxn - minn);

    ll W2 = W / 2;
    minn = min(min(W2 * (H - i), (H - i) * (W - W2)), W * i);
    maxn = max(max(W2 * (H - i), (H - i) * (W - W2)), W * i);
    ans = min(ans, maxn - minn);
  }

  // 縦方向に切る
  for(int i = 1; i < W; ++i) {
    ll tmp = (W - i) / 2;
    ll minn = min(min(H * tmp, H * (W - i - tmp)), H * i);
    ll maxn = max(max(H * tmp, H * (W - i - tmp)), H * i);
    ans = min(ans, maxn - minn);

    ll H2 = H / 2;
    minn = min(min(H2 * (W - i), (W - i) * (H - H2)), H * i);
    maxn = max(max(H2 * (W - i), (W - i) * (H - H2)), H * i);
    ans = min(ans, maxn - minn);
  }

  cout << ans << endl;
}