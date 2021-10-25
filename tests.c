#include<stdio.h>
#include <stdbool.h>
#include <windows.h>
#include<conio.h>
#include "LinkedList.h"



/* test functions*/
bool test_push();
bool test_add_at_given_position();
bool test_append();
bool test_pop();
bool test_delete_at_given_position();
bool test_delete_with_given_data();
bool test_delete_all_with_given_data();
bool test_delete_at_tail();
bool test_delete_list();
bool test_swap_nodes_at_given_positions();
bool test_swap_nodes_with_given_values();
bool test_reverse_list();
bool test_sort_list();
bool test_merge_lists();
char *filename;

/* helper functions*/
struct node* array_to_list(int*, int);
bool compare_lists(struct node**, int*, int);
void print_list(struct node**);
void print_error(char);


// open the file for writing output
FILE *fp;


int main()
{
    int passed = 0;
    int failed = 0;

    filename = "tests_output.txt";
    // open the file for writing
    fp = fopen(filename, "w");

    /*for colorful output*/
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    fprintf(fp, "push() test --------------------- : \n");
    printf("push() test --------------------- : \n");
    if(test_push())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "push() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "push() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\nadd_at_given_position() test --------------------- : \n");
    printf("\nadd_at_given_position() test --------------------- : \n");
    if(test_add_at_given_position())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "add_at_given_position() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "add_at_given_position() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\nappend() test --------------------- : \n");
    printf("\nappend() test --------------------- : \n");
    if(test_append())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "append() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "append() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\npop() test --------------------- : \n");
    printf("\npop() test --------------------- : \n");
    if(test_pop())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "pop() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "pop() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\ndelete_at_given_position() test --------------------- : \n");
    printf("\ndelete_at_given_position() test --------------------- : \n");
    if(test_delete_at_given_position())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "delete_at_given_position() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "delete_at_given_position() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\ndelete_with_given_data() test --------------------- : \n");
    printf("\ndelete_with_given_data() test --------------------- : \n");
    if(test_delete_with_given_data())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "delete_with_given_data() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "delete_with_given_data() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\ndelete_all_with_given_data() test --------------------- : \n");
    printf("\ndelete_all_with_given_data() test --------------------- : \n");
    if(test_delete_all_with_given_data())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "delete_all_with_given_data() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "delete_all_with_given_data() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\ndelete_at_tail() test --------------------- : \n");
    printf("\ndelete_at_tail() test --------------------- : \n");
    if(test_delete_at_tail())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "delete_at_tail() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "delete_at_tail() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\nswap_nodes_at_given_positions() test --------------------- : \n");
    printf("\nswap_nodes_at_given_positions() test --------------------- : \n");
    if(test_swap_nodes_at_given_positions())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "swap_nodes_at_given_positions() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "swap_nodes_at_given_positions() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\nswap_nodes_with_given_values() test --------------------- : \n");
    printf("\nswap_nodes_with_given_values() test --------------------- : \n");
    if(test_swap_nodes_with_given_values())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "swap_nodes_with_given_values() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "swap_nodes_with_given_values() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\nreverse_list() test --------------------- : \n");
    printf("\nreverse_list() test --------------------- : \n");
    if(test_reverse_list())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "reverse_list() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "reverse_list() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\nsort_list() test --------------------- : \n");
    printf("\nsort_list() test --------------------- : \n");
    if(test_sort_list())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "sort_list() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "sort_list() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\nmerge_lists() test --------------------- : \n");
    printf("\nmerge_lists() test --------------------- : \n");
    if(test_merge_lists())
    {
        SetConsoleTextAttribute(hConsole, 2); //green output
        printf("PASSED\n");
        fprintf(fp, "merge_lists() test --------------------- : PASSED\n");
        passed++;
        SetConsoleTextAttribute(hConsole, 7); //white output
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //red output
        printf("FAILED\n");
        fprintf(fp, "merge_lists() test --------------------- : FAILED\n");
        failed++;
        SetConsoleTextAttribute(hConsole, 7);
    }

    fprintf(fp, "\n\n\nRESULT :");
    fprintf(fp, "%d PASSED, %d FAILED", passed, failed);

    printf("\n\n\nPROGRAM EXECUTED (");
    SetConsoleTextAttribute(hConsole, 2);
    printf("%d PASSED", passed);
    SetConsoleTextAttribute(hConsole, 7);
    printf(", ");
    SetConsoleTextAttribute(hConsole, 4);
    printf("%d FAILED", failed);
    SetConsoleTextAttribute(hConsole, 7);
    printf(")\n");

    /* to not close the program*/
    //scanf("%d", &failed);
    getch();
    return 0;
}


