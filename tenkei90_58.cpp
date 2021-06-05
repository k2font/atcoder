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

ll digits(ll num) {
  ll tmp = 0;
  while(num > 0) {
    ll a = num % 10;
    tmp += a;
    num = num / 10;
  }
  return tmp;
}

int main() {
  ll N, K; cin >> N >> K;
  vector<P> memo(2e6); // その値Xが { 何番目に出現したか, それまでの計算結果(和) }
  ll tmp = N; // tmpは今の値
  for(ll i = 0; i < K; ++i) {
    // 桁和
    ll X = digits(tmp); X += tmp; X %= 100000;
    if(memo[X].first) { // もしその値がすでに配列にあれば、ループ最後の回りきらないフェーズまでワープさせる
      // 今の順番と、かつてXが出てきた番号の差。これが、ループ1周分の長さになる
      const auto t = i - memo[X].first;
      // この時点で、あとループを何周するか？
      const auto c = (K - i - 1) / t;
      // ループ1周分の長さ * ループを回る回数 をiに足し込む
      i += t * c;
    } else { // もし配列にまだXが無ければ
      memo[X] = P(i, 0); // 配列のX番目にpairを格納する。
    }
    tmp = X;
  }
  cout << tmp << endl;
}