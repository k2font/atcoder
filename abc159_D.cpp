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
int vector_finder(std::vector<int> vec, int number) {
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
  ll max_n = *max_element(all(A));
  vector<int> tmp(N + 1); REP(i, N + 1) tmp[i] = 0;
  REP(i, N) {
    tmp[A.at(i)]++;
  }

  ll a = 0;
  REP(i, max_n + 1) {
    ll b = tmp.at(i);
    if(b == 0) continue;
    a += b*(b-1)/2;
  }

  REP(i, N) {
    ll b = tmp[A.at(i)];
    ll c = b*(b-1)/2 - (b-1)*(b-2)/2;
    cout << a - c << endl;
  }
}
