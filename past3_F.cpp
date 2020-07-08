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
  vector<string> a(N); REP(i, N) cin >> a[i];
  vector<char> ans;
  bool flag = false;
  if(N == 1) {
    cout << a[0][0] << endl;;
  } else {
    for(int i = 0; i < N / 2; ++i) {
      flag = false;
      // 先頭から対応する文字列を見て、一致するものがあればそれを入れる
      for(int k = 0; k < a[i].size(); ++k) {
        for(int m = 0; m < a[N - i - 1].size(); ++m) {
          if(a[i][k] == a[N - i - 1][m]) {
            ans.push_back(a[i][k]);
            flag = true;
            break;
          }
        }
        if(flag == true) break;
      }
      if(flag == false) {
        cout << -1 << endl;
        break;
      }
      if(i == N / 2 - 1) {
        REP(i, ans.size()) {
          cout << ans[i];
        }
        if(N % 2 == 1) cout << a[N / 2][0];
        for(int i = ans.size() - 1; i >= 0; --i) {
          cout << ans[i];
        }
        cout << endl;
      }
    }
  }
}
