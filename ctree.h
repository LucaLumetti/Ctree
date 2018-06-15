#ifndef CTREE_H
#define CTREE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* PRIMITIVE */
/*
tree emptytree();
tree consTree(tree_type d, tree l, tree r);
tree left(tree t);
tree right(tree t);
tree_type root(tree t);
bool empty(tree t);

*//* NON PRIMITIE *//*
tree appendLeft(tree_type d, tree t);
tree appendRight(tree_type d, tree t);
unsigned getHeight(tree t);
void preOrder(tree t);
void inOrder(tree t);
void postOrder(tree t);
tree getAbsPos(tree t);
void printTree(tree t);
*/
#define INIT_TREE(NAME, TYPE, CMPFN, COPYFN, PRINTFN)                         \
struct tree_##NAME##_node {                                                   \
  TYPE value;                                                                 \
  struct tree_##NAME##_node *left, *right;                                    \
};                                                                            \
                                                                              \
typedef struct tree_##NAME##_node tree_##NAME##_node;                         \
typedef struct tree_##NAME##_node* tree_##NAME;                               \
/* ------- Definitions ------- */                                             \
                                                                              \
extern tree_##NAME tree_##NAME##_new();                                       \
extern tree_##NAME tree_##NAME##_cons(TYPE d, tree_##NAME l, tree_##NAME r);  \
extern tree_##NAME left(tree_##NAME t);                                       \
extern tree_##NAME right(tree_##NAME t);                                      \
extern TYPE tree_##NAME##_root(tree_##NAME t);                                \
extern bool tree_##NAME##_isEmpty(tree_##NAME t);                             \
                                                                              \
/* -------- Functions -------- */                                             \
                                                                              \
/* -- tree tree_new() -- */                                                   \
tree_##NAME tree_##NAME##_new(){                                              \
  return NULL;                                                                \
}                                                                             \
                                                                              \
/* -- tree tree_cons(type d, tree l, tree r) -- */                            \
tree_##NAME tree_##NAME##_cons(TYPE d, tree_##NAME l, tree_##NAME r){         \
  tree_##NAME t = malloc(sizeof(tree_##NAME##_node));                         \
  t->value = (COPYFN)(d);                                                     \
  t->left = l;                                                                \
  t->right = r;                                                               \
  return t;                                                                   \
}                                                                             \
                                                                              \
/* -- tree tree_left(tree t) -- */                                            \
tree_##NAME tree_##NAME##_left(tree_##NAME t){                                \
  if(t == NULL)                                                               \
    return NULL;                                                              \
  return t->left;                                                             \
}                                                                             \
                                                                              \
/* -- tree tree_right(tree t) -- */                                           \
tree_##NAME tree_##NAME##_right(tree_##NAME t){                               \
  if(t == NULL)                                                               \
    return NULL;                                                              \
  return t->right;                                                            \
}                                                                             \
                                                                              \
TYPE tree_##NAME##_root(tree_##NAME t){                                       \
  if(tree_##NAME##_isEmpty(t))                                                \
    abort();                                                                  \
  return t->value;                                                            \
}                                                                             \
                                                                              \
bool tree_##NAME##_isEmpty(tree_##NAME t){                                    \
  return t == NULL;                                                           \
}                                                                             \
                                                                              \
unsigned tree_##NAME##_getHeight(tree_##NAME t){                              \
  if(tree_##NAME##_isEmpty(t))                                                \
    return 0;                                                                 \
  unsigned hl = tree_##NAME##_getHeight(tree_##NAME##_left(t));               \
  unsigned hr = tree_##NAME##_getHeight(tree_##NAME##_right(t));              \
  return 1+((hl>hr)?hl:hr);                                                   \
}                                                                             \
                                                                              \
void tree_##NAME##_preOrder(tree_##NAME t) {                                  \
  if(tree_##NAME##_isEmpty(t))                                                \
    return;                                                                   \
  (PRINTFN)(tree_##NAME##_root(t));                                           \
  printf(" ");                                                                \
  tree_##NAME##_preOrder(tree_##NAME##_left(t));                              \
  tree_##NAME##_preOrder(tree_##NAME##_right(t));                             \
}                                                                             \
                                                                              \
void tree_##NAME##_inOrder(tree_##NAME t) {                                   \
  if (tree_##NAME##_isEmpty(t))                                               \
    return;                                                                   \
  tree_##NAME##_inOrder(tree_##NAME##_left(t));                               \
  (PRINTFN)(tree_##NAME##_root(t));                                           \
  printf(" ");                                                                \
  tree_##NAME##_inOrder(tree_##NAME##_right(t));                              \
}                                                                             \
                                                                              \
void tree_##NAME##_postOrder(tree_##NAME t) {                                 \
  if(tree_##NAME##_isEmpty(t))                                                \
    return;                                                                   \
  tree_##NAME##_postOrder(tree_##NAME##_left(t));                             \
  tree_##NAME##_postOrder(tree_##NAME##_right(t));                            \
  (PRINTFN)(tree_##NAME##_root(t));                                           \
  printf(" ");                                                                \
}

#endif /* CTREE_H */
