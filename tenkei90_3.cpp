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
  vector<vector<ll>> tree(N);
  REP(i, N - 1) {
    ll A, B; cin >> A >> B;
    A--; B--;
    tree[A].push_back(B);
    tree[B].push_back(A);
  }

  // 0から全方位に最短距離を探索する
  ll res = 0; ll point = -1;
  queue<P> q; q.emplace(0, 0); vector<int> tmp(N, 0);
  while(!q.empty()) {
    auto x = q.front(); q.pop();
    if(tmp[x.first] == 1) continue;
    tmp[x.first] = 1;
    for(int i = 0; i < tree[x.first].size(); ++i) {
      if(res < x.second + 1) {
        res = x.second + 1; point = x.first;
      }
      q.emplace(tree[x.first][i], x.second + 1);
    }
  }

  // 最も端の地点から最も遠い経路を計算する
  ll ans = 0;
  queue<P> q2; q2.emplace(point, 0); vector<int> tmp2(N, 0);
  while(!q2.empty()) {
    auto x = q2.front(); q2.pop();
    if(tmp2[x.first] == 1) continue;
    tmp2[x.first] = 1;
    for(int i = 0; i < tree[x.first].size(); ++i) {
      ans = max(ans, x.second + 1);
      q2.emplace(tree[x.first][i], x.second + 1);
    }
  }
  cout << ans << endl;
}