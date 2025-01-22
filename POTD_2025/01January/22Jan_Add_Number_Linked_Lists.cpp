class Solution {
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        
        num1 = reverseList(num1);
        num2 = reverseList(num2);

        Node* dummy = new Node(0);
        Node* temp = dummy;
        int carry = 0;

        while (num1 != nullptr || num2 != nullptr || carry != 0) {
            int sum = carry;

            if (num1 != nullptr) {
                sum += num1->data;
                num1 = num1->next;
            }

            if (num2 != nullptr) {
                sum += num2->data;
                num2 = num2->next;
            }

            carry = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;
        }

        return removeLeadingZeros(reverseList(dummy->next));
    }

  private:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    Node* removeLeadingZeros(Node* head) {
        while (head != nullptr && head->data == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        return head == nullptr ? new Node(0) : head;
    }
};
