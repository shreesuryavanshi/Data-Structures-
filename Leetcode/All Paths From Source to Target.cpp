class Solution {
public:
    void dfs(int idx,vector<vector<int>>&graph,vector<vector<int>>&allPath,vector<int>&path){
        path.push_back(idx);
        if(idx==graph.size()-1){
            allPath.push_back(path);
        }else{
            for(auto i:graph[idx]){
                dfs(i,graph,allPath,path);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>allPath;
        vector<int>path;
        dfs(0,graph,allPath,path);
        return allPath;
    }
};
