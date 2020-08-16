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
  int N; cin >> N;
  vector<ll> L(N); REP(i, N) cin >> L[i];
  int ans = 0;
  for(int i = 0; i < N; ++i) {
    for(int k = i + 1; k < N; ++k) {
      for(int m = k + 1; m < N; ++m) {
        if(L[i] == L[k] || L[i] == L[m] || L[k] == L[m]) continue;
        ll a = L[i] + L[k];
        ll b = L[m] + L[k];
        ll c = L[i] + L[m];
        if(a > L[m] && b > L[i] && c > L[k]) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}