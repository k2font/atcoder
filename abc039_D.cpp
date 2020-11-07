#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int, int>;
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

const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}; 

int main() {
  int H, W; cin >> H >> W;
  vector<string> S(H); REP(i, H) cin >> S[i];
  // 与えられた画素データから変換前画像を作成する
  // 周囲8マスがすべて黒なら、そのマスは変換前も黒である。
  vector<string> before(H), after(H);
  before = S;
  REP(i, H) {
    REP(k, W) {
      REP(m, 8) {
        int x = i + dx[m]; int y = k + dy[m];
        if(x < 0 || x >= H) continue;
        if(y < 0 || y >= W) continue;
        if(S[x][y] == '.') break;
        if(m == 7) {
          REP(p, 8) {
            int x = i + dx[p]; int y = k + dy[p];
            if(x < 0 || x >= H) continue;
            if(y < 0 || y >= W) continue;
            before[x][y] = '.';
          }
        }
      }
    }
  }

  // 最後に、完成した変換前画像に変換を施し、与えられた画像と一致したらpossible。
  
}