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

template<typename T>
struct segtree{
 const T inf = numeric_limits<T>::max();
 int n;
 vector<T> v;
 segtree(int n_){ //引数のnだからn_,struct内のnと区別する。
   int x = 1;
   while(n_ > x) x *= 2; 
   n = x;
   v.resize(2*n-1 ,inf);
 }
 
 void update(int k, T x){
   k += n - 1;
   v[k] = x;
   while(k > 0){
     k = (k - 1) / 2;
     v[k] = min(v[k*2+1], v[k*2+2]);
   }
 }
 T query(int a, int b) {return query_sub(a,b,0,0,n);}
 T query_sub(int a, int b, int k, int l, int r){
   if(b <= l || r <= a) return inf;
   if(a <= l && r <= b) return v[k];
   T c1 = query_sub(a, b, 2*k+1, l, (l + r) / 2);
   T c2 = query_sub(a, b, 2*k+2, (l + r) / 2, r);
   return min(c1, c2);
 }  
};

int main() {
  ll N, Q; cin >> N >> Q;
  ll mx, my; mx = N - 2; my = N - 2;
  ll w = 0;
  segtree<ll> segx(N - 2), segy(N - 2);
  REP(i, N - 2) segx.update(i, N - 2);
  REP(i, N - 2) segy.update(i, N - 2);
  REP(i, Q) {
    ll q, x; cin >> q >> x; x -= 2;
    if(q == 1) {
      ll y = segx.query(x, N - 1);
      w += y;
      if(mx > x) {
        segy.update(y - 1, x);
        mx = x;
      }
    } else {
      ll X = segy.query(x, N - 1);
      w += X;
      if(my > x) {
        segx.update(X - 1, x);
        my = x;
      }
    }
  }
  ll ans = 0;
  ans = (N - 2) * (N - 2);
  cout << ans - w << endl;
}