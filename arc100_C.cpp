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
  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> tmp;
  REP(i, N) tmp.push_back(A[i] - (i + 1));
  sort(all(tmp));
  size_t median_index = tmp.size() / 2;
  double b = (tmp.size() % 2 == 0
    ? static_cast<double>(tmp[median_index] + tmp[median_index - 1]) / 2
    : tmp[median_index]);
  ll ans = 0;
  REP(i, N) {
    ans += abs(A[i] - (round(b) + (i + 1)));
  }
  cout << ans << endl;
}