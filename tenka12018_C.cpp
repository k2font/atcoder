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
  int N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  sort(all(A), greater<int>());
  ll ans = 0;
  if(N % 2 == 0) {
    for(int i = 0; i < N / 2 - 1; ++i) ans += A[i] * 2;
    ans += A[N / 2 - 1];
    ans -= A[N / 2];
    for(int i = N / 2 + 1; i < N; ++i) ans -= A[i] * 2;
  } else {
    ll res = 0; ll res2 = 0;
    for(int i = 0; i < N / 2 - 1; ++i) res += A[i] * 2;
    res += A[N / 2 - 1];
    res += A[N / 2];
    for(int i = N / 2 + 1; i < N; ++i) res -= A[i] * 2;

    for(int i = 0; i < N / 2; ++i) res2 += A[i] * 2;
    res2 -= A[N / 2];
    res2 -= A[N / 2 + 1];
    for(int i = N / 2 + 2; i < N; ++i) res2 -= A[i] * 2;
    ans = max(res, res2);
  }
  cout << ans << endl;
}