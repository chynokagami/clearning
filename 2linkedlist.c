#include <stdio.h>
#include <stdlib.h>

// 链表节点的结构体定义
typedef struct LNode {
  int data;
  struct LNode *next;
} LNode;

// 创建新结点
LNode* createNode(int data) {
  //  创建结点newNode，动态分配内存
  LNode* newNode = (LNode*)malloc(sizeof(LNode));
  if (!newNode) {
    printf("内存分配失败!\n");
    exit(1);
  }
  //  设置结点的数据域和指针域，返回该结点
  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

// 打印链表
void printList(LNode *head) {
  LNode *current = head->next; // 从第一个结点开始
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }

  printf("NULL\n");
}

int main() {
  //  创建头结点L，指针域置空
  LNode *L = (LNode *)malloc(sizeof(LNode));
  L->next = NULL;


  // 初始化三个结点
  LNode *n1 = createNode(8);
  LNode *n2 = createNode(9);
  LNode *n3 = createNode(6);

  // 创建各结点间的连接
  L->next = n1;
  n1->next = n2;
  n2->next = n3;

  // 打印链表
  printf("链表为: ");
  printList(L);

  // 释放内存
  free(L);
  free(n1);
  free(n2);
  free(n3);

  return 0;
}