#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    char a, b; cin >> a >> b;

    if((a == 'H' && b == 'H') || (a != 'H' && b != 'H')) {
        cout << 'H' << endl;
    } else {
        cout << 'D' << endl;
    }
}