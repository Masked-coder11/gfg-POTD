//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insert(Node* newNode, Node* ans){
        if(ans == NULL){
            newNode->next = ans;
            ans = newNode;
        }
        else if(ans->data > newNode->data){
            newNode->next = ans;
            ans = newNode;
        }
        else{
            Node *temp=ans;
            while(temp->next !=NULL && temp->next->data <= newNode->data){
                temp=temp->next;
            }
            newNode->next = temp->next;
            temp->next= newNode;
        }
        
        return ans;
    }
    
    Node* insertionSort(struct Node* head)
    {
        //code here
        if(!head || !head->next){
            return head;
        }
        Node* ans=NULL;
        while(head != NULL){
            Node* next = head->next;
            ans = insert(head, ans);
            head = next;
        }
        
        return ans;
    }
    
};
