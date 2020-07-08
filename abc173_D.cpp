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
  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  sort(all(A), greater<ll>());
  ll com = 0; // 心地よさ
  ll tmp = N;
  for(int i = 0; i < N; ++i) {
    if(i == 0) {
      tmp--;
      com += A[0];
    } else {
      tmp--;
      if(tmp >= 2) {
        com += (A[i] * 2);
        tmp--;
      }
      else if(tmp == 1) {
        com += A[i];
        tmp--;
      }
    }
  }
  cout << com << endl;
}