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
  REP(i, H) {
    string t = "";
    REP(k, W) t += '.';
    before[i] = t; after[i] = t;
  }
  REP(i, H) {
    REP(k, W) {
      bool f = false;
      if(S[i][k] == '.') continue;
      REP(m, 8) {
        int x = i + dx[m]; int y = k + dy[m];
        if(x < 0 || x >= H || y < 0 || y >= W) continue;
        if(S[x][y] == '.') {
          f = true;
          break;
        }
      }
      if(f == false) {
        before[i][k] = '#';
      }
    }
  }

  // 最後に、完成した変換前画像に変換を施し、与えられた画像と一致したらpossible。
  bool f = false;
  REP(i, H) {
    REP(k, W) {
      if(before[i][k] == '#') {
        after[i][k] = '#';
        REP(m, 8) {
          int x = i + dx[m]; int y = k + dy[m];
          if(x < 0 || x >= H || y < 0 || y >= W) continue;
          after[x][y] = '#';
        }
      }
    }
  }
  REP(i, H) {
    REP(k, W) {
      if(after[i][k] != S[i][k]) f = true;
    }
  }

  if(f == true) {
    cout << "impossible" << endl;
  } else {
    cout << "possible" << endl;
    REP(i, H) {
      REP(k, W) {
        cout << before[i][k];
      }
      cout << endl;
    }
  }
}