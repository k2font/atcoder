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
  int N, K; cin >> N >> K;
  ll mot = pow(N, 3);
  ll chi = 0;
  for(int i = 1; i <= K; ++i) {
    bool flag = false;
    int cnt = 1;
    if(i == K) cnt++;
    if(cnt == 1) {
      chi += 6 * (N - K);
      chi += 3;
    } else if(cnt == 2) {
      chi += 3 * (N - K);
      chi += 1;
    }
  }
  double ans = (double)chi / (double)mot;
  cout << fixed << setprecision(20) << ans << endl;
}