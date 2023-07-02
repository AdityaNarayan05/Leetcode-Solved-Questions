class Solution {
public:
     void funct(vector<vector<int>>& requests, vector<int>& capacity, int reqId, int reqProcessed, int& maxRequests){
        if(reqId == requests.size()){
            for(auto c : capacity){
                if(c != 0)
                    return;
            }            
			maxRequests = max(maxRequests, reqProcessed);                
            return;
        }
         
        funct(requests, capacity, reqId+1, reqProcessed, maxRequests);
        capacity[requests[reqId][0]]--; 
        capacity[requests[reqId][1]]++;
         
       	funct(requests, capacity, reqId+1, reqProcessed+1, maxRequests);
        capacity[requests[reqId][0]]++;   
        capacity[requests[reqId][1]]--;
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {        
        vector<int> capacity(n, 0);
        int maxRequests;
        
        funct(requests, capacity, 0, 0, maxRequests);
        return maxRequests;        
    }
};