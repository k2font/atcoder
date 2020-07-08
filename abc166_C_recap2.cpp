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
  vector<ll> H(N); REP(i, N) cin >> H[i];
  vector<ll> A(M), B(M); REP(i, M) cin >> A[i] >> B[i];

  vector<ll> ans(N + 1);
  vector<vector<ll>> vec(N + 1);

  for(int i = 0; i < M; ++i) {
    if(!vector_finder(vec[A[i]], B[i])) {
      vec[A[i]].push_back(B[i]);
      vec[B[i]].push_back(A[i]);
    }
  }

  for(int i = 1; i <= N; ++i) {
    if(vec[i].empty()) {
      ans[i] = -1;
    } else {
      ll tmp = 0;
      for(int k = 0; k < vec[i].size(); ++k) {
        if(tmp < H[vec[i][k] - 1]) tmp = H[vec[i][k] - 1];
      }
      ans[i] = tmp;
    }
  }

  ll cnt = 0;
  for(int i = 1; i <= N; ++i) {
    if(ans[i] == -1) cnt++;
    else if(H[i - 1] > ans[i]) cnt++;
  }

  cout << cnt << endl;
}
