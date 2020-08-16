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
  int H, W, K; cin >> H >> W >> K;
  vector<string> a(H); REP(i, H) cin >> a[i];
  vector<vector<int>> ans(H, vector<int>(W));
  REP(i, H) { // ansの初期化
    REP(k, W) {
      ans[i][k] = 0;
    }
  }
  // 横方向の走査
  int p = 1; bool flag = false;
  REP(i, H) {
    flag = false;
    REP(k, W) { // いちごがあるか？
      if(a[i][k] == '#') flag = true;
    }
    if(flag)  {
      REP(k, W) ans[i][k] = p;
    }
    if(!flag && i == H - 1) p--;
    if(flag && i != H - 1) p++;
  }
  // 縦方向の走査
  bool flag2 = false;
  REP(i, H) {
    flag = false; flag2 = false;
    REP(k, W) {
      if(a[i][k] == '#' && flag == false) {
        flag = true;
      } else if(a[i][k] == '#' && flag == true) {
        flag2 = true; p++;
      }
      if(flag2) ans[i][k] = p;
    }
  }
  // 空白行の帳尻合わせ
  for(int i = H - 1; i >= 0; --i) {
    flag = false;
    REP(k, W) {
      if(a[i][k] == '#') flag = true;
    }
    if(!flag) {
      REP(k, W) {
        if(i != H - 1) ans[i][k] = ans[i + 1][k];
      }
    }
  }
  REP(i, H) {
    flag = false;
    REP(k, W) {
      if(a[i][k] == '#') flag = true;
    }
    if(!flag) {
      REP(k, W) {
        if(i != 0) ans[i][k] = ans[i - 1][k];
        else ans[i][k] = ans[i + 1][k];
      }
    }
  }
  REP(i, H) {
    REP(k, W) {
      cout << ans[i][k] << " ";
    }
    cout << endl;
  }
}