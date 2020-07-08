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
  int N, K; cin >> N >> K;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<pair<ll, ll>> p(N);
  REP(i, N) p[i] = make_pair(abs(A[i]), A[i]);
  sort(all(p), greater<pair<ll, ll>>());
  ll ans_f = 1; ll min_f = 0;
  ll ans_b = 1; ll min_b = 0;
  const ll MOD = pow(10, 9) + 7;
  for(int i = N - 1; i >= N - K; --i) {
    ans_f *= p[i].second;
    ans_f %= MOD;
    if(ans_f < 0) ans_f += MOD;
  }
  REP(i, K) {
    ans_b *= p[i].second;
    ans_b %= MOD;
    if(ans_f < 0) ans_f += MOD;
  }
  cout << max(ans_f, ans_b) << endl;
}