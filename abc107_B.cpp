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
  vector<string> a(H); REP(i, H) cin >> a[i];
  vector<string> tmp;
  int cnt = 0;
  REP(i, H) {
    int t = 0;
    REP(k, W) {
      if(a[i][k] == '.') t++;
    }
    if(t != W) {
      tmp.push_back(a[i]);
    } else {
      cnt++;
    }
  }
  vector<string> tmp2(H - cnt);
  REP(i, W) {
    int t = 0;
    REP(k, H - cnt) {
      if(tmp[k][i] == '.') t++;
    }
    if(t != H - cnt) {
      REP(m, H - cnt) {
        tmp2[m].push_back(tmp[m][i]);
      }
    }
  }
  REP(i, tmp2.size()) {
    REP(k, tmp2[i].size()) {
      cout << tmp2[i][k];
    }
    cout << endl;
  }
}