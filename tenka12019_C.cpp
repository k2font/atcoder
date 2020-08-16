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
  string S; cin >> S;
  ll ans = 0;
  ll b_l = 0; ll w_l = 0; ll b_r = 0; ll w_r = 0;
  REP(i, N) {
    if(S[i] == '#') b_l++;
    if(S[i] == '.') w_l++;
  }
  for(int i = N; i >= 0; --i) {
    if(i == N) {
      ans = b_l;
      continue;
    }
    int tmp = 0;
    if(S[i] == '#') {
      b_l--; b_r++;
      tmp = b_l + w_r;
    } else {
      w_l--; w_r++;
      tmp = b_l + w_r;
    }
    if(ans > tmp) ans = tmp;
  }
  cout << ans << endl;
}