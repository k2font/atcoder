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

int main() {
  int N; cin >> N;
  vector<int> t(N + 1), x(N + 1), y(N + 1);
  t[0] = 0;
  x[0] = 0;
  y[0] = 0;
  for(int i = 1; i <= N; ++i) {
    cin >> t[i] >> x[i] >> y[i];
  }
  string str = "Yes";
  
  REP(i, N + 1) {
    // cout << x.at(i) << " " << y.at(i) << " " << t.at(i) << endl;
    if((x.at(i) + y.at(i)) % 2 != t.at(i) % 2) {
      str = "No";
    }

    if(i == N) break;

    if((x.at(i + 1) + y.at(i + 1)) - (x.at(i) + y.at(i)) > t.at(i + 1) - t.at(i)) {
      str = "No";
    }
  }

  cout << str << endl;
}