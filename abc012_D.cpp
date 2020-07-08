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
  int N, M; cin >> N >> M;
  vector<vector<int>> d(N, vector<int>(N, INF));
  REP(i, M) {
    int a, b, t; cin >> a >> b >> t; a--; b--;
    d[a][b] = t;
    d[b][a] = t;
  }
  REP(i, N) {
    d[i][i] = 0;
  }
  for (int k = 0; k < N; k++){       // 経由する頂点
    for (int i = 0; i < N; i++) {    // 始点
      for (int j = 0; j < N; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int res = 0;
  int ans = INF;
  REP(i, N) {
    res = 0;
    REP(k, N) {
      if(d[i][k] > res) res = d[i][k];
    }
    if(ans > res) ans = res;
  }
  cout << ans << endl;
}