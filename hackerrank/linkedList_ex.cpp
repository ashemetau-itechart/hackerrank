//
//  linkedList_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 25.12.22.
//

#include "linkedList_ex.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <new>

using namespace std;


class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next = NULL;
    
    SinglyLinkedListNode(int data) {
        this->data = data;
    }
};

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if (head == nullptr) {
        return new SinglyLinkedListNode(data);
    }
    SinglyLinkedListNode* node = head;
    while (node->next) {
        node = node->next;
    }
    node->next = new SinglyLinkedListNode(data);
    return head;
}

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    if (llist == nullptr) {
        return new SinglyLinkedListNode(data);
    }
    SinglyLinkedListNode *head = new SinglyLinkedListNode(data);
    head->next = llist;
    return head;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        if (position == 0) {
            newNode->next = llist;
            return newNode;
        }
            
        SinglyLinkedListNode* node = llist;
        int pos = 0;
        while (node->next) {
            pos++;
            if (pos == position){
                SinglyLinkedListNode* nextNode = node->next;
                node->next = newNode;
                newNode->next = nextNode;
                break;
            }
            node = node->next;
        }
        return llist;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
        if (position == 0) {
            return llist->next;
        }
            
        SinglyLinkedListNode* node = llist;
        int pos = 0;
        while (node->next) {
            pos++;
            if (pos == position){
                node->next = node->next->next;
                break;
            }
            node = node->next;
        }
        return llist;
}

void printList(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode *node = llist;
    while (node) {
        cout<< node->data <<endl;
        node = node->next;
    }
}

SinglyLinkedListNode* reverseList(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode *current = llist;
    SinglyLinkedListNode *prev = nullptr;
    while (current) {
        SinglyLinkedListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    llist = prev;
    return llist;
}


bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* node1 = head1;
    SinglyLinkedListNode* node2 = head2;
     while (node1 && node2) {
            if (node1->data != node2->data) {
                return false;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
    return !node1 && !node2;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (!head1) {
        return head2;
    } else if (!head2){
        return head1;
    }
    
    SinglyLinkedListNode* node1 = head1;
    SinglyLinkedListNode* node2 = head2;
    SinglyLinkedListNode *head = nullptr;
    SinglyLinkedListNode *tail = nullptr;
    while (node1 && node2) {
        SinglyLinkedListNode *node;
        if (node1->data < node2->data){
            node = node1;
            node1 = node1->next;
        } else {
            node = node2;
            node2 = node2->next;
        }
        if (tail == nullptr) {
            tail = node;
            head = tail;
        } else {
            tail->next = node;
            tail = tail->next;
        }
    }
    tail->next = node1 ? node1 : node2;
    return head;
}

int getNodeFromTailPosition(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode *node = llist;
    SinglyLinkedListNode *temp = llist;
    
    int dist = 0;
    
    while (temp->next) {
        temp = temp->next;
        dist++;
        if (dist>=positionFromTail+1){
            node = node->next;
        }
    }
    return  node->data;
}

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode *node = llist;
    SinglyLinkedListNode *head = node;
    SinglyLinkedListNode *temp = node;
    while (temp) {
        if (node->data != temp->data){
            node->next = temp;
            node = node->next;
        }
        temp = temp->next;
    }
    node->next = nullptr;
    return head;
}

bool has_cycle(SinglyLinkedListNode* head) {
    if (head == nullptr) return false;
    SinglyLinkedListNode *pointer = head;
    SinglyLinkedListNode *fastPointer = head;
    while (fastPointer != nullptr && fastPointer->next != nullptr) {
        pointer = pointer->next;
        fastPointer = fastPointer->next->next;
        if (pointer == fastPointer) return true;
    }
    return false;
}

void linkedList_ex(){
    SinglyLinkedListNode *list = NULL;
    list = insertNodeAtTail(list, 1);
    list = insertNodeAtTail(list, 2);
    list = insertNodeAtTail(list, 3);
    list = insertNodeAtTail(list, 4);
    list = insertNodeAtTail(list, 5);
    list = insertNodeAtTail(list, 6);
    list = insertNodeAtHead(list, 0);
//    list = reverseList(list);
//    printList(list);
    
    SinglyLinkedListNode *list2 = NULL;
    list2 = insertNodeAtTail(list2, 1);
    list2 = insertNodeAtTail(list2, 2);
    list2 = insertNodeAtTail(list2, 5);
    
    int v = getNodeFromTailPosition(list, 2);
}

class DoublyLinkedListNode {
public:
    int data;
    DoublyLinkedListNode* next = NULL;
    DoublyLinkedListNode* prev = NULL;
    
    DoublyLinkedListNode(int data) {
        this->data = data;
    }
    
    DoublyLinkedListNode(int data, DoublyLinkedListNode* next, DoublyLinkedListNode* prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    
};

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    if (llist->data > data) {
        DoublyLinkedListNode *root = new DoublyLinkedListNode(data, llist, NULL);
        llist->prev = root;
        return root;
    }
    
    DoublyLinkedListNode *node = llist;
    while (node->next != NULL && node->next->data < data) {
        node = node->next;
    }
    
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data, node->next, node);
    if (node->next != NULL){
        node->next->prev = newNode;
    }    
    node->next = newNode;
    
    return llist;
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode *node = llist;
    while (1) {
        DoublyLinkedListNode *temp = node->next;
        node->next = node->prev;
        node->prev = temp;
        if (temp == NULL){
            break;
        }
        node = temp;
    }
    return node;
}


void doublyLinkedList_ex(){
    DoublyLinkedListNode *sortedList = new DoublyLinkedListNode(1);
    DoublyLinkedListNode *node = sortedList;
    DoublyLinkedListNode *nextNode = new DoublyLinkedListNode(3, NULL, node);
    node->next = nextNode;
    node = nextNode;
    nextNode = new DoublyLinkedListNode(4, NULL, node);
    node->next = nextNode;
    node = nextNode;
    nextNode = new DoublyLinkedListNode(10, NULL, node);
    node->next = nextNode;
    
//    sortedList = sortedInsert(sortedList, 11);
    DoublyLinkedListNode *reversedList = reverse(sortedList);
}
