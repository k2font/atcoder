#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int a = C * max({X, Y}) * 2;
    
    int min_num = min({X, Y});
    int b = C * min_num * 2 + (X - min_num) * A + (Y - min_num) * B;
    int c = A * X + B * Y;

    int ans = min(a, min(b, c));
    cout << ans << endl;
    
}