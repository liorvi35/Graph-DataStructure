#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <limits.h>
#include <string.h>

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
    if (nodes > 0)
    {
        pnode newhead = (pnode)malloc(sizeof(node));
        newhead->node_num = i++;
        newhead->next = *head;
        newhead->edges = NULL;
        *head = newhead;

        newTail = *head;

        for (; i < nodes; i++)
        {
            pnode newnode = (pnode)malloc(sizeof(node));
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
    printf("in add adge\n");
    printf("head id is: %d\n", head->node_num);
    pnode src_node = head;
    while (src_node->node_num != src && src_node != NULL)
    {
        src_node = src_node->next;
    }
    printf("src id is: %d\n", src_node->node_num);
    printf("after while number 1\n");

    printf("head id is: %d\n", head->node_num);
    pnode dest_node = head;
    while (dest_node->node_num != dest && dest_node != NULL)
    {
        printf("dest id is: %d\n", dest_node->node_num);
        dest_node = dest_node->next;
    }
    printf("dest id is: %d\n", dest_node->node_num);
    printf("after while number 2\n");

    pedge n_edge = (pedge)malloc(sizeof(edge));
    n_edge->weight = weight;
    n_edge->endpoint = dest_node;
    n_edge->next = src_node->edges;

    src_node->edges = n_edge;
}

void insert_node_cmd(pnode *head, int vertice)
{
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("ADD %d\n", vertice);
    pnode headNode = *head;
    pnode head_copy = *head;
    pedge currEdge = NULL, edgeTmp = NULL;
    int exist = 0, dest = -1, w = -1;

    pnode newNode = (pnode)malloc(sizeof(node));
    newNode->node_num = vertice;
    newNode->edges = NULL;

    while (headNode != NULL && !exist)
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

    if (exist)
    {
        printf("exist!!\n");
        currEdge = headNode->edges;
        while (currEdge != NULL)
        {
            edgeTmp = currEdge;
            currEdge = currEdge->next;
            free(edgeTmp);
        }
        headNode->edges = NULL;

        while (scanf("%d", &dest) == 1)
        {
            printf("dest is: %d\n", dest);
            printf("in while\n");
            scanf("%d", &w);
            printf("w is: %d\n", w);
            addEdge(*head, vertice, dest, w);
        }
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
            printf("stop here: %d\n" , headNode->node_num);
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
                printf("dest is: %d\n", dest);
                printf("in while\n");
                scanf("%d", &w);
                printf("w is: %d\n", w);
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
                printf("dest is: %d\n", dest);
                printf("in while\n");
                scanf("%d", &w);
                printf("w is: %d\n", w);
                addEdge(*head, vertice, dest, w);
            }
        }
    }
}

void delete_node_cmd(pnode *head, int vertice)
{
    delete_edges(head, vertice);
    node *current = *head;
    node **prev = head;
    int found = 0;
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
            removeFirstEdge(current);
        free(current);
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
    edge *newEdge = (node->edges);
    edge **prev = &(node->edges);
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
    }
}

void removeFirstEdge(pnode node)
{
    edge *new_edge = (node->edges);
    if (new_edge != NULL)
    {
        node->edges = new_edge->next;
        free(new_edge);
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

//An auxiliary function that given an array and an index, it returns a copy of that array without the index
int* copyArray(int *arr, int remove, int length){
    int *copy = (int*)malloc(sizeof(int)*(length-1));
    if(copy==NULL){
        printf("No Memory");
        exit(0);
    }
    int i,count=0;
    for (i = 0; i < length; i++)
    {
        if(i!=remove){
            copy[count] = arr[i];
            count++;
        }
    }
    return copy;

}

//An auxiliary function to get the shortest path
int min(int x,int y,int w){
    if(x==-1 && y==-1)
        return -1;
    if(x==-1)
        return y + w;
    if(y==-1)
        return x;
    if(x<=(y+w))
        return x;
    return y+w;
}

//The opisite of placeCalc - calculate the node id by its positon in the graph
int get_Id_by_Pos(pnode *head, int pos, int amount_of_Nodes){
    int place = amount_of_Nodes-1;
    int found = 0;
    node *current = *head;
    while (current!= NULL && found == 0){
        if(place == pos)
            found = 1;
        else{
            place--;
            current = current -> next;
        }
    }
    return current-> node_num;
}

//An auxiliary function used by dijkstra, will return -1 in case the node doesn't exist
int placeCalc(pnode *head, int node_id,int amount_of_Nodes){
    int place = amount_of_Nodes-1;
    int found = 0;
    node *current = *head;
    while (current!= NULL && found == 0){
        if(current -> node_num == node_id)
            found = 1;
        else{
            place--;
            current = current -> next;
        }
    }
    return place;
}

//The main TSP function
int TSP_cmd(pnode *head,int *cities, int length,int amount_of_Nodes){
    int minDist = -1, i;
    //Easy Cases
    if(length == 0 || length == 1)
        minDist = 0;
    //Run the TSP algorithm
    else{
        for (i = 0; i < length; i++)
        {
            int *copy = copyArray(cities,i,length);
            minDist = min(minDist,TSPalgorithm(head,copy,cities[i],length-1, amount_of_Nodes),0);
        }
    }
    //Deallocate the memory of the array
    free(cities);
    return minDist;
}

// This function is the tsp algorithm
int TSPalgorithm(pnode *head,int *cities,int start,int length,int amount_of_Nodes){
    int res = -1,minDist = -1,i, path,tsp;
    // Base Cases
    if(length == 0)
        res = 0;
    else if(length == 1)
        res =  shortsPath_cmd(*head,start,cities[0]);
        //Recursive Tsp call on a smaller amount of cities
    else{
        for (i = 0; i < length; i++)
        {
            int *copy = copyArray(cities,i,length);
            path = shortsPath_cmd(*head,start,cities[i]);
            if(path != -1){
                tsp = TSPalgorithm(head,copy,cities[i],length-1,amount_of_Nodes);
                minDist = min(minDist, tsp,path);
            }
            else{
                free(copy);
            }

        }
        res = minDist;
    }
    //Deallocate the memory
    free(cities);
    return res;
}







