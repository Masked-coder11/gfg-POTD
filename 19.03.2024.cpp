//User function template for C++

class Solution{
	
	int ans;

	private:
	//Function to find the root of the given element in the disjoint set.
	int root(int i, vector<int> &parent)
	{
	    while(parent[i]!=i)
	    {
	        parent[i] = parent[parent[i]];
	        i = parent[i];
	    }
	    return i;
	}

	//Function to perform union operation of two sets and return the resulting size of the set.
    int Union(int a, int b, vector<int> &parent, vector<int> &sz)
    {
    	int ra = root(a, parent);
	    int rb = root(b, parent);
	    
	    //If the roots are the same, it means they are already in the same set,
	    //so return the current size of the set.
	    if(ra == rb)
	        return sz[ra]*sz[ra];
	    
	    //If the size of the set containing a is smaller than the size of the set containing b,
	    //then swap a and b.
	    if(sz[ra] < sz[rb])
	    {
	        swap(ra,rb);
	        swap(a,b);
	    }
	    
	    //Merge the two sets by updating the parent and size.
	    ans += sz[ra]*sz[rb];
	    parent[rb] = ra;
	    sz[ra] += sz[rb];
	 
	    return ans;
    }
 
	public:
	vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
	{
		ans = 0;

		vector<int> parent(n+1, 0), sz(n+1, 0);
		for(int i = 0;i <= n; i++)
		{
            //Initializing each element as its own parent and size as 1.
            parent[i] = i;
            sz[i] = 1;
        }

        //Creating a vector of pairs to store the weights and the endpoints of the edges.
        vector<pair<int, pair<int, int>>> wt;
       	for(int i = 0; i < n-1; i++)
           	wt.push_back({edges[i][2] , {edges[i][0], edges[i][1]}}); 
        
        //Sorting the edges based on their weights in ascending order.
        sort(wt.begin() , wt.end());

        //Creating a map to store the maximum weight of the connected component with weights less than or equal to each query.
        map<int, int> mp;

        //Iterating through the sorted edges and performing union operation.
        for(int i = 0;i < n-1; i++){
            int a = wt[i].first;
            int b = wt[i].second.first;
            int c = wt[i].second.second;
 
            //Updating the map with the maximum weight of the connected component after each union operation.
            mp[a] = Union(b, c, parent, sz);  
        }

        //Creating a vector to store the results for each query.
        vector<int> res;

        //Iterating through each query and finding the maximum weight with weights less than or equal to the query.
        for(int i = 0; i < q; i++)
        {
           	//Finding the element in the map which is just greater than the query.
           	auto val = mp.upper_bound(queries[i]);
            if(val == mp.begin())
                res.push_back(0); //If there is no such element, then the maximum weight is 0.
            else
            {
                val--;
                res.push_back(val->second); //Storing the maximum weight for the query.
            }
       	}
       	return res;
	}
};
