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
  int N; cin >> N;
  vector<int> A(N+1); for(int i = 1; i <= N; ++i) cin >> A[i];
  vector<int> ans(N + 1, 0);
  for(int i = 1; i <= N; ++i) {
    int j = 0;
    int tmp = i;
    while(true) {
      j++;
      tmp = A[tmp];
      if(tmp == i) {
        ans[i] = j;
        break;
      }
    }
  }
  for(int i = 1; i <= N; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
