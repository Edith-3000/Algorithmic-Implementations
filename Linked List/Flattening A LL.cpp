// Prob: https://www.geeksforgeeks.org/flattening-a-linked-list/
//       https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// Ref: https://www.youtube.com/watch?v=ysytSSXpAI0&list=PLgUwDviBIf0r47RKH7fdWN54AbWFgGuii&index=12

/**************************************************************************************************************************************************************/

// NOTE: Below codes are only the methods for flattening not the entire CPP code.

/**************************************************************************************************************************************************************/

// METHOD - 1 (RECURSIVE APPROACH)

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
		data = x;
	    next = NULL;
	    bottom = NULL;
	}	
};

Node* merge_2_sorted_lists(Node *t1, Node *t2) {
	if(t1 == NULL) return t2;
	if(t2 == NULL) return t1;
	
	Node *dummy = new Node(0);
	Node *tmp = dummy;
	
	while(t1 and t2) {
		if(t1->data <= t2->data) {
	    	tmp->bottom = t1;
	        tmp = tmp->bottom;
	        t1 = t1->bottom;
	    }
	    
	    else {
	        tmp->bottom = t2;
	        tmp = tmp->bottom;
	        t2 = t2->bottom;
	    }
	}
	
	if(t1) tmp->bottom = t1;
	if(t2) tmp->bottom = t2;
	
	return dummy->bottom;
}

// Function which returns the root of the flattened linked list.
Node *flatten(Node *root) {
   // base case(s)
   if(root == NULL or root->next == NULL) return root;
   
   // flatten all the lists on the right of the current list i.e.
   // recur for list on right
   root->next = flatten(root->next);
   
   // now flatten the current list and result obtained from above step
   root = merge_2_sorted_lists(root, root->next);
   
   return root;
}

/**************************************************************************************************************************************************************/

// METHOD - 2 (ITERATIVE APPROACH)

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}	
};

Node* merge_2_sorted_lists(Node *t1, Node *t2) {
	if(t1 == NULL) return t2;
	if(t2 == NULL) return t1;
	
	Node *dummy = new Node(0);
	Node *tmp = dummy;
	
	while(t1 and t2) {
		if(t1->data <= t2->data) {
	    	tmp->bottom = t1;
	        tmp = tmp->bottom;
	        t1 = t1->bottom;
	    }
	    
	    else {
	        tmp->bottom = t2;
	        tmp = tmp->bottom;
	        t2 = t2->bottom;
	    }
	}
	
	if(t1) tmp->bottom = t1;
	if(t2) tmp->bottom = t2;
	
	return dummy->bottom;
}

// Function which returns the root of the flattened linked list.
Node *flatten(Node *root) {
   if(root == NULL or root->next == NULL) return root;
   
   bool is_start = 1;
   Node *res_head = NULL, *nxt = root->next;
   
   while(nxt) {
       if(is_start == 1) {
           Node *tmp = nxt->next;
           res_head = merge_2_sorted_lists(root, nxt);
           nxt = tmp;
           is_start = 0;
       }
       
       else {
           Node *tmp = nxt->next;
           res_head = merge_2_sorted_lists(res_head, nxt);
           nxt = tmp;
       }
   }
   
   return res_head;
}