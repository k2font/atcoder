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
    int N, X, Y; cin >> N >> X >> Y;
    vector<int> ans(N + 1);
    for(int i = 1; i <= N; ++i) {
        for(int k = 1; k <= N; ++k) {
            if(i == k) continue;
            int tmp = min(k - i, abs(X - i) + 1 + abs(Y - k));
            if(tmp < 0) continue;
            ans.at(tmp)++;
        }
    }
    for(int i = 1; i < N; ++i) {
        cout << ans.at(i) << endl;
    }
}