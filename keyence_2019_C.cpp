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
  vector<int> A(N), B(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  vector<ll> tmp(N); REP(i, N) tmp[i] = 0;
  vector<ll> dif(N); REP(i, N) dif[i] = 0;
  vector<ll> dif_a_b;
  ll ans = 0;
  if(accumulate(all(A), 0LL) < accumulate(all(B), 0LL)) {
    ans = -1;
  } else {
    REP(i, N) {
      if(A[i] < B[i]) {
        tmp[i] = 1;
        dif[i] = B[i] - A[i];
      } else {
        dif_a_b.push_back(A[i] - B[i]);
      }
    }
    sort(all(dif_a_b), greater<int>());
    ll cnt = 0;
    ll cnt_dif = 0;
    REP(i, N) {
      if(tmp[i] == 1) {
        cnt++;
        cnt_dif += dif[i];
      }
    }
    REP(i, dif_a_b.size()) {
      if(cnt_dif <= 0) break;
      cnt++;
      cnt_dif -= dif_a_b[i];
    }
    ans = cnt;
  }

  cout << ans << endl;
}
