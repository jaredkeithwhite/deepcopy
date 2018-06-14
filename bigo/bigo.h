//
// Created by Jared White on 6/8/18.
//

#ifndef BIGO_BIGO_H
#define BIGO_BIGO_H

#include <unordered_map>
#include "../node.h"

/**
 * This copy utility optimizes for big-o time complexity
 * at the expense of a memory consumption penalty, which
 * is an additional 16 bytes for each node in the source,
 * plus a minor overhead for the unordered map table structure.
 *
 * The time complexity is O(N).
 */
class copy_optimized_bigo {
public:
    node* copy_list(node* rhs);

private:
    node* copy_node(node* rhs, node* lhs);
    node* find_or_create(node* rhs);

private:
    std::unordered_map<node*, node*> mapping;

};

#endif //BIGO_BIGO_H
