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

int digit(int n) {
  int res = 0;
  while(n >= 1) {
    res += (n % 10);
    n /= 10;
  }
  return res;
}

int main() {
  int N; cin >> N;
  int ans = pow(10, 9) + 10;
  int a, b;
  for(int i = 1; i < N; ++i) {
    a = i; b = N - i;
    int res = digit(a) + digit(b);
    if(ans > res) ans = res;
  }
  cout << ans << endl;
}