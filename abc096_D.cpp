#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
struct edge {
  ll to, cost;
};

bool IsPrime(int num){
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      // 素数ではない
      return false;
    }
  }

  // 素数である
  return true;
}

int main() {
  int N; cin >> N;
  vector<int> ans;
  for(int i = 2; i <= 55555; ++i) {
    if(IsPrime(i)) {
      if(i % 5 == 4) ans.push_back(i);
    }
    if(ans.size() == N) break;
  }
  REP(i, ans.size()) {
    cout << ans[i];
    if(i != ans.size() - 1) cout << " ";
  }
  cout << endl;
}