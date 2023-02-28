#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int val;
    Node* next;
 };
 
void insert(Node** head,int data) {
    Node* new_node = new Node();
    new_node->val = data;
    new_node->next  = *head;
    *head = new_node;
}

void display(Node* head_ref) {
    Node* temp = head_ref;
    while(temp != nullptr) {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
 }

 Node* add(Node* list1,Node* list2) {
    Node* dummy = new Node();
    Node* temp = dummy;
    int carry = 0;
    while(list1 != NULL || list2 != NULL || carry) {
        int sum =0;
        if(list1 != NULL) {
            sum += list1->val;
            list1 = list1->next;
        }
        if(list2 != NULL) {
            sum += list2->val;
            list2 = list2->next;
        }
        sum += carry;
        carry = sum/10;
        Node* node = new Node();
        node->val = sum%10;
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}

int main() {
   Node* list1= nullptr;
   insert(&list1,2);
   insert(&list1,9);
   insert(&list1,5);
   display(list1);
   cout<<"\n";
   Node* list2= nullptr;
   insert(&list2,5);
   insert(&list2,1);
   insert(&list2,7);
   display(list2);
   Node* ans = add(list1,list2);
   cout<<"\n";
   display(ans);
   return 0;
}