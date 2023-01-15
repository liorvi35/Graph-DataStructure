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
