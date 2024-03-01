#include "llrec.h"
#include "iostream"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot);

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return; 
    }

    llpivot(head->next, smaller, larger, pivot);

    // std::cout << head->val << "\n";
    if(head->val <= pivot) {
        // std::cout << "Smaller\n";
        Node* temp = smaller;
        smaller = head;
        smaller->next = temp;
    } else {
        // std::cout << "Larger\n";
        Node* temp = larger;
        larger = head;
        larger->next = temp;
    }

    head = nullptr;
    return;

    // std::cout << head->val << "\n";

    // if (head->val <= pivot) {
    //     // std::cout << "smaller" << "\n";
    //     if(smaller == nullptr) {
    //         smaller = head;
    //         head = head->next;
    //         smaller->next = nullptr;
    //         return llpivot(head, smaller, larger, pivot);
    //     } else {
    //         smaller->next = head;
    //         head = head->next;
    //         smaller->next->next = nullptr;
    //         return llpivot(head, smaller->next, larger, pivot);
    //     }

       
    // } else if (head->val > pivot) {
    //     // std::cout << "larger" << "\n";
    //     if(larger == nullptr) {
    //         larger = head;
    //         head = head->next;
    //         larger->next = nullptr;
    //         return llpivot(head, smaller, larger, pivot);
    //     } else {
    //         larger->next = head;
    //         head = head->next;
    //         larger->next->next = nullptr;
    //         return llpivot(head, smaller, larger->next, pivot);
    //     }
    // }
}