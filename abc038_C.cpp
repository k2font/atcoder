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
  int N; cin >> N;
  vector<int> a(N); REP(i, N) cin >> a[i];
  vector<vector<int>> b(N + 1);
  int k = 0;
  REP(i, N - 1) {
    if(a[i] < a[i + 1]) {
      b[k].push_back(a[i]);
    } else if(a[i] >= a[i + 1]) {
      b[k].push_back(a[i]);
      k++;
    }
    if(i == N - 2) {
      if(a[i] < a[i + 1]) {
        b[k].push_back(a[i + 1]);
      } else if(a[i] >= a[i + 1]) {
        k++;
        b[k].push_back(a[i + 1]);
      }
    }
  }
  ll ans = 0;
  REP(i, N + 1) {
    if(b[i].size() == 0) continue;
    int c = b[i].size();
    ans = ans + 0.5 * c * (c - 1) + c;
  }
  cout << ans << endl;
}