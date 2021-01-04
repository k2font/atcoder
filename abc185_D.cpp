#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
struct edge {
  ll to, cost;
};

int main() {
  ll N; cin >> N;
  int M; cin >> M;
  vector<ll> A(M); REP(i, M) cin >> A[i];
  ll min_n = 10000000000000000;
  if(N == M) {
    cout << 0 << endl;
    return 0;
  }
  if(M == 0) {
    cout << 1 << endl;
    return 0;
  }
  sort(all(A));
  if(A[0] != 1) min_n = min(min_n, A[0] - 1);
  REP(i, M - 1) {
    if(A[i + 1] - 1 != A[i]) min_n = min(min_n, A[i + 1] - A[i] - 1);
  }
  if(A[M - 1] != N) min_n = min(min_n, N + 1 - A[M - 1] - 1);

  ll ans = 0;
  if(A[0] != 1) ans += ceil((double)(A[0] - 1) / (double)min_n);
  REP(i, M - 1) {
    ans += ceil((double)(A[i + 1] - A[i] - 1) / (double)min_n);
  }
  if(A[M - 1] != N) ans += ceil((double)(N + 1 - A[M - 1] - 1) / (double)min_n);
  cout << ans << endl;
}
