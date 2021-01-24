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
  vector<int> L(N); REP(i, N) cin >> L[i];
  sort(all(L));

  ll ans = 0;
  for(int i = 0; i < N - 2; ++i) {
    for(int k = i + 1; k < N - 1; ++k) {
      int m = lower_bound(L.begin(), L.end(), L[i] + L[k]) - L.begin(); // 末尾までの距離
      ans += max(m - (k + 1), 0);
    }
  }
  cout << ans << endl;
}