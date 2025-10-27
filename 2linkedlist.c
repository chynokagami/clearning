#include<stdio.h>
#include <stdlib.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode;

LNode *initList(){
  // 创建头结点，L为头指针
  LNode *L = (LNode *)malloc(sizeof(LNode));
  L->next = NULL;  // 指针域置空
  return L;        // 返回头指针
}
int main(){
  printf("give a shot");
  return 0;
}