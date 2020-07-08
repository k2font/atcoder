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

const int M = 3;
void dfs(vector<int> &A) {
  // 終了条件
  // 狙った桁が完成したら、何らかの処理を行う
  if(A.size() == 10) {
    for(int i = 0; i < 10; ++i) cout << A[i];
    cout << endl;
    return;
  }

  for(int v = 0; v < M; ++v) {
    A.push_back(v);
    dfs(A);
    A.pop_back();
  }
}

int main() {
  vector<int> A;
  dfs(A);
}
