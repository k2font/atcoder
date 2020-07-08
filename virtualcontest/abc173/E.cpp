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

ll N, M; 
ll X, Y; 
vector<ll> a; vector<ll> b; 
bool solve_b(ll index, ll key) {
  if(b[index] >= key) return true;
  else return false;
}

ll binary_search_a(ll key) {
  ll ng = -1;
  ll ok = N;
  while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if(a[mid] >= key) ok = mid;
    else ng = mid;
  }
  return ok;
}

ll binary_search_b(ll key) {
  ll ng = -1;
  ll ok = M;
  while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if(b[mid] >= key) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  cin >> N >> M;
  cin >> X >> Y;
  a.resize(N); REP(i, N) cin >> a[i];
  b.resize(M); REP(i, M) cin >> b[i];
  ll ans = 0;
  ll start = a[0];
  while(true) {
    ll b_tmp = binary_search_b(start + X);
    if(b_tmp >= M) break;
    ll a_tmp = binary_search_a(b[b_tmp] + Y);
    ans++;
    if(a_tmp >= N) break;
    else start = a[a_tmp];
  }
  cout << ans << endl;
}