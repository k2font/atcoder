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

using type = pair<int, ll>;
using event = pair<ll, type>;

int main() {
  int N, Q; cin >> N >> Q;
  // イベントの再構築
  vector<event> v;
  REP(i, N) {
    int S, T, X; cin >> S >> T >> X;
    v.push_back({S - X, type(-1, X)});
    v.push_back({T - X, type(0, X)});
  }

  REP(i, Q) {
    int D; cin >> D;
    v.push_back({D, type(1, i)});
  }

  sort(all(v));
  // for(auto p : v) {
  //   cout << p.first << " " << p.second.first << " " << p.second.second << endl;
  // }

  vector<ll> res(Q);
  multiset<ll> se; // 重複を許す集合
  for(auto p : v) {
    ll x = p.first; // keyが格納されている
    int type = p.second.first; // イベントタイプを格納
    ll val = p.second.second; // 通行止めとなる座標を格納
    if(type == -1) se.insert(val); // 通行止めとなっている座標を格納する
    else if(type == 0) se.erase(se.lower_bound(val)); // 値の検索をしてイテレータを渡さないと、multisetに存在するすべての値が削除されてしまう！
    else res[val] = (se.empty() ? -1 : *(se.begin()));
  }
  for(auto v : res) {
    cout << v << endl;
  }
}