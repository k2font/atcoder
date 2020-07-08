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
  vector<int> ans(N - 1);
  REP(i, N - 1) {
    if(A[i + 1] - A[i] > 0) ans[i] = 1;
    else if(A[i + 1] - A[i] == 0) ans[i] = 0;
    else if(A[i + 1] - A[i] < 0) ans[i] = -1;
  }

  int tmp = 0;
  int cnt = 0;
  REP(i, N - 1) {
    if(i == 0) {
      cnt++;
      tmp = ans[i];
      continue;
    }
    if(tmp != ans[i] && ans[i] != 0) {
      if(tmp != ans[i + 1]) {
        cnt++;
        tmp = ans[i];
      } else {
        tmp = ans[i];
      }
    }
  }
  cout << cnt << endl;
}