// Prob: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/********************************************************************************************************************************************/

// NOTE: Below codes are only the methods for flattening not the entire CPP code.

/********************************************************************************************************************************************/

// METHOD - 1 [O(n^2)]

// Definition for a Node.
class Node {
	public:
	    int val;
	    Node* prev;
	    Node* next;
	    Node* child;
};

Node* flatten(Node* head) {
    if(head == NULL) return head;
    
    Node* itr = head;
    
    while((itr != NULL) and (itr->child == NULL)) {
        itr = itr->next;
    }
    
    if(itr == NULL) return head;
    
    Node *child_head = flatten(itr->child);
    Node *child_tail = child_head;
    
    while(child_tail->next != NULL) {
        child_tail = child_tail->next;
    }
    
    child_tail->next = itr->next;
    if(itr->next != NULL) itr->next->prev = child_tail;
    
    itr->next = child_head;
    child_head->prev = itr;
    
    itr->child = NULL;
    
    return head;
}

/********************************************************************************************************************************************/

// METHOD - 2 [O(n), USING IMPLICIT STACK (or BY RECUSRION)]
// Ref: https://www.youtube.com/watch?v=RIyPgR7AF7M&ab_channel=KnowledgeCenter

// Definition for a Node.
class Node {
	public:
	    int val;
	    Node* prev;
	    Node* next;
	    Node* child;
};

Node* helper(Node* head) {
    if(!head) return head;
    
    Node *cur = head, *tail = head;
    
    while(cur != NULL) {
        if(cur->child != NULL) {
            Node *child_tail = helper(cur->child);
            
            child_tail->next = cur->next;
            if(cur->next != NULL) cur->next->prev = child_tail;
            
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = NULL;
            
            cur = tail;
        }
        
        else {
            tail = cur;
            cur = cur->next;
        }
    }
    
    return tail;
}

Node* flatten(Node* head) {
    helper(head);
    return head;
}

/********************************************************************************************************************************************/

// METHOD - 3 [O(n), USING EXPLICIT STACK (or BY ITERATION)]
// Ref: https://www.youtube.com/watch?v=F-oPHhK1em0&ab_channel=Codebix

// Definition for a Node.
class Node {
	public:
	    int val;
	    Node* prev;
	    Node* next;
	    Node* child;
};

Node* flatten(Node* head) {
    if(!head) return head;
    
    Node *cur = head, *tail = head;
    
    stack<Node*> stk;
    
    while(cur != NULL) {
        if(cur->child != NULL) {
            if(cur->next != NULL) {
                cur->next->prev = NULL;
                stk.push(cur->next);
            }
            
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = NULL;
        }
        
        tail = cur;
        cur = cur->next;
    }
    
    while(!stk.empty()) {
        cur = stk.top();
        stk.pop();
        
        tail->next = cur;
        cur->prev = tail;
        
        while(cur != NULL) {
            tail = cur;
            cur = cur->next;
        }
    }
    
    return head;
}