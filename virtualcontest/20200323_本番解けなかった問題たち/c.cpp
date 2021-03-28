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
  ll tmp = abs(A[0]);
  REP(i, N - 1) {
    tmp += abs(A[i] - A[i + 1]);
  }
  tmp += abs(A[N - 1]); // 帰り
  REP(i, N) {
    ll ans = tmp;
    if(i == 0) {
      ans -= abs(0 - A[i]); ans -= abs(A[i] - A[i + 1]);
      ans += abs(0 - A[i + 1]);
    } else if(i == N - 1) {
      ans -= abs(0 - A[i]); ans -= abs(A[i] - A[i - 1]);
      ans += abs(0 - A[i - 1]);
    } else {
      ans -= abs(A[i - 1] - A[i]); ans -= abs(A[i] - A[i + 1]);
      ans += abs(A[i - 1] - A[i + 1]);
    }
    cout << ans << endl;
  }
}