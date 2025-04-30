class Solution {
  public:
    // Function to detect and count the number of nodes in the loop
    int countNodesinLoop(Node *head) {
        Node *slow = head, *fast = head;
        
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return countLoopLength(slow);
            }
        }

        return 0;
    }

  private:
    int countLoopLength(Node *loopNode) {
        Node *temp = loopNode;
        int count = 1;
        while (temp->next != loopNode) {
            count++;
            temp = temp->next;
        }

        return count;
    }
};
