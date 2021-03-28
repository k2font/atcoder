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

int main() {
  int N; cin >> N;

  // 構成できるか判定するパート
  // 三角数かどうかを判定する
  int tmp = 0; int cnt = 0;
  REP(i, 10000) {
    tmp += (i + 1); cnt++;
    if(tmp == N) {
      break;
    } else if(tmp > N) {
      cout << "No" << endl;
      return 0;
    }
  }
  cnt++;

  // 三角数であれば構成するパート
  cout << "Yes" << endl;
  cout << cnt << endl;
  vector<vector<int>> ans(cnt + 1);
  ll sum = 1;
  for(int k = cnt; k >= 1; --k) {
    for(int i = 0; i < k - 1; ++i) {
      ans[cnt - k].push_back(sum + i);
      ans[cnt - k + i + 1].push_back(sum + i);
    }
    sum += (k - 1);
  }

  REP(i, cnt) {
    cout << ans[i].size() << " ";
    REP(k, ans[i].size()) {
      cout << ans[i][k] << " ";
    }
    cout << endl;
  }
}