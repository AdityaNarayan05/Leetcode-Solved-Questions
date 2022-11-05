class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i=0,x,n=chalk.size();
        long long sum=0;
        for(int v:chalk){
            sum+=v;
        }
        int ks=k%sum;
        // cout<<ks<<endl;
        while(ks>0){
            if(ks>=chalk[i]){
              ks-=chalk[i]; 
                i++;
                // cout<<ks<<" ";
            }
            else{
                x=i;
                break;
            }
        }
        return x%n;
    }
};