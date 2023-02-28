#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

void push(Node** head_ref, int new_data) {
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next =(*head_ref);
    (*head_ref) = new_node;
}

void insert_at_position(Node** head_ref,int pos,int data) {
    Node *temp = new Node();
    temp = (*head_ref);
    int size=0;
    while(temp != NULL) {
        size += 1;
        temp=temp->next;
    }
    if(pos < 1 || pos>size+1) {
        cout<<"invalid position";
    }
    else if(pos == 1) {
        push(head_ref,data);
    }
    else {
        Node* temp1 = new Node();
        temp1->data = data;
        temp1->next = NULL;
        Node* temp2 = *head_ref;
        for(int i=0; i<pos-2; i++){
            temp2=temp2->next;
        }
        temp1->next=temp2->next;
        temp2->next=temp1;
    }
}

void deleteNode(Node** head_ref, int position) {
    if (*head_ref == NULL)
    return;
    Node* temp = *head_ref;
    if (position == 1) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 1; temp != NULL && i <position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;
    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void print(Node *node) {
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

int main() {
    Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    cout<<"Initial List - ";
    print(head);
    cout<<"\n";
    insert_at_position(&head,2,9);
    cout<<"List After Insertion - ";
    print(head);
    cout<<"\n";
    deleteNode(&head,3);
    cout<<"List After Deletion - ";
    print(head);
    return 0;
}