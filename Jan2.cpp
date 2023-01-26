520. Detect Capital
https://leetcode.com/problems/detect-capital/

// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Given a string word, return true if the usage of capitals in it is right.

 #include<bits/stdc++.h>
using namespace std;
    bool detectCapitalUse(string word) {
        int n=word.size();
        int count=0;
        if(n==1){
            return true;
        }
        for(int i=0;i<n;i++){
            if(isupper(word[i])){
                count++;
            }
        }

        if(count==1 && isupper(word[0])){
            return true;
        }
        if(count==0 || count==n ){
            return true;
        }
        else{
            return false;
        }

    }
int main(){
    string word="leetcode";
    cout<<detectCapitalUse(word);
}
