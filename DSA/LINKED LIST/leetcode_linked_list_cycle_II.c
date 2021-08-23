/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode* temp = head;   // node used for iteration
    struct ListNode* np = head;     // node used for comparison
    
    int count = 1, tempCount;   // Keep a count of nodes iterated
    
    //If list is empty return NULL
    if(head == NULL)
    {
        return NULL;
    }

    // Loop until end of list (Assume there is no cycle)
    while(temp->next != NULL)
    {
        np = head;  // Node to compare (Starting from head)
        tempCount = count;
        
        // Loop until (count of) nodes iterated until now
        while(tempCount > 0)
        {
            // If a address is matched
            if(np == temp->next)
                return np;
             
            np = np->next;   // Move to next comparison(np) node
            tempCount--;    //decrement temporary counter integer
        }
        
        // Increment iterating node(temp) and counter integer
        temp = temp->next;
        count++;
    }
    
    // If no nodes are matched then return NULL
    return NULL;
}