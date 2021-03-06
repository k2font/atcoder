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
  vector<string> S(N); REP(i, N) cin >> S[i];
  for(int i = N - 2; i >= 0; --i) {
    REP(k, S[i].size()) {
      if(S[i][k] == '#') {
        if(S[i + 1][k - 1] == 'X' || S[i + 1][k] == 'X' || S[i + 1][k + 1] == 'X') {
          S[i][k] = 'X';
        }
      }
    }
  }
  REP(i, N) cout << S[i] << endl; 
}
