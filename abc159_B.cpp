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
  string S; cin >> S; int N = S.size();
  string s1 = S.substr(0, (S.size() - 1) / 2);
  string s2 = S.substr((S.size() + 3) / 2 - 1, s1.size());
  reverse(s2.begin(), s2.end());
  string ans = "Yes";
  if(s1 != s2) ans = "No";
  reverse(s2.begin(), s2.end());
  for(int i = 0; i < s1.size(); ++i) {
    if(s1[i] != s1[s1.size() - i - 1]) ans = "No";
  }
  for(int i = 0; i < s2.size(); ++i) {
    if(s2[i] != s2[s2.size() - i - 1]) ans = "No";
  }
  cout << ans << endl;
}