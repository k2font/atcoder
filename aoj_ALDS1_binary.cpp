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
  int n; cin >> n;
  vector<int> S(n); REP(i, n) cin >> S[i];
  int q; cin >> q;
  vector<int> T(q); REP(i, q) cin >> T[i];
  int ans = 0;
  REP(i, q) {
    int ng = -1;
    int ok = n; // 配列Sの末尾
    while(abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      if(T[i] <= S[mid]) ok = mid;
      else ng = mid;
    }
    //cout << ok << " " << S[ok] << endl;
    if(S[ok] == T[i]) ans++;
  }
  cout << ans << endl;
}