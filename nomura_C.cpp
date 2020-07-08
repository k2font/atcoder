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
  vector<ll> A(N + 1); REP(i, N + 1) cin >> A[i];
  ll ans = 0;
  ll before = 0;
  ll tmp = 0;
  // -1チェック
  for(int i = 0; i <= N; ++i) {
    if(pow(2, i) <= A[i] && i != N) {
      cout << -1 << endl;
      return 0;
    }
    if(i == N && 0 >= A[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  
  for(int i = N; i >= 0; --i) {
    ll a = pow(2, i);
    if(i <= 27) ans += min(A[N], a); // 葉の個数
    if(A[i] > 0 && i != N && i > 1 && A[i - 1] == 0) ans++;
  }
  cout << ans << endl;
}