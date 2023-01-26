// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false
#include<bits/stdc++.h>
using namespace std;
bool wordPattern(string pattern, string s) {
       vector<string>word;
       int i=0, s_size=s.size();
       string temp="";

       //storing each word of the string s in a vector
       while(i<s_size){
           if(s[i]==' '){
               word.push_back(temp);
               temp="";
           }
           else{
               temp+=s[i];
           }
           i++;
       }
       word.push_back(temp);
    // if pattern size is not equal to the vector word size then return false
       if(pattern.size()!=word.size()){
           return false;
       }
    //creating a map and set
       map<char,string>mp;
       set<string>st;
    //iterating through the size of the pattern
       for(int i=0;i<pattern.size();i++){
    //if pattern is present in the map then check is the word at that i matches the key to that  key
           if(mp.find(pattern[i])!=mp.end()){
               if(mp[pattern[i]]!=word[i]){
                   return false;
               }
           }
           //if the word is already present in the set it means we are trying to map the word with different key it means the pattern is not following
           else{
               if(st.count(word[i])>0){
                   return false;
               }
               //if count==0 then insert the value corresponding to the key and in the set as well
               mp[pattern[i]]=word[i];
               st.insert(word[i]);
           }
           
       }
       return true;
                
    }

int main(){
    cout<<wordPattern("abba","dog cat cat dog");
    return 0;
}
