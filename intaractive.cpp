#include <bits/stdc++.h>
#define SIZE 205
using namespace std;

char str[10];
int ans[SIZE];
map <vector <int>,int> mp;
int red(vector <int> vec)
{
	sort(vec.begin(),vec.end());
	if(mp.count(vec)) return mp[vec];
	printf("?");
	for(int i=0;i<vec.size();i++) printf(" %d",vec[i]+1);puts("");
	fflush(stdout);
	scanf("%s",&str);
	return mp[vec]=(str[0]=='R'?1:0);
}
vector <int> get_range(int l,int r)
{
	vector <int> ret;
	for(int i=l;i<=r;i++) ret.push_back(i);
	return ret;
}
vector <int> concate(vector <int> A,vector <int> B)
{
	for(int i=0;i<B.size();i++) A.push_back(B[i]);
	return A;
}
int main()
{
	int n;
	scanf("%d",&n);
	int fr=red(get_range(0,n-1));
	vector <int> vx;
	int l=0,r=n;
	while(l+1<r)
	{
		int d=(l+r)/2;
		int now=red(get_range(d,d+n-1));
		if(now!=fr) r=d;
		else l=d;
	}
	l=r;
	r=r+n-2;
	//printf("%d %d\n",l,r);
	vx=get_range(l,r);
	vector <int> vr,vb;
	for(int i=0;i<2*n;i++)
	{
		if(i<l||r<i)
		{
			vector <int> now=vx;
			now.push_back(i);
			ans[i]=red(now);
			if(ans[i]==1&&vr.size()<n/2) vr.push_back(i);
			else if(ans[i]==0&&vb.size()<n/2) vb.push_back(i);
		}
	}
	vector <int> vl=concate(vr,vb);
	for(int i=l;i<=r;i++)
	{
		vector <int> now=vl;
		now.push_back(i);
		ans[i]=red(now);
	}
	printf("! ");
	for(int i=0;i<2*n;i++) printf("%c",ans[i]==1?'R':'B');
	puts("");
	fflush(stdout);
	return 0;
}
