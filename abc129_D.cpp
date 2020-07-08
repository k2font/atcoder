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
struct edge {
  ll to, cost;
};

int main() {
  int H, W; cin >> H >> W;
  vector<string> S(H); REP(i, H) cin >> S[i];
  vector<vector<int>> A(H, vector<int>(W, 0));
  vector<vector<int>> B(H, vector<int>(W, 0));
  for(int i = 0; i < H; ++i) {
    int tmp = 0;
    int start = 0;
    for(int k = 0; k < W; ++k) {
      if(S[i][k] == '.') {
        tmp++;
      } else if(S[i][k] == '#') {
        for(int m = start; m < k; ++m) {
          A[i][m] = tmp;
        }
        start = k + 1;
        tmp = 0;
      }
      if(k == W - 1) {
        for(int m = start; m <= k; ++m) {
          A[i][m] = tmp;
        }
      }
    }
  }
  
  for(int k = 0; k < W; ++k) {
    int tmp = 0;
    int start = 0;
    for(int i = 0; i < H; ++i) {
      if(S[i][k] == '.') {
        tmp++;
      } else if(S[i][k] == '#') {
        for(int m = start; m < i; ++m) {
          B[m][k] = tmp;
        }
        start = i + 1;
        tmp = 0;
      }
      if(i == H - 1) {
        for(int m = start; m <= i; ++m) {
          B[m][k] = tmp;
        }
      }
    }
  }

  int ans = 0;
  int tmp = 0;
  REP(i, H) {
    tmp = 0;
    REP(k, W) {
      tmp = A[i][k] + B[i][k] - 1;
      if(ans < tmp) ans = tmp;
    }
  }
  cout << ans << endl;
}