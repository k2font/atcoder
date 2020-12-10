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
  vector<ll> V(N); REP(i, N) cin >> V[i];
  ll ans = 0;
  for(int p = 0; p <= min(N, K); ++p) {
    for(int q = 0; p + q <= min(N, K); ++q) {
      ll res = 0; vector<ll> tmp;
      for(int i = 0; i < p; ++i) {
        res += V[i]; tmp.push_back(V[i]);
      }
      for(int i = 0; i < q; ++i) {
        res += V[N - 1 - i]; tmp.push_back(V[N - 1 - i]);
      }
      sort(all(tmp));
      for(int i = 0; i < min(K - p - q, (int)tmp.size()); ++i) {
        if(tmp[i] < 0) res -= tmp[i];
      }
      ans = max(ans, res);
      tmp.clear();
    }
  }
  cout << ans << endl;
}