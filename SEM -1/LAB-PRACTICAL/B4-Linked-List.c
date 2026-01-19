/*Part- B 4 Develop the program to simulate the working of a linked list
       providing following operations
       a. insert at the begining
       b. insert at the end
       c. delete at the begining
       d. delete at the end
       e. display	*/

#include<stdio.h>
#include<alloc.h>

struct node
 {
    int data;
    struct node *link;
 };
typedef struct node *NODE;

NODE addbeg(NODE,int);
void display(NODE);
NODE getnode();
NODE addend(NODE,int);
NODE delbeg(NODE);
NODE delend(NODE);

void main()
 {
   int op,item;
   NODE first = NULL;
   do
   {
      printf("1.Insert at begining \n");
      printf("2.Insert at the end \n");
      printf("3.Display \n");
      printf("4.Delete at the begining \n");
      printf("5.Delete at the end \n");
      printf("6.Exit \n \n");
      printf("enter option \n");
      scanf("%d",&op);
      switch(op)
      {
	 case 1:
		printf("enter the data to be inserted \n");
		scanf("%d",&item);
		first = addbeg(first,item);
		break;
	 case 2:
	       printf("enter an item to be inserted\n");
	       scanf("%d",&item);
	       first = addend(first,item);
	       break;

	case 3:
	       if(first == NULL)
	       {
		  printf("Linked list is empty \n \n");
	       }
	       else
	       {
		  printf("contents of linked list are \n");
		  display(first);
	       }
	       break;

	case 4:
		if(first == NULL)
		{
		   printf("Linked list is empty \n \n");
		}
		else
		{
		   first = delbeg(first);
		}
		break;
	 case 5:
		if(first == NULL)
		{
		   printf("Linked list is empty \n \n");
		}
		else
		{
		   first = delend(first);
		}
		break;
	     }
 } while(op != 6);
}

NODE addbeg(NODE first,int item)
 {
    NODE temp;
    temp = getnode();
    temp->data=item;
    temp->link=first;
    first=temp;
    return first;
 }

NODE addend(NODE first,int item)
{
  NODE temp,cur;
  cur = first;
  temp = getnode();
  temp->data = item;
  temp->link = NULL;
  if(first == NULL)
  {
     first = temp;
     return first;
  }
  else
  {
     while(cur->link != NULL)
       {
	  cur = cur->link;
       }
    cur->link = temp;
    return first;
  }
}

void display(NODE first)
{
   NODE cur;
   cur = first;
   while(cur != NULL)
   {
      printf("%d->",cur->data);
      cur = cur -> link;
   }
   printf("NULL \n \n");
}

NODE delbeg(NODE first)
 {
    NODE cur;
    cur = first;
    first = first->link;
    free(cur);
    return first;
 }

NODE delend(NODE first)
 {
   NODE cur,prev;
   cur = first;
   if(first->link == NULL)
   {
      free(cur);
      return NULL;
   }
   while(cur->link !=  NULL)
   {
      prev = cur;
      cur = cur->link;
   }
   prev->link = NULL;
   free(cur);
   return first;
 }

NODE getnode()
{
   NODE x;
   x = (NODE) malloc(sizeof(struct node));
   return x;
}




