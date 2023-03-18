class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        int num[405]={};
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        for(int i=0;i<num1.size();i++)
            for(int j=0;j<num2.size();j++)
                num[i+j]+=(num1[i]-'0')*(num2[j]-'0');
        
        int n=num1.size()+num2.size();
        for(int i=0;i<n;i++)
            if(num[i]>9)
                num[i+1]+=num[i]/10,num[i]%=10;
        string ans;
        for(int i=0;i<n-1;i++)
            ans+=('0'+num[i]);
        if(num[n-1])
            ans+=('0'+num[n-1]);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};