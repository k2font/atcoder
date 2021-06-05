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
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

int N;
vector<int> xy;

int check(int x, vector<int> _v) {
  vector<int> v;
  for(auto i : _v) {
    if(i != 0) v.push_back(i);
  }

  set<int> dp;
  dp.insert(0);
  for(auto i : _v) {
    set<int> pd;
    for(auto k : dp) {
      pd.insert(k + i);
      pd.insert(k - i);
    }
    swap(dp, pd);
  }

  for(auto k : dp) {
    if(k == x) {
      return 1;
    }
  }
  return 0;
}

int main() {
  // 重要な性質としてパリティが使える
  // Fが1回来るたびに、x + yの遇奇が変化する
  // Fが奇数回来るなら、x + yは奇数でなければならない
  string s; cin >> s; xy.resize(2);
  cin >> xy[0] >> xy[1];
  N = s.size();

  int pre = -1; int state = 0;
  vector<vector<int>> v(2);
  REP(i, N) {
    if(s[i] == 'T') {
      v[state].push_back(i - pre - 1);
      state = 1 - state;
      pre = i;
    }
  }
  v[state].push_back(N - pre - 1);

  // REP(i, 2) {
  //   REP(k, v[i].size()) {
  //     cout << v[i][k] << " ";
  //   }
  //   cout << endl;
  // }

  // Fの部分だけ取り出す
  xy[0] -= v[0].front();
  v[0].erase(v[0].begin(), v[0].begin() + 1); // 取り出した値を削除する

  REP(d, 2) {
    if(!check(xy[d], v[d])) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}