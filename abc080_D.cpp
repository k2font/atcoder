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
  int C; cin >> C;
  vector<int> s(N), t(N), c(N);
  REP(i, N) {
    cin >> s[i] >> t[i] >> c[i];
    s[i]--; t[i]--; c[i]--;
  }
  int sizet = pow(10, 5) + 10;
  vector<vector<int>> p(C, vector<int>(sizet));
  REP(i, N) {
    p[c[i]][s[i]]++; p[c[i]][t[i] + 1]--;
  }
  REP(i, C) {
    REP(k, sizet) {
      p[i][k + 1] += p[i][k];
    }
  }
  int ans = 0;
  REP(i, sizet) {
    int tmp = 0;
    REP(k, C) {
      if(p[k][i] > 0) tmp++;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}