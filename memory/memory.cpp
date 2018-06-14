//
// Created by Jared White on 6/13/18.
//

#include "memory.h"

/*
 * An ill-advised bruce force search through the rhs list for the
 * desired node.  We iterate on the lhs list at the same rate as the rhs
 * list, and return the lhs node when the rhs match is found.
 *
 * @param node* rhs - the right hand side (root) node
 * @param node* lhs - the left hand side (root) node
 */
node* copy_optimized_memory::find_node(node* rhs, node* lhs, node* find) {
    if (find == nullptr) return nullptr;

    while (rhs != find && rhs != nullptr && lhs != nullptr) {
        rhs = rhs->next;
        lhs = lhs->next;
    }
    if (rhs == nullptr) {
        return nullptr;
    } else {
        return lhs;
    }
}

/*
 * Creates the deep copy of the list.
 */
node* copy_optimized_memory::copy_list(node* rhs) {
    node* lhs = new node();
    copy_node(rhs, lhs);

    assign_randoms(rhs, lhs);
    return lhs;
}

/*
 * Once we have created the lhs list, we iterate on it again to
 * find and assign the random nodes.
 */
void copy_optimized_memory::assign_randoms(node* rhs, node* lhs) {
    node* rootRhs = rhs;
    node* rootLhs = lhs;
    while (lhs != nullptr) {
        lhs->random = find_node(rootRhs, rootLhs, rhs->random);
        rhs = rhs->next;
        lhs = lhs->next;
    }
}

/*
 * Copies a node from the rhs to the lhs, and then recursively
 * copies the `next` members.
 */
node* copy_optimized_memory::copy_node(node* rhs, node* lhs) {
    lhs->text = rhs->text;
    if (rhs->next == nullptr) {
        return nullptr;
    } else {
        node* newLhs = new node();
        lhs->next = newLhs;
        return copy_node(rhs->next, newLhs);
    }
}