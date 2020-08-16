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

ll N, X;
vector<ll> a, p;
ll calc(ll n, ll x) {
  if(n == 0) {
    if(x <= 0) return 0;
    else return 1;
  } else if(x <= 1 + a[n - 1]) {
    return calc(n - 1, x - 1);
  } else {
    return p[n - 1] + 1 + calc(n - 1, x - 2 - a[n - 1]);
  }
}

int main() {
  cin >> N >> X;
  a.push_back(1); p.push_back(1);
  REP(i, N) {
    a.push_back(a[i] * 2 + 3);
    p.push_back(p[i] * 2 + 1);
  }
  ll ans = calc(N, X);
  cout << ans << endl;
}