class Solution {
public:
    bool halvesAreAlike(string s) {
        int size = s.size();
        string firstHalve = s.substr(0, size/2);
        string secondHalve = s.substr(size/2);
        
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0, j = 0; i < firstHalve.size(); i++, j++){
           if(firstHalve[i] == 'a' || firstHalve[i]== 'e'|| firstHalve[i] == 'i'|| firstHalve[i] == 'o'|| firstHalve[i] == 'u'|| firstHalve[i] == 'A'|| firstHalve[i] == 'E'|| firstHalve[i] == 'I'|| firstHalve[i] == 'O'|| firstHalve[i] == 'U')
               cnt1++;

           if(secondHalve[j] == 'a' || secondHalve[j]  == 'e'|| secondHalve[j]  == 'i'|| secondHalve[j]  == 'o'|| secondHalve[j]  == 'u'|| secondHalve[j]  == 'A'|| secondHalve[j]  == 'E'|| secondHalve[j]  == 'I'|| secondHalve[j]  == 'O'|| secondHalve[j]  == 'U')
               cnt2++;
            
        }

        if(cnt1 == cnt2)
            return true;
        
        return false;
    }
};