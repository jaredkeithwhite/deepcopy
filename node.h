//
// Created by Jared White on 6/8/18.
//

#ifndef NODE_NODE_H
#define NODE_NODE_H

#include <string>

struct node {
    node() : next(nullptr), random(nullptr) { }
    ~node() {
        delete next;
    }
    std::string text;
    node* next;
    node* random;
};

#endif //NODE_NODE_H

