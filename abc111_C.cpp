#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int n;
int bj[maxn];
int a[maxn];
int cnta[maxn];
int cntb[maxn];
typedef pair<int,int> pii;

int main()
{

    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i&1)
        {
            cnta[a[i]]++;
        }else{
            cntb[a[i]]++;
        }
    }
    vector<pii> ji,ou;
    for(int i=1;i<=n;i++)
    {
        if(i&1)
        {
            ji.push_back(make_pair(cnta[a[i]],a[i]));
        }else
        {
            ou.push_back(make_pair(cntb[a[i]],a[i]));
        }
    }
    sort(ji.begin(),ji.end());
    ji.erase(unique(ji.begin(),ji.end()),ji.end());
    sort(ou.begin(),ou.end());
    ou.erase(unique(ou.begin(),ou.end()),ou.end());
    int ans=1e9;
    for(int i=1;i<=n;i+=2)
    {
        if(ou[ou.size()-1].second!=a[i])
        {
            ans=min(ans,n/2-cnta[a[i]]+n/2-ou[ou.size()-1].first);
        }else
        {
            if(ou.size()>=2)
            {
//                cout<<ou[n/2-2].first<<" "<<ou[n/2-2].second<<endl;
                ans=min(ans,n/2-cnta[a[i]]+n/2-ou[ou.size()-2].first);
            }else
            {
                ans=min(ans,n/2-cnta[a[i]]+n/2);
            }
        }
    }
    for(int i=2;i<=n;i+=2)
    {
        if(ji[ji.size()-1].second!=a[i])
        {
            ans=min(ans,n/2-cntb[a[i]]+n/2-ji[ji.size()-1].first);
        }else
        {
            if(ji.size()>=2)
            {
                ans=min(ans,n/2-cntb[a[i]]+n/2-ji[ji.size()-2].first);
            }else
            {
                ans=min(ans,n/2-cntb[a[i]]+n/2);
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
