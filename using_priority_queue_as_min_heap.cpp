/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct compare{
	bool operator(ListNode* a, ListNode*b){
		return a->val > b->val;
	}
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    ListNode* list;
    priority_queue <ListNode*, vector<ListNode*>, compare> min_heap;
    for (int i = 0; i < A.size(); ++i) {
    	for (std::vector<ListNode>::iterator it=A[i].begin(); it!=A[i].end(); ++it){
    		min_heap.push(*it);
  	  }
    }
    

    ListNode *head=NULL;

    while(!min_heap.empyt()){
    	ListNode *temp = min_heap.top();
    	temp->next = NULL;
    	if (head==NULL){
    		head = temp;
    	}

    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
