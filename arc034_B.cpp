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

ll digits(ll num) {
  ll tmp = 0;
  while(num > 0) {
    ll a = num % 10;
    tmp += a;
    num = num / 10;
  }
  return tmp;
}

int main() {
  ll N; cin >> N;
  vector<ll> ans;
  for(ll i = N - 153; i <= N; ++i) {
    if(digits(i) == N - i) ans.push_back(i);
  }
  cout << ans.size() << endl;
  REP(i, ans.size()) {
    cout << ans[i] << endl;
  }
}