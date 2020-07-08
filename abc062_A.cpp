#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int x, y; cin >> x >> y;

    vector<int> A = {1, 3, 5, 7, 8, 10, 12};

    bool flag_x = false;
    bool flag_y = false;
    if(x == 2 || y == 2) {
        cout << "No" << endl;
    } else {
        REP(i, A.size()) {
            if(A[i] == x) flag_x = true;
            if(A[i] == y) flag_y = true;
        }

        if((flag_x == true && flag_y == true) || (flag_x == false && flag_y == false) ) cout << "Yes" << endl; 
        else cout << "No" << endl;
    }
}