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
  vector<pair<ll, ll>> p;
  REP(i, N) {
    ll x, y; cin >> x >> y;
    p.push_back(make_pair(x, y));
  }
  sort(all(p));
  map<pair<ll, ll>, ll> m;
  REP(i, N) {
    REP(k, N) {
      if(i == k) continue;
      auto x = make_pair(p[i].first - p[k].first, p[i].second - p[k].second);
      m[x]++;
    }
  }
  ll a = 0;
  for(auto x : m) {
    if(a < x.second) a = x.second;
  }
  cout << N - a << endl;
}