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

int main() {
  int H, W; cin >> H >> W;
  vector<string> A(H); REP(i, H) cin >> A[i];
  vector<int> vec_x = {1, 0, -1, 0};
  vector<int> vec_y = {0, 1, 0, -1};

  string ans = "Possible";
  REP(i, H) {
    REP(k, W) {
      if(i == H - 1 && k == W - 1) {
        if(A[i - 1][k] == '#' && A[i][k - 1] == '#') {
          ans = "Impossible";
        }
        break;
      }
      if(A[i][k] == '#') {
        if(i + 1 >= H) {
          if(A[i][k + 1] == '.') {
            ans = "Impossible";
          }
        } else if(k + 1 >= W) {
          if(A[i + 1][k] == '.') {
            ans = "Impossible";
          }
        } else {
          if((A[i + 1][k] == '#' && A[i][k + 1] == '#') || 
          (A[i + 1][k] == '.' && A[i][k + 1] == '.')) {
            ans = "Impossible";
          }
        }

        if(i - 1 >= 0 && k - 1 >= 0) {
          if(A[i][k - 1] == '#' && A[i - 1][k] == '#') ans = "Impossible";
        }
      }
    }
  }
  cout << ans << endl;
}