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
  ll N, K; cin >> N >> K;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  ll MOD = pow(10, 9) + 7;
  ll ans = 0;
  ll a = K * (K - 1) / 2;
  ll b, c = 0;
  REP(i, N) {
    REP(k, N) {
      if(A[i] > A[k]) b++;
    }
    for(int k = i + 1; k < N; ++k) {
      if(A[i] > A[k]) c++;
    }
  }
  ans += a % MOD * b % MOD;
  ans %= MOD;
  ans += c * K;
  ans %= MOD;
  cout << ans << endl;
}