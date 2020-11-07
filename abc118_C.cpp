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
struct edge {
  ll to, cost;
};

int main() {
  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  sort(all(A));
  ll ans = 0; ll tmp = A[0]; ll cnt = 0; ll k = 0;
  while(true) {
    REP(i, N) {
      if(i == k) continue;
      A[i] = A[i] % tmp;
      if(A[i] == 0) cnt++;
    }
    sort(all(A));
    REP(i, N) {
      if(A[i] == 0) continue;
      tmp = A[i];
      k = i;
      break;
    }
    if(cnt == N - 1) {
      ans = tmp;
      break;
    }
    cnt = 0;
  }
  cout << ans << endl;
}