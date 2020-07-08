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
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
  int N, M; cin >> N >> M;
  ll ans = 0;
  ll MOD = pow(10, 9) + 7;
  if(abs(N - M) > 1) {
    ans = 0;
  } else {
    ll n_mod = 1;
    ll m_mod = 1;
    for(int i = 1; i <= N; ++i) {
      n_mod = n_mod * i;
      n_mod = n_mod % MOD;
    }
    for(int i = 1; i <= M; ++i) {
      m_mod = m_mod * i;
      m_mod = m_mod % MOD;
    }
    if(N == M) ans = n_mod * m_mod * 2;
    else ans = n_mod * m_mod;
    ans = ans % MOD;
  }
  cout << ans << endl;
}
