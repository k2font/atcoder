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
  ll d; cin >> d;
  int n, m; cin >> n >> m;
  vector<int> D(n + 1); D[0] = 0;
  REP(i, n - 1) {
    cin >> D[i];
  }
  D[n - 1] = d;
  vector<int> k(m); REP(i, m) cin >> k[i];
  ll ans = 0;
  sort(all(D));
  for(int i = 0; i < m; ++i) {
    int ng = -1;
    int ok = D.size();
    while(abs(ng - ok) > 1) {
      int mid = (ng + ok) / 2;
      if(k[i] <= D[mid]) ok = mid;
      else ng = mid;
    }
    ans += min(abs(D[ng] - k[i]), abs(D[ok] - k[i]));
  }
  cout << ans << endl;
}
