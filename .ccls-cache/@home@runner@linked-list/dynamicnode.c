#include <stdio.h>

struct node {
  int value;
  struct node* next;
};
typedef struct node node_t;

void print(node_t *head){
  node_t *headt = head;
  while(headt != NULL){
    printf("%d ", headt->value);
    headt=headt->next;
  }
  printf("\n");
}

node_t *newnode(int value){
  node_t *result = malloc(sizeof(node_t));
  result->value=value;
  result->next=NULL;
  return result;
}
int main(void) {
  node_t *head;


  
  return 0;
}
