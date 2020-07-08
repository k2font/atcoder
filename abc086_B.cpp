#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    string a, b; cin >> a >> b;

    string ab = a + b;
    for(int i = 1; i < stoi(ab) / 2; ++i) {
        if(i == stoi(ab) / i && stoi(ab) % i == 0) {
            cout << "Yes" << endl;
            break;
        }

        if(i == (stoi(ab) / 2) - 1) {
            cout << "No" << endl;
        }
    }
}