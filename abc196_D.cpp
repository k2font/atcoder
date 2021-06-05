#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
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

ll H, W, A, B;
bool tmp[16][16];

int ans = 0;
ll dfs(int x, int y, int a) {
  if(H == y) return a == 0;

  if(W == x) return dfs(0, y + 1, a);

  if(tmp[y][x] == true) return dfs(x + 1, y, a);

  int res = 0;

  // 縦
  if(y + 1 < H && !tmp[y + 1][x] && 0 < a) {
    tmp[y][x] = tmp[y + 1][x] = true;
    res += dfs(x + 1, y, a - 1);
    tmp[y][x] = tmp[y + 1][x] = false;
  }

  // 横
  if(x + 1 < W && !tmp[y][x + 1] && 0 < a) {
    tmp[y][x] = tmp[y][x + 1] = true;
    res += dfs(x + 1, y, a - 1);
    tmp[y][x] = tmp[y][x + 1] = false;
  }

  // 何も置かない
  res += dfs(x + 1, y, a);

  return res;
}

int main() {
  cin >> H >> W >> A >> B;
  cout << dfs(0, 0, A) << endl;
}