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
struct edge {
  ll to, cost;
};

int main() {
  ll N, M, K; cin >> N >> M >> K;
  vector<ll> A(N), B(M); REP(i, N) cin >> A[i];
  REP(i, M) cin >> B[i];
  ll sum = 0;
  ll ans = 0;
  vector<ll> C(M + 1), D(N + 1); C[0] = 0; D[0] = 0;
  for(int i = 1; i < N + 1; ++i) D[i] = D[i - 1] + A[i - 1];
  for(int i = 1; i < M + 1; ++i) C[i] = C[i - 1] + B[i - 1];
  for(int i = 0; i <= N; ++i) {
    sum = D[i];
    if(sum > K) break;
    ll target = K - sum;
    ll ng = -1;
    ll ok = M;
    while(abs(ok - ng) > 1) {
      ll mid = (ok + ng) / 2;
      if(C[mid] >= target) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    ll tmp;
    //cout << ok << " " << i << endl;
    if(C[ok] > target) tmp = (ok - 1) + i;
    else tmp = ok + i;
    if(tmp > ans) ans = tmp;
  }
  cout << ans << endl;
}