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
  ll N, M; cin >> N >> M;
  vector<pair<ll, ll>> id(M);
  vector<vector<ll>> tmp(N + 1);
  REP(i, M) {
    ll p, y; cin >> p >> y;
    id[i] = make_pair(p, y);
  }
  REP(i, M) {
    tmp[id[i].first].push_back(id[i].second);
  }
  REP(i, N + 1) {
    sort(all(tmp[i]));
  }
  for(ll i = 0; i < M; ++i) {
    int ans = lower_bound(all(tmp[id[i].first]), id[i].second) - tmp[id[i].first].begin();
    cout << setw(6) << setfill('0') << id[i].first << setw(6) << setfill('0') << (ans + 1) << endl;
  }
}