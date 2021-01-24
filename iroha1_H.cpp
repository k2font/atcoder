#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
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

int main() {
  string N; cin >> N;
  // 1桁
  if(N.size() == 1) {
    cout << 10 + (stoi(N) - 1) << endl;
    return 0;
  }

  // *99999...
  if(N[0] != '9') {
    REP(i, N.size()) {
      if(i == 0) continue;
      if(N[i] != '9') break;
      if(i == N.size() - 1) {
        auto x = N.front();
        reverse(all(N));
        N.pop_back(); N.pop_back(); N.push_back('8');
        reverse(all(N));
        cout << char_to_int(x) + 1 << N << endl;
        return 0;
      }
    }
  }

  // 99999...
  REP(i, N.size()) {
    if(N[i] != '9') break;
    if(i == N.size() - 1) {
      N.pop_back();
      cout << "18" << N << endl;
      return 0;
    }
  }

  reverse(all(N));
  for(int i = 0; i < 100; ++i) {
    REP(i, N.size() - 1) {
      int first = char_to_int(N[i]);
      int second = char_to_int(N[i + 1]);
      if(first + second < 9) {
        first += second; second = 0; N[i] = '0' + first; N[i + 1] = '0' + second;
      } else {
        int a = 9 - first; first = 9; second -= a;
        N[i] = '0' + first; N[i + 1] = '0' + second;
      }
    }
  }
  reverse(all(N));
  ll ans = 0;
  REP(i, N.size()) {
    ans += char_to_int(N[i]);
    if(i != N.size() - 1) ans *= 10;
  }
  cout << ans << endl;
}