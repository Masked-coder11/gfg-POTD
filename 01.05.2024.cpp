/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

class Solution
{
    public:
    // task is to complete this function
    // function should return head to the list after making 
    // necessary arrangements
    struct Node* arrangeCV(Node *head)
    {
       //Code here
       if(!head || !head->next) return head;
       unordered_set<char> st={'a','e','i','o','u'};
       
       Node*temp=head, *tail;
       int cons=0, length=0;
       while(temp){
           if(st.find(temp->data)==st.end()){
               cons++;
           }
           length++;
           if(temp->next==NULL){
               tail=temp;
           }
           temp=temp->next;
       }
       
        if(cons==0 || length==cons){
            return head;
        }
        
            while(head && st.find(head->data)==st.end()){
                Node* x=head;
                head=head->next;
                tail->next=x;
                tail=x;
                x->next=NULL;
                cons--;
            }
        temp=head;
        Node*prev=NULL;
        while(cons){
            if(tail==temp){
                break;
            }
            if(st.find(temp->data)==st.end()){
                prev->next=temp->next;
                tail->next=temp;
                temp->next=NULL;
                tail=temp;
                cons--;
                temp=prev->next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
       
    }
};
