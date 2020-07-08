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

int w, h;
vector<vector<int>> c;
int ans;

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

void dfs(int _x, int _y) {
  // 訪問したマスは0に変えて
  c[_x][_y] = 0;
  // 次行くマスを決めて
  for(int i = 0; i < 8; ++i) {
    if(_x + dx[i] < 0 || _x + dx[i] >= h || _y + dy[i] < 0 || _y + dy[i] >= w) continue;
    if(c[_x + dx[i]][_y + dy[i]] == 1) dfs(_x + dx[i], _y + dy[i]);
  }
}

int main() {
  while(true) {
    cin >> w >> h;
    c.resize(h);
    if(w == 0 && h == 0) break;
    REP(k, h) {
      REP(m, w) {
        int C; cin >> C;
        c[k].push_back(C);
      }
    }
    ans = 0;
    REP(i, h) {
      REP(k, w) {
        if(c[i][k] == 1) {
          dfs(i, k);
          ans++;
        }
      }
    }
    cout << ans << endl;
    c.clear();
  }
}
