#include<bits/stdc++.h>

using namespace std;

struct Node{
  int data;
  struct Node *next;
};
struct Node* head = NULL;

struct Node* GetNewNode(int value){
  struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->data = value;
  newnode->next = NULL;
  return newnode;
}
void insert(struct Node* head, int value){
  struct Node* newnode = GetNewNode(value);
  if(head == NULL){
    head = newnode;
    return;
  }
  newnode->next = head;
  head = newnode;
}
void Print(){
  Node* temp = head;
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
void Reverse(){
  if(head == NULL) return;
  stack<struct Node*> S;
  Node* temp = head;
  while(temp != NULL){
    S.push(temp);
    temp = temp->next;
  }
  temp = S.top();
  head = temp;
  S.pop();
  while(!S.empty()){
    temp->next = S.top();
    S.pop();
    temp = temp->next;
  }
  temp->next = NULL;
}

int main(){
  insert(head, 1);
  insert(head, 2);
  insert(head, 3);
  insert(head, 4);
  insert(head, 5);
  Print();
  Reverse();
  Print();
  return 0;
}
