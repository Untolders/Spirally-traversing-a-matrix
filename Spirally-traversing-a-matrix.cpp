###################################################################################################  Question  #########################################################################################################################

You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.

Examples:

Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
Explanation: 

Input: mat[][] = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]
Output: [1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]
Explanation: Applying same technique as shown above.
Input: mat[][] = [[32, 44, 27, 23], [54, 28, 50, 62]]
Output: [32, 44, 27, 23, 62, 50, 28, 54]
Explanation: Applying same technique as shown above, output will be [32, 44, 27, 23, 62, 50, 28, 54].
Constraints:
1 <= n, m <= 1000
0 <= mat[i][j]<= 100



###################################################################################################  Solution  #########################################################################################################################
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void horizonTrav(vector<vector<int>> &mat, vector<int> &ans,int a, int b,int row ){
        //
        if(a<b){
            for(int i=a; i<=b; i++){
                ans.push_back(mat[row][i]);
            }
        }
        else {
            for(int i=a; i>=b; i--){
                ans.push_back(mat[row][i]);
            }
        }
        
    }
    void vertTrav(vector<vector<int>> &mat, vector<int> &ans, int a, int b,int col){
        if(a<b){
            for(int i=a; i<=b; i++){
                ans.push_back(mat[i][col]);;
            }
        }
        else {
            for(int i=a; i>=b; i--){
             ans.push_back(mat[i][col]);;
            }
        }
        
    }

    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        vector<int> ans;
        int n= mat.size(), m= mat[0].size();
        int left=0, right= m-1, top= 0, bottom= n-1;
        
        //Corner cases for n==1. m==1, size==1
        
        while(left<= right && top<=bottom){
            //For corner cases if we have only 1 row or column left
            if(left== right ){
                for(int i=top; i<=bottom; i++){
                    ans.push_back(mat[i][left]);
                }
                break;
            }
            else if(top== bottom){
                for(int i=left;i<=right;i++){
                    ans.push_back(mat[top][i]);
                }
                break;
            }
            
            horizonTrav(mat, ans, left, right-1, top);
            vertTrav(mat, ans, top, bottom-1, right);
            horizonTrav(mat, ans, right, left+1 ,bottom);
            vertTrav(mat, ans, bottom, top+ 1, left);
            
            right--;
            left++;
            top++;
            bottom--;
        }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
