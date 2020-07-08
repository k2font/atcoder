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
int vector_finder(std::vector<int> vec, int number) {
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
  string S; cin >> S;
  string ans = "Yes";
  string a = S.substr(0, (S.size() - 1) / 2);
  string b = S.substr((S.size() + 3) / 2 - 1, (S.size() - 1) / 2);

  for(int i = 0; i < a.size()/2; ++i) {
    if(a[i] != a[a.size() - i - 1]) ans = "No";
  }

  for(int i = 0; i < b.size()/2; ++i) {
    if(b[i] != b[b.size() - i - 1]) ans = "No";
  }

  for(int i = 0; i < S.size()/2; ++i) {
    if(S[i] != S[S.size() - i - 1]) ans = "No";
  }

  cout << ans << endl;
}
