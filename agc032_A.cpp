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
  int N; cin >> N;
  vector<int> b(N); REP(i, N) cin >> b[i];
  vector<int> a; bool flag = false;
  for(int i = b.size() - 1; i >= 0; --i) {
    if(i + 1 == b[i]) {
      a.push_back(b[i]);
      b.erase(b.begin() + i);
      i = b.size();
    }
    if(b.size() != 0 && i == 0) {
      flag = true;
    }
  }
  reverse(all(a));
  if(flag) cout << -1 << endl;
  else REP(i, a.size()) cout << a[i] << endl;
}
