#include<stdio.h>
#include <stdlib.h>
#include "graph.h"

void deleteGraph_cmd(pnode* head)
{
    pnode currNode = *head, nodeTmp = NULL;
    pedge currEdge = NULL, edgeTmp = NULL;
    while(currNode != NULL)
    {
        currEdge = currNode->edges;
        while (currEdge != NULL)
        {
            edgeTmp = currEdge;
            currEdge = currEdge->next;
            free(edgeTmp); 
        }
        currNode->edges = NULL;
        nodeTmp = currNode;
        currNode = currNode->next;
        free(nodeTmp);
    }
    *head = NULL;

}

void build_graph_cmd(pnode *head, pnode *tail, int nodes)
{
    int i = 0;
    pnode newTail = *head;
    if(nodes > 0)
    {
        pnode newhead = (pnode)malloc(sizeof(node));
        newhead->node_num = i++;
        newhead->next= *head;
        newhead->edges = NULL;
        *head = newhead;

        newTail = *head;

        for (; i < nodes; i++)
        {
            pnode newnode = (pnode)malloc(sizeof(node));
            newnode->node_num = i;
            newnode->edges = NULL;
            newnode->next = NULL;
            newTail->next=newnode;
            newTail = newnode;
        }
    }  

    *tail = newTail;
}

void addEdge(pnode head , int src , int dest , int weight)
{
    printf("in add adge\n");
    printf("head id is: %d\n" , head->node_num);
    pnode src_node = head;
    while (src_node->node_num != src && src_node != NULL)
    {
        src_node = src_node->next;
    }
    printf("src id is: %d\n" , src_node->node_num);
    printf("after while number 1\n");

    printf("head id is: %d\n" , head->node_num);
    pnode dest_node = head;
    while (dest_node->node_num != dest && dest_node != NULL)
    {
        printf("dest id is: %d\n" , dest_node->node_num);
        dest_node = dest_node->next;
    }
    printf("dest id is: %d\n" , dest_node->node_num);
    printf("after while number 2\n");

    pedge n_edge = (pedge)malloc(sizeof(edge));
    n_edge->weight = weight;
    n_edge->endpoint = dest_node;
    n_edge->next = src_node->edges;

    src_node->edges = n_edge;
}

void insert_node_cmd(pnode *head , int vertice)
{
    pnode headNode = *head;
    pedge currEdge = NULL, edgeTmp = NULL;
    int exist = 0 , dest = -1, w = -1;

    pnode newNode = (pnode)malloc(sizeof(node));
    newNode->node_num = vertice;
    newNode->edges = NULL;

    while(headNode != NULL && !exist)
    {
        if(headNode->node_num == vertice)
        {
            exist = 1;
        }
        else
        {
            headNode = headNode->next;
        }
    }

    if(exist)
    {
        currEdge = headNode->edges;
        while (currEdge != NULL)
        {
            edgeTmp = currEdge;
            currEdge = currEdge->next;
            free(edgeTmp); 
        }
        headNode->edges = NULL;

        while (scanf("%d" , &dest) == 1)
        {
            printf("dest is: %d\n" , dest);
            printf("in while\n");
            scanf("%d" , &w);
            printf("w is: %d\n" , w);
            addEdge(*head , vertice , dest , w);
        }
    }
    else
    {
        headNode = *head;
        while(headNode != NULL)
        {
            if(headNode->node_num > vertice)
            {
                break;
            }      

            headNode = headNode->next;
        }

        if(headNode != NULL)
        {
            newNode->next = headNode->next;
            headNode->next = newNode;
            while (scanf("%d" , &dest) == 1)
            {
                printf("dest is: %d\n" , dest);
                printf("in while\n");
                scanf("%d" , &w);
                printf("w is: %d\n" , w);
                addEdge(*head , vertice , dest , w);
            }
        }
        else
        {
            headNode = *head;
            while(headNode->next != NULL)
            {
                headNode = headNode->next;
            }
            headNode->next = newNode;
            newNode->next = NULL;
            while (scanf("%d" , &dest) == 1)
            {
                printf("dest is: %d\n" , dest);
                printf("in while\n");
                scanf("%d" , &w);
                printf("w is: %d\n" , w);
                addEdge(*head , vertice , dest , w);
            }
        }
    }
}

void delete_node_cmd(pnode *head , int vertice)
{
    printf("in delete\n");
    pnode currNode = *head, nodeTmp = NULL;
    pedge currEdge = NULL, edgeTmp = NULL;
    int exist = 0;
    if(currNode->node_num == vertice)
    {
        currEdge = currNode->edges;
        while (currEdge != NULL)
        {
            edgeTmp = currEdge;
            currEdge = currEdge->next;
            free(edgeTmp); 
        }
        currNode->edges = NULL;
        nodeTmp = currNode;
        currNode = currNode->next;
        free(nodeTmp);
        *head = currNode;
    }
    else
    {
        while(currNode->next != NULL)
        {
            if(currNode->next->node_num == vertice)
            {
                exist = 1;
                break;
            }
            currNode = currNode->next;
        }
    }

    printf("exist is: %d\n" , exist);
    printf("currNode is: %d\n" , currNode->node_num);
    printf("next node is: %d\n" , currNode->next->node_num);


    if(exist)
    {
        currEdge = currNode->next->edges;
        while (currEdge != NULL)
        {
            edgeTmp = currEdge;
            currEdge = currEdge->next;
            free(edgeTmp); 
        }
        currNode->edges = NULL;
        nodeTmp = currNode;
        currNode = currNode->next;
        nodeTmp->next = currNode->next;
        free(nodeTmp);
    }
}
