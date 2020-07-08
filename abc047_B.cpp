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
  int W, H, N; cin >> W >> H >> N;
  vector<int> x(N), y(N), a(N); REP(i, N) cin >> x[i] >> y[i] >> a[i];
  vector<int> x_vec(W), y_vec(H);
  REP(i, W) x_vec[i] = 0;
  REP(i, H) y_vec[i] = 0;
   
  for(int i = 0; i < N; ++i) {
    if(a[i] == 1) {
      for(int k = 0; k < x[i]; ++k) {
        x_vec[k] = 1;
      }
    }

    if(a[i] == 2) {
      for(int k = x[i]; k < W; ++k) {
        x_vec[k] = 1;
      }
    }

    if(a[i] == 3) {
      for(int k = 0; k < y[i]; ++k) {
        y_vec[k] = 1;
      }
    }

    if(a[i] == 4) {
      for(int k = y[i]; k < H; ++k) {
        y_vec[k] = 1;
      }
    }
  }

  int res_x = 0, res_y = 0;
  for(int i = 0; i < W; ++i) {
    if(x_vec[i] == 0) res_x++;
  }
  for(int i = 0; i < H; ++i) {
    if(y_vec[i] == 0) res_y++;
  }
  cout << res_x * res_y << endl;
}
