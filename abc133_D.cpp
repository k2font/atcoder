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
struct edge {
  ll to, cost;
};

int main() {
  int N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> ans;
  ll tmp = 0;
  REP(i, N) { // i = 0
    if(i % 2 == 0) tmp += A[i];
    else tmp -= A[i];
  }
  ans.push_back(tmp);
  tmp = 0;
  REP(i, N) { // i = 1
    if(i % 2 == 1 || i == 0) tmp += A[i];
    else tmp -= A[i];
  }
  ans.push_back(tmp);
  tmp = 0;
  for(int i = 2; i < N; ++i) { // i = 2以降はO(1)で求める
    tmp = ans[i - 2] + (A[i - 1] * 2 - A[i - 2] * 2);
    ans.push_back(tmp);
  }
  REP(i, N) {
    cout << ans[i];
    if(i != N - 1) cout << " ";
  }
  cout << endl;
}