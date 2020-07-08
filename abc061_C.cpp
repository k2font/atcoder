#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
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

int main() {
  ll N, K; cin >> N >> K;
  vector<ll> a(N), b(N);
  REP(i, N) cin >> a[i] >> b[i];

  map<ll, ll> m;
  for(int i = 0; i < N; ++i) {
    m[a.at(i)] += b.at(i);
  }

  ll cnt = 0;
  ll ans = 0;
  for(auto x : m) {
    cnt += x.second;
    if(cnt >= K) {
      ans = x.first;
      break;
    }
  }
  cout << ans << endl;
}