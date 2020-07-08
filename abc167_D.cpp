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
  ll N, K; cin >> N >> K;
  vector<int> A(N); REP(i, N) cin >> A[i], A[i]--; // 0-indexedに変更
  int logK = 1;
  while((1LL << logK) < K) {
    logK++; // Kの2進数における桁数をカウントしている
  }
  vector<vector<int>> d(logK, vector<int>(N));
  for(int i = 0; i < N; ++i) {
    d[0][i] = A[i];
  }
  for(int k = 0; k < logK - 1; ++k) {
    for(int i = 0; i < N; ++i) {
      d[k + 1][i] = d[k][d[k][i]];
    }
  }
  int now = 0;
  for (int k = 0; K > 0; k++) { // いまKの何ビット目を見ているか？
      if (K & 1) now = d[k][now]; // 0001とKのANDを取り、1ならk桁目のnowを更新する
      K = K >> 1; // 右に1ビットシフトする
  }
  cout << now + 1 << endl;
}