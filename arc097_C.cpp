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
  string s; cin >> s;
  int K; cin >> K; map<string, int> m;
  for(int i = 0; i < s.size(); ++i) {
    string t = char_to_string(s[i]); m[t]++;
    for(int k = i + 1; k < s.size(); ++k) {
      t += s[k];
      m[t]++;
      if(t.size() == K) break;
    }
  }
  vector<string> ans;
  for(auto x : m) {
    ans.push_back(x.first);
  }
  sort(all(ans));
  cout << ans[K - 1] << endl;
}
