#include<stdio.h>
#include <stdbool.h>
#include<conio.h>

#define SUCCESFUL 1
#define LIST_IS_EMPTY '\0'
#define ARG2_IS_OUT_OF_RANGE -1
#define ARG3_IS_OUT_OF_RANGE -2
#define ARG2_NOT_FOUND -3
#define ARG3_NOT_FOUND -4


struct node{
    int data;
    struct node* next;
};

/* program functions */
char push(struct node**, int); //add a node to the top of the list
char add_at_given_position(struct node**, int, int); //add a node to given position
char append(struct node**, int); //add a node to the end of the list
int pop(struct node**); //pop the head of the list
char delete_at_given_position(struct node**, int); //delete the node at given position
char delete_with_given_data(struct node**, int); //delete the node with given data
char delete_all_with_given_data(struct node**, int); //delete all nodes with given data
char delete_at_tail(struct node**); //delete the node at tail
char delete_list(struct node**); //delete list
char swap_nodes_at_given_positions(struct node**, int, int); //swap nodes at positionA and positionB
char swap_nodes_with_given_values(struct node**, int, int); //swap given nodes
char reverse_list(struct node**);
char sort_list(struct node**, bool); //sort_list the list in ascending or descending order
struct node* merge_lists(struct node*, struct node*); //merge two lists and return a new list


/* helper functions*/
void copyL_list(struct node** origin, struct node** copyL);
int get_data(struct node**, int);

/* helper functions */
void copyL_list(struct node** orign, struct node** copyL)
{
    if((*orign) == NULL) return;

    (*copyL) = (struct node*)malloc(sizeof(struct node));
    (*copyL)->data = (*orign)->data;
    (*copyL)->next = (*orign)->next;

    struct node* orignCur = (*orign)->next;
    struct node* copyLCur = (*copyL);

    while(orignCur != NULL)
    {
        struct node* nNode = (struct node*)malloc(sizeof(struct node));
        copyLCur->next = nNode;
        copyLCur = copyLCur->next;
        copyLCur->data = orignCur->data;
        copyLCur->next = NULL;
        orignCur = orignCur->next;
    }
    return;
}

int get_data(struct node** head, int pos)
{
    if(pos < 0) return (int)NULL;
    int indice = 0;
    struct node* cur = (*head);
    while(cur != NULL)
    {
        if(pos == indice)
        {
            return cur->data;
        }
        cur = cur->next;
        indice++;
    }
    return (int)NULL;
}

/* program functions */
char push(struct node** head, int data)
{
    struct node* nNode = (struct node*)malloc(sizeof(struct node));
    nNode->data = data;
    if((*head) == NULL)
    {
        nNode->next = NULL;
        (*head) = nNode;
        return SUCCESFUL;
    }
    nNode->next = (*head);
    (*head) = nNode;
    return SUCCESFUL;
}

char add_at_given_position(struct node* *head, int data, int position)
{
    if(position == 0)
    {
        struct node* nNode = (struct node*)malloc(sizeof(struct node));
        nNode->data = data;
        nNode->next = (*head);
        (*head) = nNode;
        return SUCCESFUL;
    }
    struct node* cur = (*head);
    int len = 0;
    struct node* prev_node_of_position = NULL;
    while(cur != NULL)
    {
        if(position-1 == len)
            prev_node_of_position = cur;
        cur = cur->next;
        len++;
    }

    if(position > len-1 || position < 0)
    {
        return ARG3_IS_OUT_OF_RANGE;
    }
    struct node* nNode = (struct node*)malloc(sizeof(struct node));
    nNode->data = data;
    nNode->next = prev_node_of_position->next;
    prev_node_of_position->next = nNode;
    return SUCCESFUL;
}
char append(struct node* *head, int data)
{
    struct node* nNode = (struct node*)malloc(sizeof(struct node));
    nNode->data = data;
    nNode->next = NULL;
    if((*head) == NULL)
    {
        (*head) = nNode;
        return SUCCESFUL;
    }
    struct node* cur = (*head);
    while(cur->next != NULL) cur = cur->next;
    cur->next = nNode;
    return SUCCESFUL;
}

int pop(struct node* *head)
{
    if((*head) == NULL)
    {
        return LIST_IS_EMPTY;
    }

    struct node* temp = (*head);
    (*head) = (*head)->next;

    int ret = temp->data;
    free(temp);
    return ret;
}
char delete_at_given_position(struct node** head, int position)
{
    if((*head) == NULL)
    {
        return LIST_IS_EMPTY;
    }
    if(position < 0)
    {
        return ARG2_IS_OUT_OF_RANGE;
    }
    struct node* cur = (*head);
    if(position == 0)
    {
        (*head) = (*head)->next;
        free(cur);
        return SUCCESFUL;
    }
    int indice = 0;
    struct node* prev_node_of_position = NULL;
    bool out_of_index = true;
    while(cur != NULL)
    {
        if(position-1 == indice)
        {
            prev_node_of_position = cur;
            cur = cur->next;
            out_of_index = false;
            break;
        }
        cur = cur->next;
        indice++;
    }


    if(out_of_index)
    {
        return ARG2_IS_OUT_OF_RANGE;
    }

    prev_node_of_position->next = cur->next;

    free(cur);
    return SUCCESFUL;
}
char delete_with_given_data(struct node* *head, int data)
{
    struct node* cur = (*head);
    int position = 0;
    while(cur != NULL)
    {
        if(cur->data == data)
        {
            delete_at_given_position(head, position);
            return SUCCESFUL;
        }
        cur = cur->next;
        position++;
    }
    return ARG2_NOT_FOUND;
}
char delete_all_with_given_data(struct node** head, int data)
{
    struct node* cur = (*head);
    int position = 0;
    bool notFound = true;
    while(cur != NULL)
    {
        if(cur->data == data)
        {
            notFound = false;
            cur = cur->next;
            delete_at_given_position(head, position);
        }
        else
        {
            cur = cur->next;
            position++;
        }
    }
    if(notFound)
    {
        return ARG2_NOT_FOUND;
    }
    return SUCCESFUL;
}
char delete_at_tail(struct node* *head)
{
    if((*head) == NULL)
    {
        return LIST_IS_EMPTY;
    }
    if((*head)->next == NULL)
    {
        free((*head));
        (*head) = NULL;
        return SUCCESFUL;
    }
    struct node* cur = (*head);
    while(cur->next->next != NULL) cur = cur->next;
    struct node* temp = cur->next;
    free(temp);
    cur->next = NULL;
    return SUCCESFUL;
}
char delete_list(struct node* *head)
{
    if((*head) == NULL) return LIST_IS_EMPTY;
    struct node* cur = (*head);
    while(cur->next != NULL)
    {
        struct node* temp = cur;
        cur = cur->next;
        free(temp);
        temp = NULL;
    }
    free(cur);
    (*head) = NULL;
    return SUCCESFUL;
}

