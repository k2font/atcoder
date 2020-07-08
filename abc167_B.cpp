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
  ll A, B, C, K; cin >> A >> B >> C >> K;
  ll ans = 0;
  ll tmp = K;
  if(A < tmp && tmp > 0) {
    tmp = tmp - A;
    ans += A;
  } else {
    ans += tmp;
    tmp = 0;
  }

  if(B < tmp && tmp > 0) {
    tmp = tmp - B;
  } else {
    tmp = 0;
  }

  if(C < tmp && tmp > 0) {
    tmp = tmp - C;
    ans -= C;
  } else {
    ans -= tmp;
    tmp = 0;
  }

  cout << ans << endl;
}
