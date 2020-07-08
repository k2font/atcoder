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

const ll INF = 1e9;
int main() {
  int H, W; cin >> H >> W;
  vector<vector<int>> c(10, vector<int>(10));
  REP(i, 10) {
    REP(k, 10) {
      cin >> c[i][k];
    }
  }
  vector<vector<int>> A(H, vector<int>(W));
  REP(i, H) {
    REP(k, W) {
      cin >> A[i][k];
    }
  }
  for (int k = 0; k < 10; k++){       // 経由する頂点
    for (int i = 0; i < 10; i++) {    // 始点
      for (int j = 0; j < 10; j++) {  // 終点
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }
  ll ans = 0;
  REP(i, H) {
    REP(k, W) {
      if(A[i][k] != 1 && A[i][k] != -1) {
        ans += c[A[i][k]][1];
      }
    }
  }
  cout << ans << endl;
}