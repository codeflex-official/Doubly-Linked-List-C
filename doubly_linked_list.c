#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct dlist
{
  int data;
  struct dlist *prev;
  struct dlist *next;
};

struct dlist *header=NULL;

void create()
{
 int n,i;
 struct dlist *node, *temp;
 printf("\n How many nodes you want to create? ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  node=(struct dlist*)malloc(sizeof(struct dlist));
  printf("\n Enter node %d: ",i+1);
  scanf("%d",&node->data);
  node->next=NULL;
  if(header==NULL)
  {
   node->prev=NULL;
   header=node;
  }
  else
  {
    temp=header;
    while(temp->next!=NULL)
      temp=temp->next;
    temp->next=node;
    node->prev=temp;
  }
 }
 printf("\n List created successfully");
}

void insertatbegin()
{
  struct dlist *node;
  node=(struct dlist*)malloc(sizeof(struct dlist));
  printf("\n Enter node ");
  scanf("%d",&node->data);
  node->prev=NULL;
  node->next=header;
  if(header!=NULL)
    header->prev=node;
  header=node;
}

void insertatend()
{
  struct dlist *node,*temp;
  node=(struct dlist*)malloc(sizeof(struct dlist));
  printf("\n Enter node ");
  scanf("%d",&node->data);
  node->next=NULL;
  if(header==NULL)
  {
    node->prev=NULL;
    header=node;
    return;
  }
  temp=header;
  while(temp->next!=NULL)
    temp=temp->next;
  temp->next=node;
  node->prev=temp;
}

void insertatmid()
{
  struct dlist *node,*temp;
  int pos,i;
  printf("\n Enter position ");
  scanf("%d",&pos);
  if(header==NULL)
  {
    printf("\n List empty");
    return;
  }
  temp=header;
  for(i=1;i<pos-1 && temp!=NULL;i++)
    temp=temp->next;
  if(temp==NULL || temp->next==NULL)
  {
    printf("\n Invalid position");
    return;
  }
  node=(struct dlist*)malloc(sizeof(struct dlist));
  printf("\n Enter node ");
  scanf("%d",&node->data);
  node->next=temp->next;
  node->prev=temp;
  temp->next->prev=node;
  temp->next=node;
}

void deleteatbegin()
{
  struct dlist *node;
  struct dlist *p;
  if(header==NULL)
  {
    printf("\n List Empty");
    return;
  }
  node=header;
  header=header->next;
  if(header!=NULL)
    header->prev=NULL;
  free(node);
  printf("Deleted\nRemaining list: ");
  p=header;
  while(p!= NULL) {
   printf("%d ",p->data);
   p = p->next;
  }
}

void deleteatend()
{
  struct dlist *temp;
  struct dlist *p;
  if(header==NULL)
  {
    printf("\n List Empty");
    return;
  }
  if(header->next==NULL)
  {
    free(header);
    header=NULL;
    printf("Deleted\nList is now empty\n");
    return;
  }
  temp=header;
  while(temp->next!=NULL)
    temp=temp->next;
  temp->prev->next=NULL;
  free(temp);
  printf("Deleted\nRemaining list: ");
  p=header;
  while(p!= NULL) {
   printf("%d ",p->data);
   p = p->next;
  }
  printf("\n");
}

void deleteatmid()
{
  struct dlist *temp;
  int pos,i;
  printf("\n Enter position ");
  scanf("%d",&pos);
  if(header==NULL)
  {
    printf("\n List Empty");
    return;
  }
  temp=header;
  for(i=1;i<pos && temp!=NULL;i++)
    temp=temp->next;
  if(temp==NULL)
  {
    printf("\n Invalid position");
    return;
  }
  if(temp->prev!=NULL)
    temp->prev->next=temp->next;
  else
    header=temp->next;
  if(temp->next!=NULL)
    temp->next->prev=temp->prev;
  free(temp);
  printf("\n Deleted");
}

void displayforward()
{
  struct dlist *temp;
  if(header==NULL)
  {
    printf("\n List Empty");
    return;
  }
  temp=header;
  printf("\n Forward: ");
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }
}

void displaybackward()
{
  struct dlist *temp;
  if(header==NULL)
  {
    printf("\n List Empty");
    return;
  }
  temp=header;
  while(temp->next!=NULL)
    temp=temp->next;
  printf("\n Backward: ");
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->prev;
  }
}

void main()
{
  int ch;
  clrscr();
  create();
  displayforward();
  while(1)
  {
    printf("\n\n 0.Create list");
    printf("\n 1.Insert at begin");
    printf("\n 2.Insert at end");
    printf("\n 3.Insert at middle");
    printf("\n 4.Delete at begin");
    printf("\n 5.Delete at end");
    printf("\n 6.Delete at middle");
    printf("\n 7.Traverse forward");
    printf("\n 8.Traverse backward");
    printf("\n 9.Exit");
    printf("\n Enter choice ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 0: create();break;
      case 1: insertatbegin(); break;
      case 2: insertatend(); break;
      case 3: insertatmid(); break;
      case 4: deleteatbegin(); break;
      case 5: deleteatend(); break;
      case 6: deleteatmid(); break;
      case 7: displayforward(); break;
      case 8: displaybackward(); break;
      case 9: exit(0);
    }
    displayforward();
  }
  getch();
}
