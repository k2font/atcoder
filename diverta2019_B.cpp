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
  int R, G, B, N; cin >> R >> G >> B >> N;
  ll ans = 0;
  int loop = 3000;
  for(int i = 0; i <= loop; ++i) {
    if(R * i > N) break;
    for(int k = 0; k <= loop; ++k) {
      if(R * i + G * k > N) break;
      ll tmp = R * i + G * k;
      if((N - tmp) % B == 0) ans++;
    }
  }
  cout << ans << endl;
}
