#include<bits/stdc++.h> 
#define int long long int  
using namespace std ;

vector<int> v(100),st(400,0),lazy(400,0); 
int n; 

void create_ST(int i, int a, int b){
	if(a==b){
		st[i]=v[a];
		return; 
	} 
	int mid=(a+b)/2;
	create_ST(2*i,a,mid); 
	create_ST(2*i+1,mid+1,b); 
	st[i]=st[2*i]+st[2*i+1]; 
}

void updat(int i, int a, int b, int s, int e, int val){
	if(lazy[i]!=0){
		int x=lazy[i]; 
		lazy[i]=0; 
		st[i]+=(b-a+1)*x;
		if(a!=b){
			lazy[2*i]=x;
			lazy[2*i+1]=x;
		}
	}
	if(s>b || e<a) return;
	if(s<=a && e>=b){
		int x=(b-a+1)*val; 
		st[i]+=x;
		if(a!=b){
			lazy[2*i]=val;
			lazy[2*i+1]=val;
		}
		return; 
	}
	int mid =(a+b)/2;
	updat(2*i,a,mid,s,e,val);
	updat(2*i+1,mid+1,b,s,e,val); 
	st[i]=st[2*i]+st[2*i+1]; 
}

int query(int i, int a, int b, int si,int ei){
	if(lazy[i]!=0){
		int x=lazy[i]; 
		lazy[i]=0; 
		st[i]+=(b-a+1)*x;
		if(a!=b){
			lazy[2*i]=x;
			lazy[2*i+1]=x;
		}
	}
	if(si>b || ei<a) return 0;
	if(si<=a && ei>=b) return st[i];
	int mid= (a+b)/2;  
	int lc = query(2*i  ,a,mid,si,ei);
	int rc = query(2*i+1,mid+1,b,si,ei);
	return lc+rc;
}

void prin(){
	for(int i=0;i<n;i++) cout<<v[i]<<" ";
	cout<<endl; 
}
void solve(){
	cin>>n; 
	for(int i=0; i<n;i++) cin>>v[i];
	create_ST(1,0,n-1);
	int q; 
	cin>>q;
	while(q--){
		//cout<<q<<":  ";
		//prin();
		int cas,val; 
		cin>>cas; 
		if(cas==1){
		int x, y; 
		cin>>x>>y;
		cout<<query(1,0,n-1,x-1,y-1)<<endl;
		}
		else {
			int x, y, val; 
			cin>>x>>y>>val;
			updat(1,0,n-1,x-1,y-1,val);
		}
	}
}


int32_t main() {
	int test =1;
	while(test--){
		solve();
	}
	return 0; 
}