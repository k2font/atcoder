#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
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
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int H, W;
vector<string> c;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
bool flag = false;
vector<vector<int>> dfs_f;

void dfs(int x, int y, int b_x, int b_y) {
  if(b_x != -1 || b_y != -1) dfs_f[b_x][b_y] = 1;
  // 終了条件
  if(c.at(x).at(y) == 'g') {
    flag = true;
    return;
  }

  if(c.at(x).at(y) == '#') {
    return;
  }

  // 再帰(4方向)
  for(int i = 0; i < 4; ++i) {
    if(x + dx.at(i) < 0 || x + dx.at(i) >= H || y + dy.at(i) < 0 || y + dy.at(i) >= W) {
      continue;
    }
    if(b_x == x + dx.at(i) && b_y == y + dy.at(i)) {
      continue;
    }
    if(dfs_f[x + dx.at(i)][y + dy.at(i)] == 1) {
      continue;
    }
    dfs(x + dx.at(i), y + dy.at(i), x, y);
  }
}

int main() {
  cin >> H >> W;
  c.resize(H);
  dfs_f.resize(H);
  REP(i, H) {
    REP(k, W) {
      dfs_f[i].push_back(0);
    }
  }
  REP(i, H) cin >> c[i];
  int ai, ak;
  REP(i, H) {
    REP(k, W) {
      if(c[i][k] == 's') {
        ai = i; ak = k;
        break;
      }
    }
  }
  dfs(ai, ak, -1, -1);
  if(flag == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}