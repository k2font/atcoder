#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    double a, b, x; cin >> a >> b >> x;

    double pi = 2.0 * asin(1.0);
    double unit_r = 180.0 / pi;

    double hantei = (a * a * b) / 2;
    double c = 2 * (a * a * b - x);
    double tangent = c / (a * a * a);
    if(hantei > x) {
        tangent = (a * b * b) / (2 * x);
    }
    double atangent = atan(tangent) * unit_r;

    cout << fixed << setprecision(10) << atangent << endl;
}