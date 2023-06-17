class Union {
    public:
    vector<int> parent, rank;
    Union(int n) {
        rank.resize(n);
        for(int i = 0; i < n; i++) 
            parent.push_back(i);
    }
    int findParent(int u) {
        return (u == parent[u]) ?
            u : parent[u] = findParent(parent[u]);
    }
    void unite(int u ,int v) {
        u = findParent(u);
        v = findParent(v);
        if(u != v) {
            parent[u] = min(u, v);
            parent[v] = min(u, v);
        }
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(begin(meetings),end(meetings),[&](auto &a, auto &b) {
            return a[2] < b[2];
        });
        Union u(n);
        u.unite(0, firstPerson);
        for(int i = 0; i < meetings.size(); ) {
            int time = meetings[i][2];
            int index = i;
            // for some time t, unite all people at once to avoid any confusion
            while(i < meetings.size() && time == meetings[i][2]) {
                // unite all the peoples
                u.unite(meetings[i][0], meetings[i][1]);
                i++;
            }
            while(index < i) {
                int x = meetings[index][0], y = meetings[index][1];
                // if people are still not aware of the secret
                if(u.findParent(x) != 0 && u.findParent(y) != 0) {
                    u.parent[x] = x;
                    u.parent[y] = y;
                }
                index++;
            }
        }
        // store how many people knows the secret
        vector<int> people;
        for(int i = 0; i < n; i++) {
            if(u.findParent(i) == 0) {
                people.push_back(i);
            }
        }
        return people;
    }
};