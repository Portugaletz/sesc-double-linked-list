#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
  int value;
  struct Node * next;
  struct Node * last;
};

int main(void) {
  struct Node *end =NULL;
  struct Node * head = NULL;
  char mystr [100];
  while (scanf("%s", mystr)!=EOF){
    if (strcmp(mystr, "push-front")==0){
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      int n;
      scanf("%d", &n);
      tempnode->value=n;
      if (head==NULL){
        head=tempnode;
        end=tempnode;
      }else{
        tempnode->next=head;
        head->last=tempnode;
        head=tempnode;
      }
      printf("%d\n", n);
    }else if (strcmp(mystr, "dump")==0){
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=head;
      if (head==NULL){
        printf("empty\n");
      }else{
      while(tempnode!=NULL){
        printf("%d ",tempnode->value);
        tempnode=tempnode->next;
      }
      printf("\n");}
    }else if(strcmp(mystr, "push-back")==0){
      int n;
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      scanf("%d", &n);
      tempnode->value=n;
      if (head==NULL){
        head=tempnode;
        end=tempnode;
      }else{
      tempnode->last=end;
      tempnode->next=NULL;
      end->next=tempnode;
      end=tempnode;}
      printf("%d\n", n);
    }else if(strcmp(mystr, "clear")==0){
      while (head!=NULL){
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=head;
      head=head->next;
      free(tempnode);
      }
      printf("empty\n");
    }else if(strcmp(mystr, "peek-front")==0){
      if (head->next==NULL){printf("empty\n");}else{
      printf("%d\n", head->value);}
    }else if(strcmp(mystr, "peek-back")==0){
      if (head->next==NULL){printf("empty\n");}else{
      printf("%d\n", end->value);}
    }else if(strcmp(mystr, "pop-front")==0){
      if(head->next==NULL){printf("empty\n");}else{
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=head;
      printf("%d\n", head->value);
      head=head->next;
      head->last=NULL;
      free(tempnode);}
    }else if(strcmp(mystr, "pop-back")==0){
      if(head->next==NULL){printf("empty\n");}else{
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=end;
      printf("%d\n", end->value);
      end=end->last;
      end->next=NULL;
      free(tempnode);}
    }else if(strcmp(mystr, "size")==0){
      int n=0;
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=head;
      while(tempnode!=NULL){tempnode=tempnode->next;n++;};
      printf("%d\n", n);
    }else if(strcmp(mystr, "dump-reversed")==0){
      struct Node * tempnode=(struct Node*)malloc(sizeof(struct Node));
      tempnode=end;
      if (end==NULL){
        printf("empty\n");
      }else{
      while(tempnode!=NULL){
        printf("%d ",tempnode->value);
        tempnode=tempnode->last;
      }
      printf("\n");}
       
    }else printf("unknown operation %s\n", mystr);
  }
  return 0;
}
