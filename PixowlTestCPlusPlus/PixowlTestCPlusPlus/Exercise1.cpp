#include "funcPixowl.h"

//
//Exercise 2
//

void Add(struct node** head_ref, int new_value)
{
    //Declare new node
    struct node* new_node = new node;

    cout << "El programa corta con 0" << "\n";
    cout << "Se agrega nodo: " << new_node << "\n";
    cout << "Se agrega valor al nodo: ";
    
    cin >> new_value;

    //Copy value in the new node value
    if (new_value != 0)
    {
        new_node->value = new_value;

        //Link the old list to the new node
        new_node->next = (*head_ref);

        //Move the head to point to the new node */
        (*head_ref) = new_node;

        Add(head_ref, new_value);
    }
}

void SumNodes(struct node* head, int* sum)
{
    //Validate head is not null
    if (!head)
        return;

    // recursively traverse the remaining nodes
    SumNodes(head->next, sum);

    //Sum
    *sum = *sum + head->value;
}

int SumNodesUtil(struct node* head)
{

    int sum = 0;

    // find the sum of  nodes
    SumNodes(head, &sum);

    // required sum
    return sum;
}

int Exercise1()
{
    cout << "/-------------------\\ \n";
    cout << "|  Pixowl C++ Test  | \n";
    cout << "\\-------------------/ \n";
    cout << "\n";
    cout << "\\-----EXercise1-----/ \n";
    cout << "\n";

    struct node* head = NULL;

    Add(&head, 0);

    cout << "Sum of nodes = "
        << SumNodesUtil(head)
        << "\n"
        << "\n";
    return 0;
}