/**
 * @brief this file contains implementations for graph header.
 * @authors Lior Vinman & Yoad Tamar
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "graph.h"


void deleteGraph_cmd(pnode *head)
{
    pnode currNode = *head, nodeTmp = NULL;
    pedge currEdge = NULL, edgeTmp = NULL;

    while (currNode != NULL)
    {
        currEdge = currNode->edges;
        while (currEdge != NULL)
        {
            edgeTmp = currEdge;
            currEdge = currEdge->next;

            free(edgeTmp);
            edgeTmp = NULL;
        }
        currNode->edges = NULL;
        nodeTmp = currNode;
        currNode = currNode->next;

        free(nodeTmp);
        nodeTmp = NULL;
    }
    *head = NULL;
}


void build_graph_cmd(pnode *head, pnode *tail, int nodes)
{
    int i = 0;

    pnode newTail = *head, newhead =NULL, newnode = NULL;

    if (nodes > 0)
    {
        newhead = (pnode)malloc(sizeof(node));
        newhead->node_num = i++;
        newhead->next = *head;
        newhead->edges = NULL;
        *head = newhead;

        newTail = *head;

        for (; i < nodes; i++)
        {
            newnode = (pnode)malloc(sizeof(node));
            newnode->node_num = i;
            newnode->edges = NULL;
            newnode->next = NULL;
            newTail->next = newnode;
            newTail = newnode;
        }
    }
    *tail = newTail;
}


void addEdge(pnode head, int src, int dest, int weight)
{
    pnode src_node = head, dest_node = head;

    while (src_node->node_num != src && src_node != NULL)
    {
        src_node = src_node->next;
    }

    while (dest_node->node_num != dest && dest_node != NULL)
    {
        dest_node = dest_node->next;
    }

    pedge n_edge = (pedge)malloc(sizeof(edge));
    n_edge->weight = weight;
    n_edge->endpoint = dest_node;
    n_edge->next = src_node->edges;

    src_node->edges = n_edge;
}

void insert_node_cmd(pnode *head, int vertice)
{
    pnode headNode = *head, head_copy = *head, newNode = NULL;

    pedge currEdge = NULL, edgeTmp = NULL;

    int exist = 0, dest = -1, w = -1;

    newNode = (pnode)malloc(sizeof(node));
    newNode->node_num = vertice;
    newNode->edges = NULL;

    while(headNode != NULL && !exist)
    {
        if (headNode->node_num == vertice)
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
            edgeTmp = NULL;
        }
        headNode->edges = NULL;

        while (scanf("%d", &dest) == 1)
        {
            scanf("%d", &w);
            addEdge(*head, vertice, dest, w);
        }

        free(newNode);
        newNode = NULL;
    }
    else
    {
        headNode = *head;
        while (headNode != NULL)
        {
            if (headNode->node_num > vertice)
            {
                break;
            }

            headNode = headNode->next;
        }

        if(headNode != NULL)
        {
                while(head_copy->next->node_num != headNode->node_num)
            {
                head_copy = head_copy->next;
            }
        }

        if (headNode != NULL)
        {
            newNode->next = head_copy->next;
            head_copy->next = newNode;
            while (scanf("%d", &dest) == 1)
            {
                scanf("%d", &w);
                addEdge(*head, vertice, dest, w);
            }
        }
        else
        {
            headNode = *head;
            while (headNode->next != NULL)
            {
                headNode = headNode->next;
            }

            headNode->next = newNode;
            newNode->next = NULL;

            while (scanf("%d", &dest) == 1)
            {
                scanf("%d", &w);
                addEdge(*head, vertice, dest, w);
            }
        }
    }
}

void delete_node_cmd(pnode *head, int vertice)
{
    pnode current = *head, *prev = head;

    int found = 0;

    delete_edges(head, vertice);

    while (current != NULL && found == 0)
    {
        if (current->node_num == vertice)
        {
            *prev = current->next;
            found = 1;
        }
        else
        {
            prev = &(current->next);
            current = current->next;
        }
    }
    if (current != NULL)
    {
        while (current->edges != NULL)
        {
            removeFirstEdge(current);
        }
        free(current);
        current = NULL;
    }
}

void delete_edges(pnode *head, int ver)
{
    pnode currNode = *head;

    while (currNode != NULL)
    {
        removeEdge(currNode, ver);
        currNode = currNode->next;
    }
}

void removeEdge(pnode node, int vertice)
{
    pedge newEdge = (node->edges), *prev = &(node->edges);

    int found = 0;

    while (newEdge != NULL && found == 0)
    {
        if (newEdge->endpoint->node_num == vertice)
        {
            *prev = newEdge->next;
            found = 1;
        }
        else
        {
            prev = &(newEdge->next);
            newEdge = newEdge->next;
        }
    }
    if (found == 1)
    {
        free(newEdge);
        newEdge = NULL;
    }
}

void removeFirstEdge(pnode node)
{
    edge *new_edge = (node->edges);

    if (new_edge != NULL)
    {
        node->edges = new_edge->next;
        free(new_edge);
        new_edge = NULL;
    }
}

int shortsPath_cmd(pnode head, int n1, int n2)
{
    pnode current = head;

    while (current)
    {
        current->dist = INT_MAX;
        current->visited = 0;
        current = current->next;
    }

    current = head;
    while (current)
    {
        if (current->node_num == n1)
        {
            current->dist = 0;
            break;
        }
        current = current->next;
    }

    while (1)
    {
        int min_dist = INT_MAX;
        pnode min_node = NULL;
        current = head;
        while (current)
        {
            if (!current->visited && current->dist < min_dist)
            {
                min_dist = current->dist;
                min_node = current;
            }
            current = current->next;
        }
        if (!min_node)
        {
            break;
        }
        min_node->visited = 1;
        pedge e = min_node->edges;
        while (e)
        {
            if (e->endpoint->dist > min_node->dist + e->weight)
            {
                e->endpoint->dist = min_node->dist + e->weight;
            }
            e = e->next;
        }
    }
    current = head;
    while (current)
    {
        if (current->node_num == n2)
        {
            if (current->dist == INT_MAX)
            {
                return -1;
            }
            return current->dist;
        }
        current = current->next;
    }
    return -1;
}

int* deepcopy(int *arr, int index , int size)
{

    int i = 0 , j = 0;
    int *arrcopy = (int*)calloc(size -1 , sizeof(int));
    if(arrcopy == NULL)
    {
        perror("calloc() failed");

        free(arrcopy);
        arrcopy = NULL;

        exit(EXIT_FAILURE);
    }
    while(i<size)
    {
        if(i == index)
        {
            i++;
            continue;
        }
        else
        {
            arrcopy[j++] = arr[i++];
        }
    }
    return arrcopy;
}

int getMin(int a , int b , int c)
{
    int min = -1;

    if(a == min && b == min)
    {
        return min;
    }
    if(a == min && b != min)
    {
        return b + c;
    }
    if(a != min && b == min)
    {
        return a;
    }
    if(a>b+c)
    {
        return b + c;
    }

    return a;
}

int TSP_cmd(pnode *head, int *nodes, int size)
{
    int distance = -1, i = -1, *copy = NULL;

    if(size == 0 || size == 1)
    {
        distance = 0;
    }   
    else
    {
        for (i = 0; i < size; i++)
        {
            copy = deepcopy(nodes,i,size);
            distance = getMin(distance,TSPalgorithm(head,copy,nodes[i],size-1),0);
        }
    }

    free(nodes);
    nodes = NULL;

    return distance;
}

int TSPalgorithm(pnode *head, int *nodes, int start, int size)
{
    int res = -1, distance = -1, i = 0, path = 0, tsp = 0;

    if(size == 0)
    {
        res = 0;
    }
    else if(size == 1)
    {
        res =  shortsPath_cmd(*head,start,nodes[0]);
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            int *copy = deepcopy(nodes,i,size);
            path = shortsPath_cmd(*head,start,nodes[i]);
            if(path != -1)
            {
                tsp = TSPalgorithm(head,copy,nodes[i],size-1);
                distance = getMin(distance, tsp,path);
            }
            else
            {
                free(copy);
                copy = NULL;
            }
        }

        res = distance;
    }

    free(nodes);
    nodes = NULL;

    return res;
}
