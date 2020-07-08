#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int W, a, b; cin >> W >> a >> b;

    if((a <= b && b <= a + W) || (a <= b + W && b + W <= a + W)) {
        cout << 0 << endl;
    } else if(b + W < a) {
        cout << a - (b + W) << endl;
    } else {
        cout << b - (a + W) << endl;
    }
}
