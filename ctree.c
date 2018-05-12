#include "ctree.h"

tree emptytree(){
  return NULL;
}

tree consTree(tree_type d, tree l, tree r){
  tree t = malloc(sizeof(tree_node));
  t->value = d;
  t->left = l;
  t->right = r;
  return t;
}

tree left(tree t){
  if(t == NULL)
    return NULL;
  return t->left;
}

tree right(tree t){
  if(t == NULL)
    return NULL;
  return t->right;
}

tree_type root(tree t){
  if(empty(t))
    abort();
  return t->value;
}

bool empty(tree t){
  return t == NULL;
}

/* NON PRIMITIVE */
tree appendLeft(tree_type d, tree t){
  if(t == NULL)
    return consTree(d, NULL, NULL);
  if(t->left != NULL)
    free(t->left); //TODO: destroy(t->left)
  t->left = consTree(d, NULL, NULL);
  return t;
}

tree appendRight(tree_type d, tree t){
  if(t == NULL)
    return consTree(d, NULL, NULL);
  if(t->right != NULL)
    free(t->right); //TODO: destroy(t->right)
  t->right = consTree(d, NULL, NULL);
  return t;
}

unsigned getHeight(tree t){
  if(empty(t))
    return 0;
  unsigned hl = getHeight(t->left);
  unsigned hr = getHeight(t->right);
  return 1+((hl>hr)?hl:hr);
}

void preOrder(tree t) {
  if(empty(t))
    return;
  printf("%d\t", root(t));
  preOrder(left(t));
  preOrder(right(t));
}

void inOrder(tree t) {
  if (empty(t))
    return;
  inOrder(left(t));
  printf("%d\t", root(t));
  inOrder(right(t));
}

void postOrder(tree t) {
  if(empty(t))
    return;
  postOrder(left(t));
  postOrder(right(t));
  printf("%d\t", root(t));
}

int serie_a(int height){
  return (height == -1) ? 0 : 3*(1<<height)-1;
}

int serie_b(int height){
  if(height == -2)
    return 0;
  if(height == -1)
    return 1;
  return 3*(1<<height)-1;
}

tree getAbsPos(tree t, unsigned p){
  if(empty(t))
    return t;
  int dir = 1;
  while(p > 1){
    dir = (dir<<1)+(p%2);
    p = p>>1;
  }
  while(dir > 1){
    if(dir%2)
      t = right(t);
    else
      t = left(t);
    dir = dir>>1;
  }
  return t;
}

void printTree(tree t){
  printf("\n");
  unsigned height = getHeight(t);
  /* Blocchi (numero piu' /\) da stampare */
  for(int h = 0; h < height; h++){
    unsigned a = serie_a(height-h-1);
    unsigned b = serie_a(height-h-2);
    unsigned c = serie_b(height-h-3);
    /* stampo spazi a sx */
    for(int l = 0; l < b; l++)
      printf(" ");
    /* Stampo spazi tra i vari numeri */
    for(int j = 0; j < (1<<h); j++){
      tree k = getAbsPos(t, (1<<h)+j);
      if(k == NULL)
        printf("X");
      else
        printf("%d", root(k));
      for(int r = 0; r < ((h==height-1)?(((j%2==0)?a:b)+1):a); r++)
        printf(" ");
    }
    printf("\n");
    /* Stampo \n e /\ */
    for(int s = 0; s < c; s++){
      for(int y = 0; y < (1<<h); y++){
        for(int w = 0; w < b-s-1; w++)
          printf(" ");
        if(y != 0){
          for(int d = 0; d < b-s; d++)
            printf(" ");
        }
        printf("/");
        for(int x = 0; x < a-2*(b-s); x++)
          printf(" ");
        printf("\\");
      }
      printf("\n");
    }
  }
}
