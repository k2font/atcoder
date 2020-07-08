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

int N; string S;
ll ans = 0;
void dfs(vector<int> &A) {
  if(A.size() == 3) {
    int tmp = 0;
    for(int i = 0; i < S.size(); i++) {
      if(char_to_int(S[i]) == A[tmp]) {
        tmp++;
      }
      if(tmp == 3) {
        ans++;
        return;
      }
      if(i == S.size() - 1) {
        return;
      }
    }
  }

  for(int i = 0; i <= 9; ++i) {
    A.push_back(i);
    dfs(A);
    A.pop_back();
  }
}

int main() {
  cin >> N; cin >> S;
  vector<int> A;
  dfs(A);
  cout << ans << endl;
}