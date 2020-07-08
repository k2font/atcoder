#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    string A, B; cin >> A >> B;


    if(A.size() > B.size()) {
        cout << "GREATER" << endl;
    } else if(A.size() < B.size()) {
        cout << "LESS" << endl;
    } else if(A.size() == B.size()){
        REP(i, A.size()) {
            if((A[i] - '0')== (B[i] - '0')) {
                if(i == A.size() - 1) {
                    cout << "EQUAL" << endl;
                }

                continue;
            }

            if((A[i] - '0') > (B[i] - '0')) {
                cout << "GREATER" << endl;
                break;
            } else if((A[i] - '0') < (B[i] - '0')) {
                cout << "LESS" << endl;
                break;
            }
        }
    }
}