#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    int x3 = x2 - (y2 - y1); // こいつを求める
    int y3 = y2 + (x2 - x1);
    int x4 = x1 - (y2 - y1); // こいつを求める
    int y4 = y1 + (x2 - x1);

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}