#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}; // ここがおかしい
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
  int x, y; cin >> x >> y; --x; --y;
  string W; cin >> W;
  vector<string> c(9); REP(i, 9) cin >> c[i];
  map<string, int> t;
  t["U"] = 4; t["RU"] = 3; t["R"] = 2; t["RD"] = 1;
  t["D"] = 0; t["LD"] = 7; t["L"] = 6; t["LU"] = 5; 
  int d_x = dx[t[W]]; int d_y = dy[t[W]];
  vector<char> ans; queue<pair<int, int>> q; q.emplace(x, y);
  while(ans.size() < 4) {
    auto p = q.front(); q.pop();
    int fy = 0; int fx = 0;
    if(p.second >= 9) {
      p.second -= 2; fy = 1;
    }
    if(p.second < 0) {
      p.second += 2; fy = 1;
    }
    if(p.first >= 9) {
      p.first -= 2; fx = 1;
    }
    if(p.first < 0) {
      p.first += 2; fx = 1;
    }
    ans.push_back(c[p.second][p.first]);
    if(fy == 1) d_y *= -1;
    if(fx == 1) d_x *= -1;
    q.emplace(p.first + d_x, p.second + d_y);
  }
  REP(i, 4) cout << ans[i];
  cout << endl;
}
