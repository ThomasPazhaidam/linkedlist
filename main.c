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
int main(void) {
  node_t n1,n2,n3;
  node_t *head;

  n1.value=1;
  n2.value=2;
  n3.value=3; 

  // head of list is n3, order n3 -> n2 -> n1
  head=&n3;
  n3.next=&n2;
  n2.next=&n1;
  n1.next=NULL; //end of list is null
  print(head);
 
  //add value at end of list
  node_t n4;
  n4.value=4;
  n1.next=&n4;
  n4.next=NULL;
  print(head);

  //remove first node
  head=head->next;
  print(head);

  //move nodes around 
  n2.next=&n4;
  n4.next=&n1;
  n1.next=NULL;
  print(head);

  //add value in between list
  n4.next=&n3;
  n3.next=&n1;
  n1.next=NULL;
  print(head);
  return 0;
}
