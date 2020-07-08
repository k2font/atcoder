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

int N;
vector<string> parts = {"a", "b", "c"};
vector<string> ans;
void dfs(vector<string> &A) {
  if(A.size() == N) {
    string a = "";
    REP(i, A.size()) a += A[i];
    ans.push_back(a);
    return;
  }

  for(int i = 0; i < parts.size(); ++i) {
    A.push_back(parts[i]);
    dfs(A);
    A.pop_back();
  }
}

int main() {
  cin >> N;
  vector<string> A;
  dfs(A);
  sort(all(ans));
  REP(i, ans.size()) cout << ans[i] << endl;
}