
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at end
void insertEnd(int data)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

// Create linked list using insertEnd()
void create()
{
    int n, i, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);

        insertEnd(data);
    }
}

// Insert at first position
void insertFirst(int data)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

// Insert at any position
void insertPosition(int data, int pos)
{
    struct node *newnode, *temp;
    int i;

    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        insertFirst(data);
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
}

// Display linked list
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice, data, pos;
    printf("Name : Diganth C P , usn: 1WA25CS077 , date: 03/11/26");


    while (1)
    {
        printf("\n1. Create Linked List");
        printf("\n2. Insert at First");
        printf("\n3. Insert at Any Position");
        printf("\n4. Insert at End");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFirst(data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter position: ");
                scanf("%d", &pos);

                insertPosition(data, pos);
                break;

            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
