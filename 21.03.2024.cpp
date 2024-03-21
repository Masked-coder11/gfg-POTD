//User function Template for C++

/*Structure of the node of the binary tree is as

struct Node {

    int data;

    Node *left;

    Node *right;



    Node(int val) {

        data = val;

        left = right = NULL;

    }

};

*/



class Solution{

    public:

    //Function to store the zig zag order traversal of tree in a list.

    vector <int> zigZagTraversal(Node* root)

    {

    	// Code here

    	vector<vector<int>>traversal;

    	queue<Node*>q;

    	q.push(root);

    	

    	while(!q.empty()){

    	    int n=q.size();

    	    vector<int>level;

    	    for(int i=0;i<n;i++){

    	        Node* node=q.front();

    	        q.pop();

    	        

    	        level.push_back(node->data);

    	        if(node->left){

    	            q.push(node->left);

    	        }

    	        if(node->right){

    	            q.push(node->right);

    	        }

    	    }

    	    traversal.push_back(level);

    	}

    	vector<int>ans;

    	for(int i=0;i<traversal.size();i++){

    	    if(i%2==1){

    	        reverse(traversal[i].begin(), traversal[i].end());

    	    }

    	    for(auto it:traversal[i]){

    	        ans.push_back(it);

    	    }

    	}

    	return ans;

    	

    	

    	

    }

};

