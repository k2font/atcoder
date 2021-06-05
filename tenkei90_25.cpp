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

ll N, B;
ll ans = 0;
void dfs(string s) {
  if(s != "") {
    if(s.size() > 14) return;
    ll res = 1;
    REP(i, s.size()) res *= (ll)char_to_int(s[i]);
    ll b = B + res;
    if(b <= N) {
      string goal = to_string(b);
      sort(all(goal));
      if(goal == s) ans++;
    }
  }

  string t = s;
  char f;
  if(s == "") f = '1';
  else f = s[s.size() - 1];
  for(char i = f; i <= '9'; ++i) {
    t.push_back(i);
    dfs(t);
    t.pop_back();
  }
}

int main() {
  cin >> N >> B;
  string tmp = "";
  dfs(tmp);
  string V = to_string(B);
  bool f = false;
  for(int i = 0; i < V.size(); ++i) {
    if(V[i] == '0') f = true;
  }
  if(f == true && N >= B) ++ans; 
  cout << ans << endl;
}