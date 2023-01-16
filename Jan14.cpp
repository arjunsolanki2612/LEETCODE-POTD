1061. Lexicographically Smallest Equivalent String
You are given two strings of the same length s1 and s2 and a string baseStr.

We say s1[i] and s2[i] are equivalent characters.

For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'.
Symmetry: 'a' == 'b' implies 'b' == 'a'.
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the 
lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

 

Example 1:

Input: s1 = "parker", s2 = "morris", baseStr = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
The characters in each group are equivalent and sorted in lexicographical order.
So the answer is "makkek".

  
 //explaination
//   In this question we have used parent of each respective char as  in s1 and s2 at 0 index p and m are there so smallest of them is m so m is the parent of p. 
//   So that is we are doing in union and find operation. Initially the parent of each character is -1.
//   After finding all the parents of each respective character we will update our baseStr by finding the parent of the character at that index and then adding a to it.
  
// code
  
  class Solution {
public:
vector<char>parentChar;

int find(int parent){
    if(parentChar[parent]==-1) return parent;
    
    return parentChar[parent]=find(parentChar[parent]);
}

void findUnion(int x,int y){
    int ParentX=find(x);
    int ParentY=find(y);

    if(ParentX==ParentY)return;

    if(ParentX>ParentY){
        parentChar[ParentX]=ParentY;
    }
    else{
        parentChar[ParentY]=ParentX;
    }
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parentChar.resize(26,-1);

        for(int i=0;i<s1.size();i++){
            findUnion(s1[i]-'a',s2[i]-'a');
        }

        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=find(baseStr[i]-'a')+'a';
        }
        return baseStr;
    }
};
