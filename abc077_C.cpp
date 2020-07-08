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

vector<ll> A, B, C;

bool isOK(vector<ll> p, ll index, ll key) {
  if(p[index] >= key) return true;
  else return false;
}

ll binary_search(vector<ll> p, ll key) {
  ll ng = -1;
  ll ok = p.size();
  while(abs(ng - ok) > 1) {
    ll mid = (ng + ok) / 2;
    if(isOK(p, mid, key)) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  ll N; cin >> N; A.resize(N); B.resize(N); C.resize(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  REP(i, N) cin >> C[i];
  sort(all(A)); sort(all(B)); sort(all(C));
  ll ans = 0;
  REP(i, N) {
    ll a = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
    ll c = C.end() - upper_bound(C.begin(), C.end(), B[i]);
    ans += a * c;
  }
  cout << ans << endl;
}