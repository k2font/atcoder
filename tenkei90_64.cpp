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
  ll N, Q; cin >> N >> Q;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> L(Q), R(Q), V(Q); REP(i, Q) cin >> L[i] >> R[i] >> V[i];
  ll ans = 0;
  REP(i, N - 1) {
    ans += abs(A[i] - A[i + 1]);
  }

  REP(i, Q) {
    ll tmpl = 0; 
    ll tmpl2 = 0;
    if(L[i] != 1){
      tmpl = abs(A[L[i] - 2] - A[L[i] - 1]);
      tmpl2 = abs(A[L[i] - 2] - (A[L[i] - 1] + V[i]));
      A[L[i] - 1] += V[i];
    }
    ll tmpr = 0;
    ll tmpr2 = 0;
    if(R[i] != N) {
      tmpr = abs(A[R[i] - 1] - A[R[i]]);
      tmpr2 = abs(A[R[i] - 1] + V[i] - A[R[i]]);
      A[R[i] - 1] += V[i];
    }
    ans += (tmpl2 - tmpl); ans += (tmpr2 - tmpr);
    cout << ans << endl;
  }
}