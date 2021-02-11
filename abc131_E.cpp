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
  int N, K; cin >> N >> K;
  vector<pair<int, int>> ans;
  if((N - 1) * (N - 2) * 0.5 < K) {
    cout << -1 << endl;
    return 0;
  } else {
    REP(i, N - 1) ans.emplace_back(i + 1, N);
    int rem = (N - 1) * (N - 2) * 0.5 - K;
    int ci = 1; int cj = 2;
    REP(i, rem) {
      ans.emplace_back(ci, cj);
      ++cj;
      if(cj == N) {
        ci++; cj = ci + 1;
      }
    }
  }
  cout << ans.size() << endl;
  REP(i, ans.size()) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
