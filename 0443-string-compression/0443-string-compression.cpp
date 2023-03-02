class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n < 2)
			return n;

		int  i = 0;
		int  j = 0;

		while(i < n){
			chars[j] = chars[i];
			int cnt = 0;
			while(i < n && chars[i] == chars[j]) {
				cnt++;
				i++;
			}

			if(cnt == 1) {
				j++;
			} else {
				string str = to_string(cnt);
				for(auto ch: str)
					chars[++j] = ch;
				j++;
			}
		}

		return j;
    }
};