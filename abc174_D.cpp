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
struct edge {
  ll to, cost;
};

int main() {
  ll N; cin >> N;
  string S; cin >> S;
  int b = 0; int ans = 0; bool flag = false;
  for(int i = N - 1; i >= 0; --i) {
    if(b == i) {
      flag = true;
      break;
    }
    if(S[i] == 'R') {
      while(true) {
        // bがiに衝突したら終了
        if(b == i) {
          flag = true;
          break;
        }
        // Wが見つかったら...
        if(S[b] == 'W') {
          ans++;
          // RとWを交換する
          swap(S[i], S[b]);
          b++;
          if(b == i) {
            flag = true;
            break;
          }
          break;
        }
        b++;
      }
    }
    if(flag == true) break;
  }
  cout << ans << endl;
}