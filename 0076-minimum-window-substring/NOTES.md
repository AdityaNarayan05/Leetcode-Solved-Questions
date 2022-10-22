I will first give the solution then show you the magic template.
​
The code of solving this problem is below. It might be the shortest among all solutions provided in Discuss.
​
string minWindow(string s, string t) {
vector<int> map(128,0);
for(auto c: t) map[c]++;
int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
while(end<s.size()){
if(map[s[end++]]-->0) counter--; //in t
while(counter==0){ //valid
if(end-begin<d)  d=end-(head=begin);
if(map[s[begin++]]++==0) counter++;  //make it invalid
}
}
return d==INT_MAX? "":s.substr(head, d);
}
Here comes the template.
​
For most substring problem, we are given a string and need to find a substring of it which satisfy some restrictions. A general way is to use a hashmap assisted with two pointers. The template is given below.
​
int findSubstring(string s){
vector<int> map(128,0);
int counter; // check whether the substring is valid
int begin=0, end=0; //two pointers, one point to tail and one  head
int d; //the length of substring
​
for() { /* initialize the hash map here */ }
​
while(end<s.size()){
​