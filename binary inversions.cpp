#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//inversion count korar function 
///inversion hosse ekta songkha tar bame tar cheye boro koto gula number ase?
ll invcnt(vector<ll>a,int n){
	ll res=0,one=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==1){
			one++;///1 paile one ++ korbe
		}else{
			res+=one;//tasara koyta 1 ase seta jog krbe
		}
	}
	return res;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n;
		vector<ll>a;
		for(int i=0;i<n;i++){
			cin>>x;
			a.push_back(x);//input nisi arrray ta
		}
		ll ans=invcnt(a,n);///first e ekbar check kore nisi maximum ase kina?
		int id=-1;//id er man initially -1 kore raksi
		
		//first er 0 take 1 kore check korlam
		for(int i=0;i<a.size();i++){
			if(a[i]==0){
				a[i]=1;
				id=i;///eta korar karon hosse kon index er 0 take 1 korsi
				break;
			}
		}
		ans=max(ans,invcnt(a,n));//abar dekhe nilam maximum answer konta
		if(id!=-1){
			a[id]=0;///abbar zero kore disi karon pore abar last er 1 take zero korbo
		}
		for(int i=n-1;i>=0;i--){
			if(a[i]==1){
				a[i]=0;////last er 1 take zero korsi
				break;
			}
		}
		ans=max(ans,invcnt(a,n));
		cout<<ans<<"\n";
	}
}
