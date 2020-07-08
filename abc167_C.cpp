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
  int N, M, X; cin >> N >> M >> X;
  vector<int> C(N);
  vector<vector<int>> A(N, vector<int>(M));
  REP(i, N) {
    cin >> C[i];
    REP(k, M) {
      cin >> A[i][k];
    }
  }
  ll ans = pow(10, 17);
  vector<int> tmp(M);
  for(int bit = 0; bit < (1 << N); ++bit) {
    ll sum = 0;
    REP(i, M) tmp[i] = 0;
    for(int i = 0; i < N; ++i) {
      if(bit & (1 << i)) {
        sum += C[i];
        REP(k, M) {
          tmp[k] += A[i][k];
        }
      }
    }
    REP(i, M) {
      if(tmp[i] < X) break;
      if(i == M - 1 && ans > sum) {
        ans = sum;
      }
    }
  }
  if(ans == pow(10, 17)) cout << -1 << endl;
  else cout << ans << endl;
}