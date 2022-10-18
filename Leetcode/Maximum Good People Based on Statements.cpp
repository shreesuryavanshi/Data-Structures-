class Solution {
private: 
    int max_count = 0;
    int n;
public:
    int maximumGood(vector<vector<int>>& statements) {
        n = statements.size(); 
        vector<int> curr; 
        dfs(statements, curr, 0);
        return max_count;
    }
    void dfs(vector<vector<int>>& statements, vector<int>& curr, int count){
        if(curr.size() == n){
            if(isValid(curr, statements)){
                max_count = max(max_count, count);
            }
            return;
        }
        curr.push_back(0);
        dfs(statements, curr, count);
        curr.pop_back();
        curr.push_back(1);
        dfs(statements, curr, count + 1);
        curr.pop_back();
    }
    bool isValid(vector<int>& curr, vector<vector<int>>& statements){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(curr[i] == 1){
                    if(statements[i][j] != 2 && statements[i][j] != curr[j]) return false;
                }
            }
        }
        return true;
    }
};
