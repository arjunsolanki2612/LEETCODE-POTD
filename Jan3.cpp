// You are given an array of n strings strs, all of the same length.

// The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:

// abc
// bce
// cae
// You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

// Return the number of columns that you will delete.

 

// Example 1:

// Input: strs = ["cba","daf","ghi"]
// Output: 1
// Explanation: The grid looks as follows:
//   cba
//   daf
//   ghi
// Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.

#include<bits/stdc++.h>
using namespace std;

    int minDeletionSize(vector<string>& strs) {
       int row=strs.size();
       int col=strs[0].size();
       int del_col=0;
       for(int i=0;i<col;i++){
           for(int j=0;j<row-1;j++){
               if(strs[j][i]>strs[j+1][i]){
                   del_col++;
                   break;
               }
           }
       }
       return del_col; 
    }

int main(){
    vector<string>strs={"cba","daf","ghi"};
    cout<<minDeletionSize(strs);
    return 0;
}