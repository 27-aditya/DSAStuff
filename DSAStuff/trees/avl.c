#include<stdio.h>
#include<stdlib.h>

struct node{
  struct node *lchild;
  int data;
  int height;
  struct node *rchild;
}*root = NULL;

int nodeheight(struct node *p){
  int hl, hr;

  hl = p && p->lchild ? p->lchild->height : 0;
  hr = p && p->rchild ? p->rchild->height : 0;

  return hl>hr ? hl+1 : hr+1;
}

struct node *LLrotation(struct node *p){
  struct node *pl = p->lchild;
  struct node *plr = pl->rchild;

  pl->rchild = p;
  p->lchild = plr;
  p->height = nodeheight(p);
  pl->height = nodeheight(pl);

  if(root == p)
    root = pl;
  
  return pl;
}

struct node *LRrotation(struct node *p){
  struct node *pl = p->lchild;
  struct node *plr = pl->rchild;

  pl->rchild = plr->lchild;
  p->lchild = plr->rchild;

  plr->lchild = pl;
  plr->rchild = p;

  pl->height = nodeheight(pl);
  plr->height = nodeheight(plr);
  p->height = nodeheight(p);

  if(root == p)
    root = plr;
  
  return plr;

}

struct node *RRrotation(struct node *p){
  struct node *pr = p->rchild;
  struct node *prl = pr->lchild;

  pr->lchild = p;
  p->rchild = prl;
  pr->height = nodeheight(pr);
  p->height = nodeheight(p);

  if(root == p)
    root = pr;
  
  return pr;
}


struct node *RLrotation(struct node *p){
  struct node *pr = p->rchild;
  struct node *prl = pr->lchild;

  p->rchild = prl->lchild;
  pr->lchild = prl->rchild;

  prl->lchild = p;
  prl->rchild = pr;

  pr->height = nodeheight(pr);
  prl->height = nodeheight(prl);
  p->height = nodeheight(p);

  if(root == p)
    root = prl;
  
  return prl;
}

int balancefactor(struct node *p){
  int hl, hr;

  hl = p && p->lchild ? p->lchild->height : 0;
  hr = p && p->rchild ? p->rchild->height : 0;

  return hl-hr;
}

struct node *rinsert(struct node *p, int key){
  struct node *t;
  
  if(p == NULL){
    t = (struct node *)malloc(sizeof(struct node));
    t->data = key;
    t->lchild = t->rchild = NULL;
    return t;
  }
  
  if(key < p->data)
    p->lchild = rinsert(p->lchild, key);
  else if(key > p->data)
    p->rchild = rinsert(p->rchild, key);
  
  p->height = nodeheight(p);

  if(balancefactor(p) == 2 && balancefactor(p->lchild) == 1)
    return LLrotation(p);
  else if(balancefactor(p) == 2 && balancefactor(p->lchild) == -1)
    return LRrotation(p);
  else if(balancefactor(p) == -2 && balancefactor(p->rchild) == -1)
    return RRrotation(p);
  else if(balancefactor(p) == -2 && balancefactor(p->lchild) == 1)
    return RLrotation(p);
  return p;
}

void preorder(struct node *p){
  if(p){
    printf("%d ",p->data);
    preorder(p->lchild);
    preorder(p->rchild);
  }
}

struct node *inpre(struct node *p){
  while(p && p->rchild != NULL)
    p = p->rchild;

  return p;
}

struct node *insucc(struct node *p){
  while(p && p->lchild != NULL)
    p = p->lchild;

  return p;
}


struct node *delete(struct node *p, int key){
  struct node *q;

  if(p == NULL) 
    return NULL;
  
  if(p->lchild == NULL && p->rchild == NULL){
    if(p == root){
      root == NULL;
    }
    free(p);
    return NULL;
  }

  if(key < p->data)
    p->lchild = delete(p->lchild, key);
  else if(key > p->data)
    p->rchild = delete(p->rchild, key);
  else{
    if(nodeheight(p->lchild) > nodeheight(p->rchild)){
      q = inpre(p->lchild);
      p->data = q->data;
      p->lchild = delete(p->lchild, q->data);
    }
    else{
      q = insucc(p->rchild);
      p->data = q->data;
      p->rchild = delete(p->rchild, q->data);
    }
  }

  p->height=nodeheight(p);
 
  if(balancefactor(p)==2){
    if(balancefactor(p->lchild)==1)
      return LLrotation(p);
    else
      return LRrotation(p);
  }
  if(balancefactor(p)==-2){
    if(balancefactor(p->lchild)==-1)
      return RRrotation(p);
    else
      return RLrotation(p);
  }
  return p;
}

int main(){
  root = rinsert(root, 50);
  rinsert(root, 10);
  rinsert(root, 20);
  rinsert(root, 5);
  delete(root, 20);
  preorder(root);

  return 0;
}