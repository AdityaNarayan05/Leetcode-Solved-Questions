class Solution {
    bool isSorted( string s) {
        int i = 0, j = 1;
        while( j < s.length() ) {
            if( (s[j] - s[i]) < 0 ) return false;
            i++;
            j++;
        }
        return true;
    }
public:
    int minDeletionSize(vector<string>& strs) {

        int ans, count = 0;
        // Length of each string in the array
        int len = strs[0].length();
        // Size of the array
        int size = strs.size();

        for( int i = 0; i < len; i++ ) {
            string temp = "";

            // Store 1st column in temp
            for( int j = 0; j < size; j++) {
                temp.push_back(strs[j][i]);
            }
            
            // Check if the column in temp is sorted lexicographically

            if( !isSorted(temp) ) {
                count ++;
            }
        }
            
            return count;
    }
};