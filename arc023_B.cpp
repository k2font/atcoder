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
  int R, C, D; cin >> R >> C >> D;
  vector<vector<ll>> A(R, vector<ll>(C));
  REP(i, R) {
    REP(k, C) {
      cin >> A[i][k];
    }
  }
  vector<vector<int>> tmp(R, vector<int>(C, -1));
  queue<pair<pair<ll, ll>, int>> q; q.push(make_pair(make_pair(0, 0), 0)); tmp[0][0] = 0;
  while(!q.empty()) {
    auto p = q.front(); q.pop();
    int num = p.second;
    if(num == D) break;
    for(int i = 0; i < 4; ++i) {
      int x = p.first.first + dx[i]; int y = p.first.second + dy[i];
      if(x < 0 || x >= R || y < 0 || y >= C) continue;
      if(tmp[x][y] != -1) continue;
      tmp[x][y] = num + 1;
      q.push(make_pair(make_pair(x, y), num + 1)); 
    }
  }
  ll ans = 0;
  REP(i, R) {
    REP(k, C) {
      // cout << (D % 2 == tmp[i][k] % 2) << endl;
      if(D % 2 == tmp[i][k] % 2 && tmp[i][k] != -1) {
        ans = max(ans, A[i][k]);
      }
    }
  }
  cout << ans << endl;
}