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

int N = 5;
vector<int> tmp(N);
vector<int> ans;
void dfs(vector<ll> &A, int select) {
  if(A.size() == 3) {
    ans.push_back(A[0] + A[1] + A[2]);
    return;
  }

  for(int i = 0; i < 5; ++i) {
    if(A.size() == 1 && A[0] == tmp[i]) continue;
    if(A.size() == 2 && (tmp[i] == A[0] || A[1] == tmp[i])) {
      continue;
    }
    A.push_back(tmp[i]);
    dfs(A, tmp[i]);
    A.pop_back();
  }
}

int main() {
  REP(i, 5) cin >> tmp[i];
  vector<ll> A;
  dfs(A, 0);
  sort(all(ans));
  int a = 1;
  for(int i = ans.size() - 1; i >= 1; --i) {
    if(ans[i] != ans[i - 1]) a++;
    if(a == 3) {
      cout << ans[i - 1] << endl;
      break;
    }
  }
}