#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
ll char_to_ll(char val) {
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

template<ll MOD> struct ModLl {
    static const ll Mod = MOD; unsigned x; ModLl() : x(0) { }
    ModLl(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModLl(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ll get() const { return (ll)x; }
    ModLl &operator+=(ModLl that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModLl &operator-=(ModLl that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModLl &operator*=(ModLl that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModLl &operator/=(ModLl that) { return *this *= that.inverse(); }
    ModLl operator+(ModLl that) const { return ModLl(*this) += that; }
    ModLl operator-(ModLl that) const { return ModLl(*this) -= that; }
    ModLl operator*(ModLl that) const { return ModLl(*this) *= that; }
    ModLl operator/(ModLl that) const { return ModLl(*this) /= that; }
    ModLl inverse() const { long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModLl(u); }
    bool operator==(ModLl that) const { return x == that.x; }
    bool operator!=(ModLl that) const { return x != that.x; }
    ModLl operator-() const { ModLl t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<ll MOD> ostream& operator<<(ostream& st, const ModLl<MOD> a) { st << a.get(); return st; };
template<ll MOD> ModLl<MOD> operator^(ModLl<MOD> a, unsigned long long k) {
    ModLl<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r; }
typedef ModLl<1000000007> mint;

ll N, K;

vector<mint> pFactorization(ll n) {
    vector<mint> ret;
    for(ll i=2; i*i<=n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n != 1) ret.push_back(n);
    return ret;
}

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for(ll i=1; i*i<=n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(n / i != i) ret.push_back(n/i);
        }
    }
    return ret;
}

ll MOD = 1000000007;

// 1 <= i <= n, gcd(i, m) = 1 なるすべての i の和を求める
// mint solve(ll n, ll m) {
//     vector<mint> vp = pFactorization(m);
//     ll s = vp.size();
//     mint ans = 0;
//     for(ll bit = 0; bit < (1<<s); ++bit) {
//         mint num = 1;
//         for(ll i = 0; i < s; ++i) if(bit >> i & 1) num *= vp[i];
//         mint a = ((mint)n / num);
//         mint b = (a * (a+1) / 2);
//         mint c = num;
//         if(__builtin_popcount(bit) % 2) {
//           mint sub = b * c;
//           ans = (ans - sub + MOD) % MOD;
//         }
//         else {
//           ans += b * c;
//         }
//     }
//     return ans;
// }

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> vec;//gcd(i,k)=hogeを格納
 
    for(ll i = 1;i*i <= k;i++){
        if(k % i){
            continue;
        }
        vec.push_back(i);
        vec.push_back(k / i);
    }
    sort(vec.begin(),vec.end(),greater<ll>());
 
    ll ans = 0;
    ll siz = vec.size();
 
    vector<ll> s(siz,0);
 
    for(ll i = 0;i < siz;i++){
        //大きい方から見る
        //約数がhogeとなる整数の集合を考える
        ll r = (n /vec[i]) * vec[i];//約数がvec[i]となるものでn以下の最大の数
        s[i] = (vec[i] + r)*(n/vec[i])/2;//約数がhogeとなる整数の総和
 
        for(int j = 0;j < i;j++){
 
            if(vec[j] % vec[i]){
                continue;
            }
            //約数の倍数以外の場合は除く
            //約数がxの集合から約数が2x、3x、・・・となる集合を引いておく
            //大きい方から見ていくと２回引かなくなる
            //1の場合、2,3,4,・・・と引いていくが、大きい方から見ていくことで、2,3において6の倍数を２回引かなくなる
            //3の時に6の倍数が引かれ、2の時に6の倍数が独立に引かれる
            s[i] = s[i] - s[j];
        }
        //s[i]は整数の和なのでs[i]/gcd(i,k)のようにgcdで割る
        ans = (ans + s[i] / vec[i]) % MOD;
    }
    cout << ans * k % MOD << endl;//最後に定数として置いておいたkをかける
}