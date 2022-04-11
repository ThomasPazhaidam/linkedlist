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
#include <stdio.h>

//insert node to start of new list and set new node as head of the list
node_t *newnode(int value){
  node_t *result = malloc(sizeof(node_t));
  result->value=value;
  result->next=NULL;
  return result;
}

node_t *nodefinder(node_t *head, int value){
  node_t *tmp = head;
  while(tmp != NULL){
    if (tmp->value == value) return tmp;
    tmp=tmp->next;
  }
  return NULL;
}

node_t *inserthead(node_t **head, node_t *insertnode){
  insertnode->next=*head;
  *head=insertnode;
  return insertnode;
}

void insertnewnode(node_t *insertafter, node_t *newnode){
  newnode->next=insertafter->next;
  insertafter->next=newnode;
}

int main(void) {
  node_t *head=NULL;
  node_t *tmp;

  for (int i=0;i<5;i++){
    tmp=newnode(i);
    inserthead(&head,tmp);
    //tmp->next=head;
    //head=tmp;
  }
  print(head);

  tmp=nodefinder(head, 3);
  printf("node %d found\n", tmp->value);

  insertnewnode(tmp, newnode(7));
  print(head);
  //tmp = newnode(1);
  //head=tmp;
  //tmp = newnode(2);
  //tmp->next=head;
  //head=tmp;
  //tmp = newnode(3);
  //tmp->next=head;
  //head=tmp;
  
  //node_t n1,n2,n3;
  //node_t *head;

  //n1.value=1;
  //n2.value=2;
  //n3.value=3; 

  // head of list is n3, order n3 -> n2 -> n1
  //head=&n3;
  //n3.next=&n2;
  //n2.next=&n1;
  //n1.next=NULL; //end of list is null
  //print(head);
 
  //add value at end of list
  //node_t n4;
  //n4.value=4;
  //n1.next=&n4;
  //n4.next=NULL;
  //print(head);

  //remove first node
  //head=head->next;
  //print(head);

  //move nodes around 
  //n2.next=&n4;
  //n4.next=&n1;
  //n1.next=NULL;
  //print(head);

  //add value in between list
  //n4.next=&n3;
  //n3.next=&n1;
  //n1.next=NULL;
  //print(head);
  return 0;
}
