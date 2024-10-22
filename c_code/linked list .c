#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct Node {
  int num;
  int score;
  struct Node *next;
} Node, *Linklist;
 
void initLinklist(Linklist l) {
  l = (Node *)malloc(sizeof(Node));
  l->next = NULL;
}
 
void add(Linklist l, int i, int num, int score) {
  Node *p;
  int j = 0;
  p = l;
  for (; j < i - 1; j++) {
    p = p->next;
  }
 
  Node *s = (Node *)malloc(sizeof(Node));
  s->num = num;
  s->score = score;
  s->next = p->next;
  p->next = s;
}
 
void printLinklist(Linklist l) {
  Node *p = l->next;
  while (p) {
    printf("[num=%d,score=%d]\n", p->num, p->score);
    p = p->next;
  }
}
 
void destroyLinklist(Linklist l) {
  Node *p = l;
  while (p) {
    Node *q = p;
    p = p->next;
    free(q);
  }
  l = NULL;
}
 
int main() {
  Linklist L;
  initLinklist(L);
  int num, score;
  int i;
  for (i = 1; i <= 3; i++) {
    scanf("%d%d", &num, &score);
    add(L, i, num, score);
  }
  printLinklist(L);
  destroyLinklist(L);
  return 0;
}

