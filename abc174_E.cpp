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
  int N; ll K; cin >> N >> K;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  ll ng = 0; ll ok = *max_element(all(A));
  while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    ll tmp = 0;
    REP(i, N) {
      tmp += (A[i] - 1) / mid;
    }
    if(K >= tmp) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}