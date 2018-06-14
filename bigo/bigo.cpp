//
// Created by Jared White on 6/13/18.
//

#include "bigo.h"

/*
 * @param node* rhs - the right hand (root) node that we are copying
 */
node* copy_optimized_bigo::copy_list(node* rhs) {
    node* root = new node();
    copy_node(rhs, root);
    mapping.clear();
    return root;
}

/*
 * Copies a single node, and recursively copies the `next` member
 * as well.
 *
 * @param node* rhs - the right hand side that we are copying
 * @param node* lhs - the left hand side that we are copying
 */
node* copy_optimized_bigo::copy_node(node* rhs, node* lhs) {
    lhs->text = rhs->text;

    if (lhs->random == nullptr) {
        // create placeholder or find placeholder
        // this finds if we've encountered `random` as `next`
        // this creates if we've not encountered it yet
        lhs->random = find_or_create(rhs->random);
    }

    if (rhs->next == nullptr) {
        return nullptr;
    } else {
        node* lhsNext = find_or_create(rhs->next);
        lhs->next = lhsNext;
        return copy_node(rhs->next, lhsNext);
    }
}

/*
 * Finds a node in our mapping dictionary, otherwise creates it and
 * inserts it into the map.
 *
 * @param node* rhs - the node to find in our unordered map.
 *
 */
node* copy_optimized_bigo::find_or_create(node* rhs) {
    auto found = mapping.find(rhs);
    if (found != mapping.end()) {
        return found->second;
    } else {
        node* newNode = new node();
        auto result = mapping.insert(std::make_pair(rhs, newNode));
        return result.first->second;
    }
}