char swap_nodes_at_given_positions(struct node** head, int posA, int posB)
{
    if((*head) == NULL)
    {
        return LIST_IS_EMPTY;
    }
    if(posA == posB) return SUCCESFUL;

    if(posA < 0)
    {
        return ARG2_IS_OUT_OF_RANGE;
    }
    if(posB < 0)
    {
        return ARG3_IS_OUT_OF_RANGE;
    }
    struct node* curHead = (*head);
    int lengt = 1;
    while(true)
    {
        curHead = curHead->next;
        if(curHead == NULL) break;
        lengt++;
    }
    if(posA > lengt-1)
    {
        return ARG2_IS_OUT_OF_RANGE;
    }
    if(posB > lengt-1)
    {
        return ARG3_IS_OUT_OF_RANGE;
    }

    struct node* copyL = NULL;
    copyL_list(head, &copyL);
    curHead = (*head);
    int indice = 0;
    while(indice < lengt)
    {
        if(indice == posA)
            curHead->data = get_data(&copyL, posB);
        if(indice == posB)
            curHead->data = get_data(&copyL, posA);
        curHead = curHead->next;
        indice++;
    }
    delete_list(&copyL);

    return SUCCESFUL;
}
char swap_nodes_with_given_values(struct node* *head, int valA, int valB)
{
    if(valA == valB) return SUCCESFUL;
    struct node* cur = (*head);
    int len = 0;
    int posA = NULL;
    int posB = NULL;
    bool foundA = false;
    bool foundB = false;
    while(cur != NULL)
    {
        len++;
        if(!foundA && valA == cur->data)
        {
            foundA = true;
            posA = (len-1);
        }
        if(!foundB && valB == cur->data)
        {
            foundB = true;
            posB = (len-1);
        }
        if(foundA && foundB)
        {
            swap_nodes_at_given_positions(head, posA, posB);
            return SUCCESFUL;
        }
        cur = cur->next;
    }
    if(!foundA)
    {
        return ARG2_NOT_FOUND;
    }
    if(!foundB)
    {
        return ARG3_NOT_FOUND;
    }
    return SUCCESFUL;
}

char reverse_list(struct node* *head)
{
    if((*head) == NULL) return LIST_IS_EMPTY;
    struct node* cur = (*head);
    int len = 0;
    while(cur != NULL)
    {
        len++;
        cur = cur->next;
    }
    if(len == 1) return SUCCESFUL;

    int temp[len];
    cur = (*head);
    int i = 0;
    while(cur != NULL)
    {
        temp[i] = cur->data;
        cur = cur->next;
        i++;
    }

    cur = (*head);
    i = len-1;
    while(cur != NULL)
    {
        cur->data = temp[i];
        cur = cur->next;
        i--;
    }
    return SUCCESFUL;
}

char sort_list(struct node* *head, bool ascending)
{
    if((*head) == NULL) return LIST_IS_EMPTY;
    if((*head)->next == NULL) return SUCCESFUL;
    if(ascending)
    {
        struct node* smallest = (*head);
        struct node* cur = smallest->next;
        while(smallest->next != NULL)
        {
            while(cur != NULL)
            {
                if(smallest->data > cur->data)
                {
                    int temp = smallest->data;
                    smallest->data = cur->data;
                    cur->data = temp;
                }
                cur = cur->next;
            }
            smallest = smallest->next;
            cur = smallest->next;
        }
    }
    else
    {
        struct node* biggest = (*head);
        struct node* cur = biggest->next;
        while(biggest->next != NULL)
        {
            while(cur != NULL)
            {
                if(biggest->data < cur->data)
                {
                    int temp = biggest->data;
                    biggest->data = cur->data;
                    cur->data = temp;
                }
                cur = cur->next;
            }
            biggest = biggest->next;
            cur = biggest->next;
        }
    }
    return SUCCESFUL;
}

struct node* merge_lists(struct node* listA, struct node* listB)
{
    struct node* newList = NULL;
    while(listA != NULL)
    {
        append(&newList, listA->data);
        listA = listA->next;
    }
    while(listB != NULL)
    {
        append(&newList, listB->data);
        listB = listB->next;
    }
    return newList;
}

