#include<stdio.h>
#include<stdlib.h>
void display();
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *last;
void insert_beg()
{
    struct node *nn;
    int ele;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter data for the node\n");
    scanf("%d",&ele);
    nn->data=ele;
   if(head==NULL)
   {
        nn->next=head;
        head=nn;
        last=nn;
        //last->next=nn;
        printf("Element %d inserted successfully\n",ele);
   }
   else{
     nn->next=head;
    head=nn;
    last->next=nn;
    printf("Element %d inserted successfully\n",ele);
   }

}
void insert_end()
{
    if(head==NULL)
    {
        insert_beg();
    }
    else
    {
        struct node *nn;
        int ele;
        nn=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for the node\n");
        scanf("%d",&ele);
        nn->data=ele;
        last->next=nn;
        nn->next=head;
        last=nn;
        printf("Element %d inserted successfully\n",ele);
    }
}
void insert_ran()
{
 if(head==NULL)
    {
        char ch;
        printf("The list is currently empty\ndo you want to start the list?(y/n)\n");
        fflush(stdin);
        scanf("%c",&ch);
        if(ch=='y')
        {
            insert_beg();
        }
        else
        {
            printf("\nNo element entered\n");
        }
    }
    else
    {
    display();
    printf("Enter after which element you want to add\n");
    int e;
    scanf("%d",&e);
    struct node *temp;
    if(last->data==e)
    {
        insert_end();
    }
    else
    {
        int flag=0;
                temp=head;

            do
                {
                    if(temp->data==e)
                    {
                        flag=1;
                        break;

                    }
                    temp=temp->next;
                }while(temp!=head);
            if(temp==head&&flag==0)//flag because if the specified element is the first element itself
            {
                printf("No such element found\n");
            }
            else
            {
                    struct node *nn;
                    int ele;
                    nn=(struct node*)malloc(sizeof(struct node));
                    printf("Enter data for the node\n");
                    scanf("%d",&ele);
                    nn->data=ele;
                nn->next=temp->next;
                temp->next=nn;
                printf("Element %d inserted successfully\n",ele);
            }
    }
    }
}
void remove_beg()
{
if(head==NULL)
{
    printf("Linked list is empty no data to be removed\n");
}
else
{
    if(head==last)
    {
        printf("Only remaining Element %d removed successfully\n",head->data);
       free(head);
       head=NULL;
       last=NULL;
    }
    else
    {
            struct node *temp;
            temp=head;
            head=head->next;
            last->next=head;
            printf("Element %d removed successfully\n",temp->data);
            free(temp);
    }
}

}
void remove_end()
{
    if(head==NULL)
    {
        printf("The linked list is empty no element to be removed\n");
    }
    else if(head==last)
    {
       printf("only remaining Element %d removed successfully\n",head->data);
       free(head);
       head=NULL;
       last=NULL;
    }
    else
    {
        struct node *temp;
        temp=head;
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        temp->next=head;
        //struct node *temp2;
        //temp2=last;
        printf("Element %d removed successfully\n",last->data);
        free(last);
        last=temp;
        //free(temp2);
    }
}
void remove_ran()
{
    if(head==NULL)
    {
        printf("The linked list is empty no data to be removed\n");
    }
    else if(head==last)
    {
       printf("Only remaining Element %d removed successfully\n",head->data);
       free(head);
       head=NULL;
       last=NULL;
    }

     else
  {
        display();
        printf("Enter the element to be deleted\n");
        int ele;
        scanf("%d",&ele);

    if(last->data==ele)
    {
        remove_end();
    }
    else if(head->data==ele)
    {
        remove_beg();

    }
    else
    {

        struct node *temp;
        struct node *temp2;
        temp=head;

        do{
            if(temp->data==ele)
            {
                break;
            }
            temp2=temp;
            temp=temp->next;
        }while(temp!=head);
        if(temp==head)
        {
            printf("No such element found\n");
        }
        else{
        temp2->next=temp->next;
        free(temp);
        }
    }
 }
}
void display()
{
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else{
        struct node *temp;
        temp=head;
        printf("\nThe linked list is\n");

    do{
        printf("%d\n",temp->data);
        temp=temp->next;
    }while(temp!=head);
    }
}
void main()
{
    int a;
    head=NULL;
    last=NULL;
    do{
             printf("\n\n                               ******Please enter your choice******\n1:To insert in the beginning \n2:To insert at the end\n3:To insert after any element\n");
             printf("5:To remove from the beginning\n6:To remove from the end\n7:To remove specified element\n");
             printf("8:To display\n9:To exit\n\n\n");

            scanf("%d",&a);
            switch(a)
            {
                case 1:insert_beg();
                break;

                case 2:insert_end();
                break;

                case 3:insert_ran();
                break;

                case 5:remove_beg();
                break;

                case 6:remove_end();
                break;

                case 7:remove_ran();
                break;


                case 8:display();
                break;

                case 9:exit(0);
                break;

                default:
                    printf("Invalid entry\n");
            }


    }while(1);
}
