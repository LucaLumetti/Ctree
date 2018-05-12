
#ifndef CTREE_H
#define CTREE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef CTREE_TYPE
#define CTREE_TYPE int
#endif

typedef CTREE_TYPE tree_type;

struct tree_node {
  tree_type value;
  struct tree_node *left, *right;
};

typedef struct tree_node tree_node;
typedef struct tree_node* tree;

/* PRIMITIVE */
tree emptytree();
tree consTree(tree_type d, tree l, tree r);
tree left(tree t);
tree right(tree t);
tree_type root(tree t);
bool empty(tree t);

/* NON PRIMITIE */
tree appendLeft(tree_type d, tree t);
tree appendRight(tree_type d, tree t);
unsigned getHeight(tree t);
void preOrder(tree t);
void inOrder(tree t);
void postOrder(tree t);
tree getAbsPost(tree t);
void printTree(tree t);

/* getAbsPos follow this "draw"
 *      1
 *     / \
 *    /   \
 *   2     3
 *  / \   / \
 * 4   5 6   7
 * etc..
 */

#endif /* CTREE_H */
