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
  int A, B, C; cin >> A >> B >> C;
  int X, Y; cin >> X >> Y;
  int a, b;
  ll ans = 1000000000000000000;
  for(int i = 0; i <= max(X, Y); ++i) {
    a = i; b = i;
    int tmp_a = 0; int tmp_b = 0;
    if(X > a) tmp_a = X - a;
    if(Y > b) tmp_b = Y - b;
    ll tmp = C * i * 2 + A * tmp_a + B * tmp_b;
    if(ans > tmp) ans = tmp;
  }
  cout << ans << endl;
}