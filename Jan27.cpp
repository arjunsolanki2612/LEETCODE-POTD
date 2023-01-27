472. Concatenated Words
https://leetcode.com/problems/concatenated-words/description/
https://www.youtube.com/watch?v=zZsnMAgM6Q0&t=1225s

// Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

// A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
// Example 1:

// Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
// "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".



class Solution {
public:

    bool isConcatenated(string word,unordered_set<string>&st){

        int l=word.length();
        for(int i=0;i<l;i++){
            string prefix = word.substr(0,i+1);
            string suffix = word.substr(i+1);

            if((st.find(prefix)!=st.end() && st.find(suffix)!=st.end()) || (st.find(prefix)!=st.end() && isConcatenated(suffix,st))){
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>st(begin(words),end(words));
        vector<string>result;
        for(int i=0;i<words.size();i++){
            string word = words[i];

            if(isConcatenated(word,st)){
                result.push_back(word);
            }
        }
        return result;
    }
};
