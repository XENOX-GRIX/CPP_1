#include<bits/stdc++.h> 
#define int long long int  
using namespace std ;

vector<int> v(100),st(400); 
int n; 
void create_ST(int i, int a, int b){
	if(a==b){
		st[i]=v[a];
		return; 
	} 
	int mid=(a+b)/2;
	create_ST(2*i,a,mid); 
	create_ST(2*i+1,mid+1,b); 
	st[i]=max(st[2*i],st[2*i+1]); 
}
int query(int i, int a, int b, int si,int ei){
	if(si>b || ei<a) return INT_MIN; 
	if(si<=a && ei>=b) return st[i];
	int mid= (a+b)/2;  
	int lc = query(2*i  ,a,mid,si,ei);
	int rc = query(2*i+1,mid+1,b,si,ei);
	return max(lc,rc);
}
void prin(){
	for(int i=0;i<n;i++) cout<<v[i]<<" ";
	cout<<endl; 
}
void solve(){
	cin>>n; 
	for(int i=0; i<n;i++) cin>>v[i];
	create_ST(1,0,n-1);
	prin();
	int q; 
	cin>>q;
	while(q--){
		int x, y; 
		cin>>x>>y;
		cout<<query(1,0,n-1,x-1,y-1)<<endl;
	}
}


int32_t main() {
	int test =1;
	while(test--){
		solve();
	}
	return 0; 
}