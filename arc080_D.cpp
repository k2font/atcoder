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
  int N; cin >> N;
  vector<int> a(N); REP(i, N) cin >> a[i];
  int cnt = 0, num = 0, k = 0;
  vector<deque<int>> ans(H);
  bool flag = true;
  while(true) {
    if(flag == true) {
      ans[cnt/W].push_back(k + 1);
    } else if(flag == false) {
      ans[cnt/W].push_front(k + 1);
    }
    cnt++; num++;
    if(cnt % W == 0) {
      flag = !flag;
    }
    if(num == a[k]) {
      num = 0;
      k++;
    }
    if(cnt == H * W) break;
  }
  REP(i, H) {
    REP(k, W) {
      cout << ans[i][k] << " ";
    }
    cout << endl;
  }
}