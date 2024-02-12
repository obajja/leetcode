#include <iostream>
#include <stack>

using namespace std;
/*
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLinkedList(ListNode* head){
    ListNode* current = head;
    while(current != nullptr){
        cout << current->val;
        if (current -> next != nullptr){
            cout << "-->";
        }
        current = current -> next;
    }
    cout << endl << endl;
}

ListNode *reverseList(ListNode *head) {
    if (head == nullptr){
        return nullptr;
    }
    stack<ListNode*> s;
    ListNode* current = head;
    while (current != nullptr){
        s.push(current);
        current = current -> next;
    }
    ListNode* current2;
    ListNode* newHead = s.top();
    while(!s.empty()){
        current2 = s.top();
        s.pop();
        if (!s.empty()){
            current2 -> next = s.top();
        } else{
            current2 -> next = nullptr;
        }
    }
    return newHead;
}

int main() {

    ListNode* head = new ListNode(0);
    ListNode* node1 = new ListNode(1);
    //ListNode* node2 = new ListNode(2);
    //ListNode* node3 = new ListNode(3);
    //ListNode* node4 = new ListNode(4);

    head -> next = node1;
    //node1 -> next = node2;
    //node2 -> next = node3;
    //node3 -> next = node4;

    //printLinkedList(head);
    printLinkedList(reverseList(nullptr));

    return 0;
}