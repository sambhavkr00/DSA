#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int dt;
    struct Node *lk;
}N;

N *h = NULL;
N *creation(N *);
N *insertion(N *);
N *deletion(N *);
N *sorting(N *);
N *reversion(N *);
N *display(N *);

int main(){
    int option;
    do
    {
        printf("\n*****MAIN MENU*****\n");
        printf("1. Create a node.\n2. Insert a node.\n3. Delete a node/list.\n4. Sort the list.\n5. Reverse the list.\n6. Display the list.\n7. Exit.\n");
        header: 
            printf("\nEnter your option: ");
            scanf("%d", &option);

        switch (option)
        {
            case 1: 
                h = creation(h);
                break;
            case 2:
                h = insertion(h);
                break;
            case 3:
                h = deletion(h);
                break;
            case 4:
                h = sorting(h);
                break;
            case 5:
                h = reversion(h);
                break;
            case 6:
                h = display(h);
                break;
            case 7:
                printf("\n***See you again!!***\n");
                exit(1);
            default:
                printf("\nWrong Input!! Please enter a valid option.\n");
                break;
        }
    } while (1);
    return 0;
}

N *creation(N *h){
    N *new, *ptr;
    int data, option;
    if (h != NULL)
    {
        printf("\n***Linked list has been already created.***\n");
        return h;
    }
    do
    {
        printf("\nDo you want to create a new node?\n");
        printf("Enter 1 for YES or other number for NO: ");
        scanf("%d", &option);

        if (option != 1)
        {
            break;
        }
        new = (N*)malloc(sizeof(N));
        printf("Enter an element: ");
        scanf("%d", &data);
        new->dt = data;
        new->lk = NULL;
        if (h == NULL)            
        {
            new->lk = h;
            h = new;
            ptr = h;
            printf("\n***Linked list has been created.***\n"); 
        }
        else
        {
            ptr->lk = new;
            ptr = ptr->lk;
            printf("\n***Linked list has been created.***\n"); 
        }
    }
    while (1);
    if (h==NULL)
    {
        printf("\n***Linked list is empty.***\n");
    }
    return h;
}

N *insertion(N *h){
    N *new, *ptr, *preptr;
    int data, option, pos, count = 0;

    if (h == NULL)
    {
        printf("\n***Linked list is empty. Please create first.***\n");
        return h;
    }
    else
    {   
        ptr = h;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr -> lk;
        }
    }
    do
    {
        printf("\nDo you want to insert a new node?\n");
        printf("Enter 1 for YES or other number for NO: ");
        scanf("%d", &option);
        if (option != 1)
        {
            break;
        }
        else
        {
            printf("\nEnter the position at which you want to insert element: ");
            scanf("%d", &pos);
            new = (N*)malloc(sizeof(N));
            if (pos >=1 && pos <= count+1)
            {
                printf("Enter an element: ");
                scanf("%d", &data);
                new -> dt = data;
                new -> lk = NULL;
                ptr = h;
                if (pos != 1)
                {
                    for (int i = 1; i < pos; i++)
                    {
                        preptr = ptr;
                        ptr = ptr -> lk;
                    }
                    preptr -> lk = new;
                    new -> lk = ptr;
                }
                else
                {
                    new -> lk = h;
                    ptr = new;
                    h = new;
                }
                printf("\n***New node has been inserted***\n");
            }
            else
            {
                printf("\nInvalid input!\n");
                break;
            }   
        }
    } while (1);
    return h; 
}

N *deletion(N *h){
    N *ptr, *preptr;
    int count, option, input;
    
    if (h == NULL)
    {
        printf("\n***Linked list is empty. Please create first.***\n");
        return h;
    }
    else
    {   
        ptr = h;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr -> lk;
        }
    }
    do
    {
        printf("\nDo you want to delete node/list?\n");
        printf("Enter 1 for YES or other number for NO: ");
        scanf("%d", &option);
        if (option != 1)
        {
            return h;
        }
        else
        {
            printf("Enter 0 to delete the list or enter position of node: ");
            scanf("%d", &input);
            ptr = h;
            preptr = h;
            if (input == 0)
            {
                while (ptr != NULL)
                {
                    ptr = ptr -> lk;
                    free(h);
                    h = ptr;
                }
                printf("\n***List has been deleted***\n");
                break;
            }
            else if (input >= 1 && input <= count)
            {
                if (input >= 2 && input <= count-1)
                {
                    for(int i = 1; i < input; i++)
                    {
                        preptr = ptr;
                        ptr = ptr -> lk;
                    }
                    preptr -> lk = ptr -> lk;
                    free(ptr);
                    ptr = NULL;
                }
                else if (input == 1)
                {
                    ptr = ptr -> lk;
                    free(h);
                    h = ptr;
                }
                else
                {
                    while(ptr -> lk != NULL)
                    {
                        preptr = ptr;
                        ptr = ptr -> lk;
                    }
                    preptr -> lk = NULL;
                    free(ptr);
                    ptr = NULL;
                }
                
                printf("\n***Node has been deleted***\n");
                break;
            }
            else
            {
                printf("\nInvalid input!\n");
                break;
            }    
        }
    } while (1);
    return h;
}

N *sorting(N *h){
    N *ptr;
    int count, option, select;
    if (h == NULL)
    {
        printf("\n***Linked list is empty. Please create first.***\n");
        return h;
    }
    else
    {   
        ptr = h;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr -> lk;
        }
    }
    do
    {
        printf("\nDo you want to sort the list?\n");
        printf("Enter 1 for YES or other number for NO: ");
        scanf("%d", &option);
        if (option != 1)
        {
            break;
        }
        else
        {
            printf("\nEnter 1 for ascendig or 0 for descending: ");
            scanf("%d", &select);
            ptr = h;
            if (select == 0 || select == 1)
            {
                if (select == 1)
                {
                
                }
                else
                {
                
                }
                printf("\n***List has been sorted.***\n");
            }
            else
            {
                printf("\nInvalid input!\n");
                break;
            }   
        }
        
    } while (1);
    return h;
}

N *reversion(N *h){
    N *ptr, *preptr;
    if (h == NULL)
    {
        printf("\n***Linked list is empty. Please create first.***\n");
        return h;
    }
    ptr = NULL;
    while (h != NULL)
    {
        preptr = h -> lk;
        h -> lk = ptr;
        ptr = h;
        h = preptr;
    }
    h = ptr;
    printf("\n***List has been reversed.***\n");
    return h;
}

N *display(N *h){

    N *ptr;
    ptr = h;
    if (h == NULL)
    {
        printf("\n***Linked list is empty. Please create first.***\n");
        return h;
    }
    printf("\nYour Linked List is: ");
    while(ptr != NULL)
    {
        printf("%d->", ptr -> dt);
        ptr = ptr -> lk;
    }
    printf("\b\b  \n");
    return h;
}