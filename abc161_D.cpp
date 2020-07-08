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

vector<ll> A;
void dfs(string s) {
  // 終了条件
  if(s.size() == 11) {
    return;
  }

  // 判定
  A.push_back(stoll(s));

  // 再帰
  int a = char_to_int(s[s.size() - 1]);
  for(int i = a - 1; i <= a + 1; ++i) {
    if(i < 0 || i >= 10) continue;
    s.push_back('0' + i);
    dfs(s);
    s.pop_back();
  }
}

int main() {
  int K; cin >> K;
  for(int i = 1; i <= 9; ++i) {
    dfs(to_string(i));
  }
  sort(all(A));
  cout << A[K - 1] << endl;
}