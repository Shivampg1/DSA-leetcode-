class Solution {
public:
vector<int>par;
  vector<int>rnk;
      int find(int x){
          if(par[x]==x){
              return x;
          }
          return par[x]=find(par[x]);
      }
      void unionbyrnk(int u,int v){
          int path_u=find(u);
          int path_v=find(v);
          
          if(path_u==path_v)return;
          if(rnk[path_u]==rnk[path_v]){
              par[path_v]=path_u;
              rnk[path_u]++;
          }
          else if(rnk[path_u]>rnk[path_v]){
              par[path_v]=path_u;
          }
          else{
               par[path_u]=path_v;
          }
  }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        par.resize(n);
        rnk.assign(n, 0);
        for(int i=0;i<n;i++){
          par[i]=i;
      }
        int count=n;
        for(auto & e:connections){
            int u=e[0];
            int v=e[1];
            
            int path_u=find(u);
            int path_v=find(v);
            
            if(path_u!=path_v){
                 unionbyrnk(u,v);
                 count--;
            }
        }
        return count-1;
    }
};