class UnionFind {
    vector<int> component;
    int distinctComponents;
public:
    UnionFind(int n) {
	    distinctComponents = n;
        for (int i=0; i<=n; i++) {
            component.push_back(i);
        }
    }
    bool Union(int a, int b) {       
        if (find(a) == find(b)) {
            return false;
        }
        component[find(a)] = b;
        distinctComponents--;
        return true;
    }
    int find(int a) {
        if (component[a] != a) {
            component[a] = find(component[a]);
        }
        return component[a];
    }
    bool connected() {
        return distinctComponents == 1;
    }
};

class Solution {    
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [] (vector<int> &a, vector<int> &b){
            return a[0] > b[0]; 
        });
        
        int edgesAdded = 0;
        UnionFind bob(n), alice(n);
        
        for (auto &e: edges) { // For each edge -
            int type = e[0], one = e[1], two = e[2];
            switch(type){
                case 1:
                    edgesAdded += alice.Union(one, two);
                    break;
                case 2:
                    edgesAdded += bob.Union(one, two);
                    break;
                case 3:
                    edgesAdded += (bob.Union(one, two) | alice.Union(one, two));
                    break;
            }
        }
        
        if(bob.connected() and alice.connected())
            return (edges.size()-edgesAdded);
            
        return -1; // yay solved
    }
};