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
  int H, W; cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  REP(i, H) {
    REP(k, W) {
      cin >> A[i][k];
    }
  }

  int min_n = 100000;
  REP(i, H) {
    REP(k, W) {
      min_n = min(min_n, A[i][k]);
    }
  }

  int ans = 0;
  REP(i, H) {
    REP(k, W) {
      ans += (A[i][k] - min_n);
    }
  }
  cout << ans << endl;
}
