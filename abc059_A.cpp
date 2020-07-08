#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    string s1, s2, s3; cin >> s1 >> s2 >> s3;

    char s1c, s2c, s3c;
    s1c = s1[0] - ('a' - 'A');
    s2c = s2[0] - ('a' - 'A');
    s3c = s3[0] - ('a' - 'A');
    cout << s1c << s2c << s3c << endl;
}