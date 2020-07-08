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
  string S; cin >> S;
  string T; cin >> T;

  vector<pair<char, char>> sp(S.size());
  vector<pair<char, char>> tp(S.size());
  REP(i, S.size()) {
    sp[i] = make_pair(S[i], T[i]);
    tp[i] = make_pair(T[i], S[i]);
  }
  sort(all(sp));
  sort(all(tp));

  string ans = "Yes";
  for(int i = 0; i < S.size() - 1; ++i) {
    if(sp[i].first == sp[i + 1].first) {
      if(sp[i].second != sp[i + 1].second) {
        ans = "No";
      }
    }

    if(tp[i].first == tp[i + 1].first) {
      if(tp[i].second != tp[i + 1].second) {
        ans = "No";
      }
    }
  }
  cout << ans << endl;
}
