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
  int N, M; cin >> N >> M;
  vector<int> A(M), B(M); REP(i, M) cin >> A[i] >> B[i];
  vector<vector<int>> G(N, vector<int>(N, 1000000007));
  for (int i = 0; i < N; i++) {
    G[i][i] = 0;
  }
  for (int i = 0; i < M; i++) {
    G[A[i] - 1][B[i] - 1] = 1;
    G[B[i] - 1][A[i] - 1] = 1;
  }

  for (int k = 0; k < N; k++){       // 経由する頂点
    for (int i = 0; i < N; i++) {    // 始点
      for (int j = 0; j < N; j++) {  // 終点
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }

  REP(i, N) {
    int ans = 0;
    REP(k, N) {
      if(G[i][k] == 2) ans++;
    }
    cout << ans << endl;
  }
}