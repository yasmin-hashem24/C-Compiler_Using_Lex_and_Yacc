#include "node.h"
ListNode *head = NULL;

void addNodeToList(nodeType *node)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->node = node;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        ListNode *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}
