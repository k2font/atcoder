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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int main() {
  int H, W; cin >> H >> W;
  vector<string> s(H); REP(i, H) cin >> s[i];
  string ans = "Yes";
  for(int i = 0; i < H; ++i) {
    for(int k = 0; k < W; ++k) {
      if(s[i][k] == '#') {
        for(int m = 0; m < 4; ++m) {
          if(i <= 0 || k <= 0 || i >= H - 1 || k >= W - 1) continue;
          if(s[i + dx[m]][k + dy[m]] == '#') break;
          if(m == 3) ans = "No";
        }
      }
    }
  }
  cout << ans << endl;
}
