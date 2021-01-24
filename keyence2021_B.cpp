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
  int N, K; cin >> N >> K;
  vector<ll> a(N); REP(i, N) cin >> a[i];
  map<int, int> m;
  REP(i, N) m[a[i]]++;
  ll ans = 0;
  while(K > 0) {
    // 表示できる数の最大値を求める
    int maxn = -1; int bef = -1;
    bool f = false;
    for(auto x : m) {
      if(x.second <= 0) continue;
      if(abs(bef - x.first) == 1 && x.second > 0) {
        bef = x.first;
      } else {
        maxn = bef + 1; f = true;
        break;
      }
      // cout << "m: " << x.second << endl;
    }
    if(f == false) maxn = bef + 1;
    // cout << maxn << endl;

    // 個数の最小値を求める
    int minn = pow(10, 9);
    for(auto x : m) {
      if(x.second <= 0) continue;
      if(minn > x.second) minn = x.second;
    }

    // 個数の最小値 * maxn
    ans += min(minn, K) * maxn;
    K -= minn;

    // 個数の最小値をすべての要素から引き算する。
    for(auto x : m) {
      if(x.second <= 0) continue;
      m[x.first] -= minn;
    }
  }

  cout << ans << endl;
}