struct node* array_to_list(int* A, int A_size)
{
    struct node* head = NULL;
    if(A_size == 0) return head;

    int i;
    for(i = A_size - 1; i >= 0; i--)
    {
        push(&head, A[i]);
    }
    return head;
}


void print_error(char err_value)
{
    switch(err_value)
    {
    case SUCCESFUL:
        fprintf(fp, "[success]\n");
        break;
    case LIST_IS_EMPTY:
        fprintf(fp, "[list is empty]\n");
        break;
    case ARG2_IS_OUT_OF_RANGE:
        fprintf(fp, "[argument 2 is out of range]\n");
        break;
    case ARG3_IS_OUT_OF_RANGE:
        fprintf(fp, "[argument 3 is out of range]\n");
        break;
    case ARG2_NOT_FOUND:
        fprintf(fp, "[argument 2 is not found]\n");
        break;
    case ARG3_NOT_FOUND:
        fprintf(fp, "[argument 3 is not found]\n");
        break;
    default:
        fprintf(fp, "[success]\n");
    }
}
bool compare_lists(struct node** head, int* listB, int lenB)
{
    struct node* listCur = (*head);
    int lenList = 0;

    while(listCur != NULL)
    {
        lenList += 1;
        listCur = listCur->next;
    }
    if(lenList == 0 && lenB == 0) return true;
    if(lenList != lenB) return false;

    listCur = (*head);
    /*if lengths are equal then check data values*/
    int i;
    for(i = 0; i < lenB; i++)
    {
        if(listCur->data != listB[i]) return false;
        listCur = listCur->next;
    }
    return true;
}

void print_list(struct node* *head)
{
    if((*head) == NULL)
    {
        fprintf(fp, "NULL");
        fprintf(fp, "\n");
        return;
    }
    struct node* cur = (*head);
    while(true)
    {
        fprintf(fp, "%d", cur->data);
        cur = cur->next;
        if(cur == NULL)
        {
            fprintf(fp, " -> NULL");
            fprintf(fp, "\n");
            return;
        }
        fprintf(fp, " -> ");
    }
}

/* test functions */
bool test_push()
{
    int list_length = 4;
    int expected_list[4] = {9, 8, 2, 10};

    struct node* head = NULL;
    fprintf(fp, "Initial List : ");
    print_list(&head);

    fprintf(fp, "pushing 10,2,8,9 ...\n");
    print_error(push(&head, 10));
    print_error(push(&head, 2));
    print_error(push(&head, 8));
    print_error(push(&head, 9));
    fprintf(fp, "List : ");
    print_list(&head);

    bool check1 = compare_lists(&head, expected_list, list_length);
    if(check1) fprintf(fp, "   (true)");
    else fprintf(fp, "   (false)");
    fprintf(fp, "\n");

    /* free the allocated memory*/
    delete_list(&head);
    return check1;
}

