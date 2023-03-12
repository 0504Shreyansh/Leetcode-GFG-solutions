class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        //Available items
        unordered_set<string> s;
        for(auto item : supplies)
            s.insert(item);      
		
        //Initialise the indegrees of recipes with 0
        unordered_map<string,int> indegree;  
        for(auto food : recipes)
            indegree[food] = 0;  
    
        unordered_map<string,vector<string>> graph;
        int n = recipes.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < (int)ingredients[i].size(); j++) {
            //ing[i][j] is not avilable in the supply list, so we can assume a directed edge.
            //This means ing[i][j] is needed for making rec[i] (++inDegree[rec[i]])
                if(s.find(ingredients[i][j]) == s.end()){     
                    graph[ingredients[i][j]].push_back(recipes[i]); 
                    indegree[recipes[i]]++;          
                }
            }
        }
        
        //cnt==0 means these items can be made by the currently available supply list
        queue<string> q;
        for(auto [item,cnt] : indegree)
            if(cnt==0)
                q.push(item);
        
        vector<string> res;
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            res.push_back(cur);
            //inDegree cnt zero further signifies we have satisfied the needs of the current rec.
            for(auto nbr : graph[cur])
                if(--indegree[nbr]==0)
                    q.push(nbr);
        }
        return res;
        
    }
};