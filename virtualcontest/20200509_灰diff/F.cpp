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
  ll N, M; cin >> N >> M;
  vector<ll> H(N); REP(i, N) cin >> H[i];
  vector<ll> A(M), B(M); REP(i, M) cin >> A[i] >> B[i];

  vector<ll> vec(N + 1); REP(i, N + 1) vec[i] = 0;
  vector<vector<ll>> tmp(N + 1);

  for(int i = 0; i < M; ++i) {
    if(!vector_finder(tmp[A[i]], B[i])) {
      tmp[A[i]].push_back(B[i]);
      tmp[B[i]].push_back(A[i]);
    }
  }

  for(int i = 1; i <= N; ++i) {
    if(!tmp[i].empty()) {
      int tmp_num = 0;
      for(int k = 0; k < tmp[i].size(); ++k) {
        if(tmp_num < H[tmp[i][k] - 1]) tmp_num = H[tmp[i][k] - 1];
      }
      vec[i] = tmp_num;
    } else {
      vec[i] = -1;
    }
  }

  int ans = 0;
  for(int i = 1; i <= N; ++i) {
    if(H[i - 1] > vec[i] || vec[i] == -1) {
      ans++;
    }
  }

  cout << ans << endl;
}
