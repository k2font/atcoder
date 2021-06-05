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
  vector<ll> A(N); REP(i, N) cin >> A[i];
  ll Q; cin >> Q;
  vector<ll> B(Q); REP(i, Q) cin >> B[i];
  sort(all(A));
  REP(i, Q) {
    ll l = lower_bound(all(A), B[i]) - A.begin();
    if(l - 1 >= 0) cout << min(abs(A[l - 1] - B[i]), min(abs(A[l] - B[i]), abs(A[l + 1] - B[i]))) << endl;
    else cout << min(abs(A[l] - B[i]), abs(A[l + 1] - B[i])) << endl;
  }
}