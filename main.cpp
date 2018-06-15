#include <iostream>
#include <ctime>

#include "bigo/bigo.h"
#include "memory/memory.h"

node* get_nth_node(node* root, int nth) {
    for (int i = 0; i < nth; ++i) {
        root = root->next;
    }
    return root;
}

node* create_random_list(int listLength) {
    node* root = new node();
    node* thisNode = root;
    for (int i = 0; i < listLength; ++i) {
        thisNode->text = std::to_string(i); // string from int
        thisNode->next = new node();
        thisNode = thisNode->next;
    }

    thisNode = root;
    for (int i = 0; i < listLength; ++i) {
        thisNode->random = get_nth_node(root, rand() % listLength);
        thisNode = thisNode->next;
    }

    return root;
}

void print_list(node* root, int listLength) {
    //std::cout << " === " << std::endl;

    node* thisNode = root;
    for (int i = 0; i < listLength; ++i) {
        //std::cout << "node " << thisNode->text << "->" << thisNode->random->text << std::endl;
        thisNode = thisNode->next;
    }

    //std::cout << " === " << std::endl;
}

bool validate_list(node* rhs, node* lhs) {
    if (rhs == nullptr || lhs == nullptr) {
        throw std::runtime_error("input list rhs or lhs was null");
    }
    while (rhs->next != nullptr) {
        if (rhs->text != lhs->text) {
            throw std::runtime_error("node " + rhs->text + " was not equal to " + lhs->text);
        }
        rhs = rhs->next;
        lhs = lhs->next;
    }
    return true;
}

int main() {
    srand(time(nullptr));

    int listLength = 25000;
    node* list = create_random_list(listLength);
    print_list(list, listLength);

    copy_optimized_bigo copyBigO;
    node* bigOCopy = copyBigO.copy_list(list);
    print_list(bigOCopy, listLength);

    copy_optimized_memory copyMem;
    node* memCopy = copyMem.copy_list(list);
    print_list(memCopy, listLength);

    validate_list(list, bigOCopy);
    validate_list(list, memCopy);

    delete list;
    delete bigOCopy;
    delete memCopy;

    return 0;
}