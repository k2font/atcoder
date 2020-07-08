#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int, int>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
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
  int D; cin >> D;
  vector<int> c(26); REP(i, 26) cin >> c[i];
  vector<vector<int>> s(D, vector<int>(26));
  REP(i, D) {
    REP(k, 26) {
      cin >> s[i][k];
    }
  }
  REP(i, D) {
    int max_n = 0;
    int res = 0;
    REP(k, 26) {
      if(res < s[i][k]) {
        res = s[i][k];
        max_n = k + 1;
      }
    }
    cout << max_n << endl;
  }
}