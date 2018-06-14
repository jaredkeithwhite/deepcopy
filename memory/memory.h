//
// Created by Jared White on 6/8/18.
//

#ifndef MEMORY_MEMORY_H
#define MEMORY_MEMORY_H

#include "../node.h"

/**
 * This copy utility optimizes for minimal memory usage
 * at the considerable expense of time complexity and
 * cache coherence.
 *
 * * The time complexity is O(N^2).
 */
class copy_optimized_memory {
public:
    node* copy_list(node* rhs);

private:
    void assign_randoms(node* rhs, node* lhs);
    node* find_node(node* rootRhs, node* rootLhs, node* findRhs);
    node* copy_node(node* rhs, node* lhs);

};

#endif //MEMORY_MEMORY_H
