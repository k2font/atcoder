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
  vector<string> A(H); REP(i, H) cin >> A[i];
  queue<pair<pair<int, int>, int>> q;
  int ans = 0;
  REP(i, H) {
    REP(k, W) {
      if(A[i][k] == '#') {
        q.push(make_pair(make_pair(i, k), 0));
        A[i][k] = 'a';
      }
    }
  }

  while(!q.empty()) {
    auto x = q.front(); q.pop();
    for(int i = 0; i < 4; ++i) {
      int di = x.first.first + dx[i]; int dk = x.first.second + dy[i];
      if(di < 0 || di >= H) continue;
      if(dk < 0 || dk >= W) continue;
      if(A[di][dk] == 'a') continue;
      A[di][dk] = 'a';
      q.push(make_pair(make_pair(di, dk), x.second + 1));
      ans = max(ans, x.second + 1);
      // cout << di << endl;
    }
  }
  cout << ans << endl;
}