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

// 最大公約数
int gcd(int a, int b) {
  if (a % b == 0) {
    return(b);
  } else {
    return(gcd(b, a % b));
  }
}
int main() {
  ll N, M; cin >> N >> M;
  int a = M / N; int b = M % N;
  vector<ll> tmp;
  REP(i, N) {
    tmp.push_back(a);
  }
  tmp[0] += b; ll ans = 0;
  if(N != 1) ans = gcd(tmp[0], tmp[1]);
  else ans = tmp[0];
  for(int i = 2; i < N ; ++i) {
    ans = gcd(ans, tmp[i]);
  }
  cout << ans << endl;
}
