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
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

int main() {
  int N, Q; cin >> N >> Q;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  map<ll, ll> B, D;
  vector<ll> C;
  REP(i, N) {
    if(B[A[i] - (i + 1)] == 0) B[A[i] - (i + 1)] = A[i];
    D[A[i] - (i + 1)] = A[i];
    C.push_back(A[i] - (i + 1));
  }
  REP(i, Q) {
    ll K; cin >> K;
    ll sz = A[N - 1] - N;
    ll k = upper_bound(A.begin(), A.end(), K) - A.begin();
    if(K <= sz) cout << K + k << endl;
    else cout << N + K << endl;
  }
}