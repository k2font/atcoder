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
  int N; cin >> N;
  vector<vector<ll>> C(N, vector<ll>(N));
  REP(i, N) {
    REP(k, N) {
      cin >> C[i][k];
    }
  }
  string ans = "Yes"; vector<ll> A(N, -1), B(N, -1);
  ll minn = 2e18;
  REP(i, N) minn = min(minn, C[i][0]);
  REP(i, N) A[i] = C[i][0] - minn;
  REP(i, N) B[i] = C[0][i] - A[0];

  // Noになるかどうか判定するパート
  REP(i, N) {
    REP(k, N) {
      if(C[i][k] != A[i] + B[k]) ans = "No";
    }
  }

  if(ans == "No") {
    cout << ans << endl;
  } else {
    cout << ans << endl;
    REP(i, N) cout << A[i] << " ";
    cout << endl;
    REP(i, N) cout << B[i] << " ";
    cout << endl;
  }
}