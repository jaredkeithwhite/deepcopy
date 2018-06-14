# Linked List Deep Copy

## Running the App

Running the app is a matter of compiling and executing:

    mkdir cmake-build-dir && cd cmake-build-dir
    cmake .. && make && ./deepcopy


There are no parameters, it's meant for demonstration purposes only.

The app creates a test list with randomly assigned `random` members
for each node, and then performs a `deep copy` of this list using
both copy utilities.

These copy utilities are described below.

## Optimized BigO

The BigOp optimized copy utility is meant to optimize the
operations performed to copy the list, at the expense of a modest
memory consumption penalty.

The BigO optimized copy utility will create a `std::unordered_map`, which
maps the `rhs` pointer to it's copied node (i.e., the `lhs`).

This `std::unordered_map` is the source of the additional memory consumption.

The copy operation works like this:
  - iterate the `rhs` list and create a copy (`lhs`) for each node
  - search for the `lhs`'s `random` member in the mapping using the key
    of the `rhs`'s `random` member pointer
    - if the `rhs`'s `random` pointer is not found in the mapping, create a placeholder for it
    - this placeholder will be found when searching for an eventual `next`
  - create or find the `lhs`'s `next` node by searching for the `rhs`'s `next` pointer
  - recursively perform the above steps for the `rhs`'s `next` member

Unless memory constraints are severe, larger lists should be copied using this operation.

## Optimized Memory Consumption

The Memory Consumption optimized copy utility is meant to minimize the
memory consumed by the deep copy operation at the expense of cache coherence
and number of operations performed.

The copy operation works like this:
  - iterate the `rhs` list and create a copy (`lhs`) for each node
  - recursively perform the copy operation for the `rhs`'s `next` member
  - iterate the `rhs` list again simultaneously with the `lhs` operation
    - for each `rhs` node (`rhs1`), iterate the `rhs` and `lhs` nodes simultaneously to find the `rhs1`'s `random` node
    - assign the current `lhs`'s `random` node to `lhs1`
    - assign `lhs`'s `random` node to this discovered `lhs1` node

I would highly recommend avoiding this utility except for the smallest of
linked lists, where the overhead of `2` `unordered_map` lookups and an
`insert` for each node would exceed the expense of `rhs` list iteration.

In my estimation, lists of under approximately `5-10` nodes fit this pattern.