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

const int INF = pow(10, 9) + 7;

int A, B, C;
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

auto dp = make_vec<double>(101, 101, 101);

double dfs(int a, int b, int c) {
  if(dp[a][b][c]) return dp[a][b][c];
  if(a == 100 || b == 100 || c == 100) return 0;
  double ans = 0; int par = a + b + c;
  ans += (dfs(a + 1, b, c) + 1) * a / par;
  ans += (dfs(a, b + 1, c) + 1) * b / par;
  ans += (dfs(a, b, c + 1) + 1) * c / par;
  dp[a][b][c] = ans;
  return ans;
}

int main() {
  cin >> A >> B >> C;
  cout << fixed << setprecision(20) << dfs(A, B, C) << endl;
}