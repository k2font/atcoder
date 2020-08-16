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

int main() {
  int N, K; cin >> N >> K;
  string S; cin >> S;
  vector<int> tmp; int cnt = 0;

  if(S[0] == '0') tmp.push_back(0);
  REP(i, N) {
    cnt++;
    if(S[i] != S[i + 1]) {
      tmp.push_back(cnt);
      cnt = 0;
    }
  }
  if(S[N - 1] == '0') tmp.push_back(0);
  
  vector<int> res(tmp.size() + 1, 0);
  REP(i, tmp.size()) res[i + 1] = res[i] + tmp[i]; // 累積

  int ans = 0;
  for(int i = 0; i < res.size(); i = i + 2) {
    int right = i + (2 * K + 1);
    if(right >= res.size()) right = res.size() - 1;
    ans = max(ans, (res[right] - res[i]) );
  }
  cout << ans << endl;
}