bool test_add_at_given_position()
{
    bool check1,check2,check3,check4,check5;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        struct node* list = NULL;
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Adding 13 to position 1 on empty List...\n");
        print_error(add_at_given_position(&list, 13,1));
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        struct node* list = NULL;
        int expected_list_length = 1;
        int expected_list[1] = {14};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Adding 14 to position 0 on empty List...\n");
        print_error(add_at_given_position(&list, 14, 0));
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check2*/

    /*check3*/{
        fprintf(fp, "\n--- check3 ----\n");
        int to_be_list_arr[13] = {5, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list_arr, 13);

        int expected_list_length = 14;
        int expected_list[14] = {5, 99, 19, 23, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Adding 23 to position 3...\n");
        print_error(add_at_given_position(&list, 23, 3));
        fprintf(fp, "Result : ");
        print_list(&list);
        check3 = compare_lists(&list, expected_list, expected_list_length);
        if(check3) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check3*/

    /*check4*/{
        fprintf(fp, "\n--- check4 ----\n");
        int to_be_list_arr[13] = {5, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list_arr, 13);

        int expected_list_length = 13;
        int expected_list[13] = {5, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Adding 23 to position 99...\n");
        print_error(add_at_given_position(&list, 23, 99));
        fprintf(fp, "Result : ");
        print_list(&list);
        check4 = compare_lists(&list, expected_list, expected_list_length);
        if(check4) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check4*/

    /*check5*/{
        fprintf(fp, "\n--- check5 ----\n");
        int to_be_list_arr[13] = {5, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list_arr, 13);

        int expected_list_length = 13;
        int expected_list[13] = {5, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Adding 23 to position -1...\n");
        print_error(add_at_given_position(&list, 23, -1));
        fprintf(fp, "Result : ");
        print_list(&list);
        check5 = compare_lists(&list, expected_list, expected_list_length);
        if(check5) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check5*/

    return check1&&check2&&check3&&check4&&check5;
}

bool test_append()
{
    struct node* list = NULL;
    bool check1, check2;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        int expected_list_length = 1;
        int expected_list[1] ={13};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Appending 13 to empty List...\n");
        print_error(append(&list, 13));
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        int expected_list_length = 5;
        int expected_list[5] = {13, 14, 17, -3, 99};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Appending 14, 17, -3, 99 to List...\n");
        print_error(append(&list, 14));
        print_error(append(&list, 17));
        print_error(append(&list, -3));
        print_error(append(&list, 99));
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check2*/
    delete_list(&list);

    return check1&&check2;
}

bool test_pop()
{
    bool check1,check2;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        struct node* list = NULL;
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Poping from empty List...\n");
        int pop_value = pop(&list);
        print_error(pop_value);
        int expected_pop_value = NULL;
        fprintf(fp, "pop_value = %d\n", pop_value);
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length) && (pop_value == expected_pop_value);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 12;
        int expected_list[12] = {99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Pop from list...\n");
        int pop_value = pop(&list);
        print_error(pop_value);
        int expected_pop_value = 13;
        fprintf(fp, "pop_value = %d\n", pop_value);
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length) && (pop_value == expected_pop_value);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check2*/

    return check1 && check2;
}

bool test_delete_at_given_position()
{
    bool check1,check2, check3, check4;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        struct node* list = NULL;
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting at position 0 from empty List...\n");
        print_error(delete_at_given_position(&list,0));
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 11;
        int expected_list[11] = {99, 19, 5, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting at position 0 on List...\n");
        print_error(delete_at_given_position(&list, 0));
        fprintf(fp, "Delete at position 4 on List...\n");
        print_error(delete_at_given_position(&list, 4));
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check2*/

    /*check3*/{
        fprintf(fp, "\n--- check3 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 13;
        int expected_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting at position 99 on List...\n");
        print_error(delete_at_given_position(&list, 99));
        fprintf(fp, "Deleting at position -1 on List...\n");
        print_error(delete_at_given_position(&list, -1));
        fprintf(fp, "Result : ");
        print_list(&list);
        check3 = compare_lists(&list, expected_list, expected_list_length);
        if(check3) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check3*/

    /*check4*/{
        fprintf(fp, "\n--- check4 ----\n");
        int to_be_list[1] = {13};
        struct node* list = array_to_list(to_be_list, 1);
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting at position 0 on List...\n");
        print_error(delete_at_given_position(&list, 0));
        fprintf(fp, "Result : ");
        print_list(&list);
        fprintf(fp, "Deleting at position 2 on List...\n");
        print_error(delete_at_given_position(&list, 2));
        fprintf(fp, "Result : ");
        print_list(&list);
        check4 = compare_lists(&list, expected_list, expected_list_length);
        if(check4) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check4*/

    return check1&&check2&&check3&&check4;
}

bool test_delete_with_given_data()
{
    bool check1,check2, check3, check4;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        struct node* list = NULL;
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting data from empty List...\n");
        print_error(delete_with_given_data(&list,20));
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 11;
        int expected_list[11] = {99, 19, 5, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting 13 from List...\n");
        print_error(delete_with_given_data(&list, 13));
        fprintf(fp, "Result : ");
        print_list(&list);
        fprintf(fp, "Deleting 10 from List...\n");
        print_error(delete_with_given_data(&list, 10));
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check2*/

    /*check3*/{
        fprintf(fp, "\n--- check3 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 13;
        int expected_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting 77 on List...\n");
        print_error(delete_with_given_data(&list, 77));
        fprintf(fp, "Result : ");
        print_list(&list);
        fprintf(fp, "Deleting 2 on List...\n");
        print_error(delete_with_given_data(&list, 2));
        fprintf(fp, "Result : ");
        print_list(&list);
        check3 = compare_lists(&list, expected_list, expected_list_length);
        if(check3) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check3*/

    /*check4*/{
        fprintf(fp, "\n--- check4 ----\n");
        int to_be_list[1] = {13};
        struct node* list = array_to_list(to_be_list, 1);
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting 13 on List...\n");
        print_error(delete_with_given_data(&list, 13));
        fprintf(fp, "Result : ");
        print_list(&list);
        fprintf(fp, "Deleting 2 on List...\n");
        print_error(delete_with_given_data(&list, 2));
        fprintf(fp, "Result : ");
        print_list(&list);
        check4 = compare_lists(&list, expected_list, expected_list_length);
        if(check4) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check4*/

    return check1&&check2&&check3&&check4;
}
bool test_delete_all_with_given_data()
{
    bool check1,check2, check3;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        struct node* list = NULL;
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting data from empty List...\n");
        print_error(delete_all_with_given_data(&list,20));
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 8;
        int expected_list[8] = {99, 19, 5, 15, 45, 55, 5, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting all 13s from List...\n");
        print_error(delete_all_with_given_data(&list, 13));
        fprintf(fp, "Result : ");
        print_list(&list);
        fprintf(fp, "Deleting all 10s from List...\n");
        print_error(delete_all_with_given_data(&list, 10));
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check2*/

    /*check3*/{
        fprintf(fp, "\n--- check3 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 13;
        int expected_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting all 77s on List...\n");
        print_error(delete_all_with_given_data(&list, 77));
        fprintf(fp, "Result : ");
        print_list(&list);
        check3 = compare_lists(&list, expected_list, expected_list_length);
        if(check3) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check3*/
    return check1&&check2&&check3;
}
bool test_delete_at_tail()
{
    bool check1,check2, check3;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        struct node* list = NULL;
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting at tail from empty List...\n");
        print_error(delete_at_tail(&list));
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        int to_be_list[1] = {13};
        struct node* list = array_to_list(to_be_list, 1);
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting at tail from List...\n");
        print_error(delete_at_tail(&list));
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check2*/

    /*check3*/{
        fprintf(fp, "\n--- check3 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 12;
        int expected_list[12] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting at tail from List...\n");
        print_error(delete_at_tail(&list));
        fprintf(fp, "Result : ");
        print_list(&list);
        check3 = compare_lists(&list, expected_list, expected_list_length);
        if(check3) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check3*/

    return check1&&check2&&check3;
}
bool test_delete_list()
{
    bool check1,check2, check3;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        struct node* list = NULL;
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting empty List...\n");
        print_error(delete_list(&list));
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        int to_be_list[1] = {13};
        struct node* list = array_to_list(to_be_list, 1);
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting List...\n");
        print_error(delete_list(&list));
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
    }/*-check2*/

    /*check3*/{
        fprintf(fp, "\n--- check3 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Deleting List...\n");
        print_error(delete_list(&list));
        fprintf(fp, "Result : ");
        print_list(&list);
        check3 = compare_lists(&list, expected_list, expected_list_length);
        if(check3) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
    }/*-check3*/

    return check1&&check2&&check3;
}
bool test_swap_nodes_at_given_positions()
{
    bool check1,check2, check3, check4;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        struct node* list = NULL;
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Swaping nodes at position 0, 3 on empty List...\n");
        print_error(swap_nodes_at_given_positions(&list, 0, 3));
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 13;
        int expected_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Swaping nodes at position 1, 1 on List...\n");
        print_error(swap_nodes_at_given_positions(&list, 1, 1));
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check2*/

    /*check3*/{
        fprintf(fp, "\n--- check3 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 13;
        int expected_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Swaping nodes at position 1, 99 on List...\n");
        print_error(swap_nodes_at_given_positions(&list, 1, 99));
        fprintf(fp, "Result : ");
        print_list(&list);
        check3 = compare_lists(&list, expected_list, expected_list_length);
        if(check3) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check3*/

    /*check4*/{
        fprintf(fp, "\n--- check4 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 13;
        int expected_list[13] = {13, 10, 19, 5, 10, 99, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Swaping nodes at position 1, 5 on List...\n");
        print_error(swap_nodes_at_given_positions(&list, 1, 5));
        fprintf(fp, "Result : ");
        print_list(&list);
        check4 = compare_lists(&list, expected_list, expected_list_length);
        if(check3) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check4*/

    return check1&&check2&&check3&&check4;
}
bool test_swap_nodes_with_given_values()
{
    bool check1,check2, check3, check4;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        struct node* list = NULL;
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Swaping nodes with values 5, 20 on empty List...\n");
        print_error(swap_nodes_with_given_values(&list, 5, 20));
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 13;
        int expected_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Swaping nodes with values 1, 20 on List...\n");
        print_error(swap_nodes_with_given_values(&list, 1, 20));
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check2*/

    /*check3*/{
        fprintf(fp, "\n--- check3 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 13;
        int expected_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Swaping nodes with values 14, 99 on List...\n");
        print_error(swap_nodes_with_given_values(&list, 14, 99));
        fprintf(fp, "Result : ");
        print_list(&list);
        check3 = compare_lists(&list, expected_list, expected_list_length);
        if(check3) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check3*/

    /*check4*/{
        fprintf(fp, "\n--- check4 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 13;
        int expected_list[13] = {13, 99, 19, 45, 10, 10, 10, 15, 5, 55, 5, 10, 85};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Swaping nodes with values 5, 45 on List...\n");
        print_error(swap_nodes_with_given_values(&list, 5, 45));
        fprintf(fp, "Result : ");
        print_list(&list);
        check4 = compare_lists(&list, expected_list, expected_list_length);
        if(check4) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check4*/

    return check1&&check2&&check3&&check4;
}
bool test_reverse_list()
{
   bool check1,check2, check3;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        struct node* list = NULL;
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Reversing empty List...\n");
        print_error(reverse_list(&list));
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        int to_be_list[1] = {13};
        struct node* list = array_to_list(to_be_list, 1);
        int expected_list_length = 1;
        int expected_list[1] = {13};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Reversing List...\n");
        print_error(reverse_list(&list));
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check2*/

    /*check3*/{
        fprintf(fp, "\n--- check3 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 13;
        int expected_list[13] = {85, 10, 5, 55, 45, 15, 10, 10, 10, 5, 19, 99, 13};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "Reversing List...\n");
        print_error(reverse_list(&list));
        fprintf(fp, "Result : ");
        print_list(&list);
        check3 = compare_lists(&list, expected_list, expected_list_length);
        if(check3) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check3*/

    return check1&&check2&&check3;
}
bool test_sort_list()
{
    bool check1,check2, check3;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        struct node* list = NULL;
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "sorting empty list ascending...\n");
        print_error(sort_list(&list, true));
        fprintf(fp, "Result : ");
        print_list(&list);
        fprintf(fp, "sorting empty list descending...\n");
        print_error(sort_list(&list, false));
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 13;
        int expected_list[13] = {99, 85, 55, 45, 19, 15, 13, 10, 10, 10, 10, 5, 5};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "sorting list descending...\n");
        print_error(sort_list(&list, false));
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check2*/

    /*check3*/{
        fprintf(fp, "\n--- check3 ----\n");
        int to_be_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list = array_to_list(to_be_list, 13);
        int expected_list_length = 13;
        int expected_list[13] = {5, 5, 10, 10, 10, 10, 13, 15, 19, 45, 55, 85, 99};
        fprintf(fp, "Initial List: ");
        print_list(&list);
        fprintf(fp, "sorting list ascending...\n");
        print_error(sort_list(&list, true));
        fprintf(fp, "Result : ");
        print_list(&list);
        check3 = compare_lists(&list, expected_list, expected_list_length);
        if(check3) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check3*/

    return check1&&check2&&check3;
}
bool test_merge_lists()
{
    bool check1,check2, check3;
    /*check1*/{
        fprintf(fp, "\n--- check1 ----\n");
        struct node* list = NULL;
        struct node* list1 = NULL;
        struct node* list2 = NULL;
        int expected_list_length = 0;
        int* expected_list = NULL;
        fprintf(fp, "Initial List1: ");
        print_list(&list1);
        fprintf(fp, "Initial List2: ");
        print_list(&list2);
        fprintf(fp, "Merging two empty Lists...\n");
        list = merge_lists(list1, list2);
        fprintf(fp, "Result : ");
        print_list(&list);
        check1 = compare_lists(&list, expected_list, expected_list_length);
        if(check1) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
    }/*-check1*/

    /*check2*/{
        fprintf(fp, "\n--- check2 ----\n");
        struct node* list = NULL;
        struct node* list2 = NULL;
        int to_be_list1[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        struct node* list1 = array_to_list(to_be_list1, 13);
        int expected_list_length = 13;
        int expected_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List1: ");
        print_list(&list1);
        fprintf(fp, "Initial List2: ");
        print_list(&list2);
        fprintf(fp, "Merging two Lists one of them is empty...\n");
        list = merge_lists(list1, list2);
        fprintf(fp, "Result : ");
        print_list(&list);
        check2 = compare_lists(&list, expected_list, expected_list_length);
        if(check2) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
        delete_list(&list1);
    }/*-check2*/

    /*check3*/{
        fprintf(fp, "\n--- check3 ----\n");
        struct node* list = NULL;
        int to_be_list1[6] = {13, 99, 19, 5, 10, 10};
        struct node* list1 = array_to_list(to_be_list1, 6);
        int to_be_list2[7] = {10, 15, 45, 55, 5, 10, 85};
        struct node* list2 = array_to_list(to_be_list2, 7);;
        int expected_list_length = 13;
        int expected_list[13] = {13, 99, 19, 5, 10, 10, 10, 15, 45, 55, 5, 10, 85};
        fprintf(fp, "Initial List1: ");
        print_list(&list1);
        fprintf(fp, "Initial List2: ");
        print_list(&list2);
        fprintf(fp, "Merging two Lists...\n");
        list = merge_lists(list1, list2);
        fprintf(fp, "Result : ");
        print_list(&list);
        check3 = compare_lists(&list, expected_list, expected_list_length);
        if(check3) fprintf(fp, "   (true)");
        else fprintf(fp, "   (false)");
        fprintf(fp, "\n");
        delete_list(&list);
        delete_list(&list1);
        delete_list(&list2);
    }/*-check3*/

    return check1&&check2&&check3;
}
