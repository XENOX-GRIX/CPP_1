class sparse_tree{
    vector<vector<int>> sparse; 
    vector<int> vs; 
    int n; 
public:
    sparse_tree(vector<int> s){
        vs = s;
        n=vs.size(); 
    }
    void create_max_sparse(){
        sparse = vector<vector<int>>(n, vector<int>(log2(n)+1,0)); 
       
        for(int i=0; i<n ; i++) sparse[i][0]=i;  
        
        for(int j=1; (1<<j)<=n; j++){
            for(int i=0; i+(1<<j)-1<n; i++){
                if(vs[sparse[i][j-1]] > vs[sparse[i+(1<<(j-1))][j-1]]){
                    sparse[i][j]= sparse[i][j-1]; 
                }
                else{
                    sparse[i][j] = sparse[i+(1<<(j-1))][j-1]; 
                }
            }
        }
    }

    void create_min_sparse(){
        sparse = vector<vector<int>>(n, vector<int>(log2(n)+1,0)); 
        for(int i=0; i<n ; i++) sparse[i][0]=i; 
        for(int j=1; (1<<j)<=n; j++){
            for(int i=0; i+(1<<j)-1<n; i++){
                if(vs[sparse[i][j-1]] < vs[sparse[i+(1<<(j-1))][j-1]]){
                    sparse[i][j]= sparse[i][j-1]; 
                }
                else{
                    sparse[i][j] = sparse[i+(1<<(j-1))][j-1]; 
                }
            }
        }
    }
    int sparse_min_query(int l, int r){
        int tot = r-l+1; 
        int k = log2(tot); 
        return min( vs[sparse[l][k]], vs[sparse[l+tot -(1<<k)][k]]); 
    }
    int sparse_max_query(int l, int r){
        int tot = r-l+1; 
        int k = log2(tot); 
        return max( vs[sparse[l][k]], vs[sparse[l+tot -(1<<k)][k]]); 
    }
}; 