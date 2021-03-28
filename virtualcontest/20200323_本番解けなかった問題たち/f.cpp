#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val)
{
  return string(1, val);
}
int char_to_int(char val)
{
  return val - '0';
}
char inverse_char(char c)
{
  if (isupper(c))
    return tolower(c);
  else
    return toupper(c);
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
struct edge
{
  ll to, cost;
};

struct interval {
  ll s, f;
  interval(ll s, ll f) : s(s), f(f) { }
};
bool compare_f(const interval &x, const interval &y) {
  return x.f < y.f;
}
vector<interval> interval_scheduling(vector<interval> J) {
  vector<interval> A;
  sort(J.begin(), J.end(), compare_f);
  int f = 0;
  for (int i = 0; i < J.size(); ++i) {
    if (J[i].s >= f) {
      A.push_back(J[i]);
      f = J[i].f;
    }
  }
  return A;
}

int main() {
  int N, M; cin >> N >> M;
  vector<ll> a(M), b(M); REP(i, M) cin >> a[i] >> b[i];
  vector<interval> inter;
  REP(i, M) {
    inter.push_back({a[i], b[i]});
  }
  auto ans = interval_scheduling(inter);
  cout << ans.size() << endl;
}