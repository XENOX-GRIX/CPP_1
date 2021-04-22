#include<bits/stdc++.h> 
#define int long long int 
using namespace std; 
typedef struct element{
	int ez,eo,et; 
}el; 
vector<int> lazy(400009,0); 
vector<el>  st(400009);

void build(int i, int a, int b){
	if(a==b){
		st[i].ez=1;
		st[i].eo=0;
		st[i].et=0;
		return; 
	}
	int mid =(a+b)/2;
	build(2*i, a, mid);
	build(2*i+1,mid+1,b); 
	st[i].ez=st[i*2].ez+st[i*2+1].ez;
	st[i].eo=st[i*2].eo+st[i*2+1].eo;
	st[i].et=st[i*2].et+st[i*2+1].et;
}
void shif(int i){
	int x=st[i].ez;
	st[i].ez=st[i].eo;
	st[i].eo=st[i].et;
	st[i].et=x;
}
void _update(int i, int a, int b, int s, int e){
	if(lazy[i]!=0){
		int x= lazy[i];
		lazy[i]=0;
		if(a!=b){
			lazy[i*2]+=x;
			lazy[2*i+1]+=x;
		}
		x%=3;
		while(x--){
			shif(i); 
		}
	}
	if(s>b || e<a) return ;
	if(a>=s && b<=e){
		shif(i);
		if(a!=b){
			lazy[i*2]+=1;
			lazy[2*i+1]+=1;
		}
		return; 
	}
	int mid=(a+b)/2;
	_update(2*i,a,mid,s,e); 
	_update(2*i+1,mid+1,b,s,e); 
	st[i].ez=st[i*2].ez+st[i*2+1].ez;
	st[i].eo=st[i*2].eo+st[i*2+1].eo;
	st[i].et=st[i*2].et+st[i*2+1].et;
}

int query(int i, int a, int b, int s, int e){
	if(lazy[i]!=0){
		int x= lazy[i];
		lazy[i]=0;
		if(a!=b){
			lazy[i*2]+=x;
			lazy[2*i+1]+=x;
		}
		x%=3;
		while(x--){
			shif(i); 
		}
	}
	if(s>b || e<a) return 0; 
	if(a>=s && b<=e) return st[i].ez; 
	int mid=(a+b)/2;
	int lq=query(2*i,a,mid,s,e);
	int rq=query(2*i+1,mid+1,b,s,e);
	return lq+rq;
}
void solve(){
	int N, Q; 
	cin>>N>>Q;
	build(1,0,N-1); 
	for(int i=0;i<Q;i++){
		int choi,s,e; 
		cin>>choi>>s>>e;
		if(choi==0){
			_update(1,0,N-1,s,e); 
		}
		else{
			cout<<query(1,0,N-1,s,e)<<endl; 
		}
	}
}
int32_t main(){
	int test = 1; 
	while(test--){
		solve();
	}
	return 0;
}
