class Solution {
public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         unordered_map<int,vector<pair<int,int>>> adjL;
//         for(auto f:flights)
//             adjL[f[0]].push_back({f[1],f[2]});
        
        
//         priority_queue< vector<int>,vector<vector<int>>,greater<vector<int>> > mH;
//         mH.push({0,src,k+1});
        
//         while(!mH.empty()){
//             auto t=mH.top();
//             mH.pop();
//             int cost=t[0];
//             int curr=t[1];
//             int stop=t[2];
//             if(curr==dst)
//                 return cost;
            
//             if(stop>0)
//                 for(auto next:adjL[curr])
//                     mH.push({cost+next.second,next.first,stop-1});
//         }
//         return -1;
//     }
    
    
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         unordered_map<int,vector<pair<int,int>>> adjL;
//         for(auto f:flights)
//             adjL[f[0]].push_back({f[1],f[2]});
        
//         queue<pair<int,int>> q;
//         q.push({src,0});
//         int std=INT_MAX;
        
//         while(!q.empty() and k-- >=0){
//             int sz=q.size();
//             for(int i=0;i<sz;i++){
//                 auto curr=q.front();
//                 q.pop();
//                 for(auto t:adjL[curr.first]){
                    
//                     if(std<curr.second+t.second)
//                         continue;
                    
//                     q.push({t.first,curr.second+t.second});
                    
//                     if(dst==t.first)
//                         std=min(std,curr.second+t.second);
//                 }
//             }
//         }
//         return std==INT_MAX?-1:std;
//     }
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        /* distance from source to all other nodes */
        vector<int> dist( n, INT_MAX );
        dist[src] = 0;
        
        // Run only K+1 times since we want shortest distance in K hops
        for( int i=0; i <= K; i++ ) {
            vector<int> tmp( dist );
            for( auto flight : flights ) {
                if( dist[ flight[0] ] != INT_MAX ) {
                    tmp[ flight[1] ] = min( tmp[flight[1]], dist[ flight[0] ] + flight[2] );
                }
            }
            dist = tmp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};