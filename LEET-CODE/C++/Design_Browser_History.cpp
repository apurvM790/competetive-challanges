// we design doubly linked list nodes to move forward and backward in the list.....
// Node class for structure of the node..
class Node{
public:
    string data;
    Node* next;
    Node* prev;

    Node(string data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
        
    }
};

class BrowserHistory {
public:
    // creating head as a dummy node
    Node* head=new Node("-1");
    Node* temp=nullptr;
    BrowserHistory(string homepage) {

        head->next=new Node(homepage);
        temp=head->next;
    }
    
    void visit(string url) {
        temp->next=new Node(url);
        temp->next->prev=temp;
        temp=temp->next;
        
    }
    
    string back(int steps) {

        while(steps and temp->prev!=nullptr)
        {
            steps--;
            temp=temp->prev;
        }
        return temp->data;
        
        
    }
    
    string forward(int steps) {

        while(steps and temp->next!=nullptr)
        {
            steps--;
            temp=temp->next;
        }
        return temp->data;
        

    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
