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

vector<int> Eratosthenes( const int N ){
  vector<bool> is_prime( N + 1 );
  for( int i = 0; i <= N; i++ ) {
    is_prime[i] = true;
  }

  vector<int> P;
  for( int i = 2; i <= N; i++ ) {
    if( is_prime[ i ] == true) {
      for( int j = 2 * i; j <= N; j += i ) {
        is_prime[ j ] = false;
      }

      P.emplace_back( i );
    }
  }
  return P;
}

int main() {
  ll N, K; cin >> N >> K;
  auto p = Eratosthenes(N);
  vector<int> v(N + 10);
  REP(i, p.size()) {
    for(int k = p[i]; k <= N; k += p[i]) {
      v[k]++;
    }
  }
  int ans = 0;
  REP(i, N + 1) {
    if(i == 0) continue;
    if(v[i] >= K) ans++;
  }
  cout << ans << endl;
}