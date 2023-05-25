/**
 * @brief this file contains the main program of using.
 * @authors Lior Vinman & Yoad Tamar
 */


#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main(int argc, char *argv[])
{
    int *arr = NULL;

    char ch = 0;

    int nodes = 0, dest = -1, w = -1,
        src = -1, v = -1, start = -1, end = -1, tsp = -1;

    pnode head = NULL;

    pnode tail = NULL;

    while(scanf("%c" , &ch) != EOF)
    {
        BACK:
        if(ch == 'A') // create new graph
        {
            deleteGraph_cmd(&head);
            scanf("%d" , &nodes);
            build_graph_cmd(&head, &tail , nodes);
        }

        if(ch == 'n') // nodes for creating graph (sub of 'A')
        {
            while(ch == 'n')
            {
                ch = '\0';
                scanf("%d" , &src);

                while (scanf("%d" , &dest) == 1)
                {
                    scanf("%d" , &w);
                    addEdge(head , src , dest , w);
                }
                scanf(" %c" , &ch);
            }
            goto BACK;
        }

        if(ch == 'B') // creates new node
        {
            scanf("%d" , &v);
            insert_node_cmd(&head , v);
            v = -1;
        }

        if(ch == 'D') // delete graph
        {
            scanf("%d" , &v);
            delete_node_cmd(&head , v);
            v = -1;
        }

        if(ch == 'S') // shortest paths
        {
            scanf("%d" , &start);
            scanf("%d" , &end);
            printf("Dijsktra shortest path: %d \n" ,shortsPath_cmd(head , start , end));
        }

        if(ch == 'T') // traveling salesman problem
        {
            scanf("%d" , &tsp);

            arr = (int*)calloc(tsp , sizeof(int));
            if(arr == NULL)
            {
                perror("calloc() failed");
                exit(EXIT_FAILURE);
            }

            for (int i = 0; i < tsp; i++)
            {
                scanf("%d" , &arr[i]);
            }
            printf("TSP shortest path: %d \n" ,TSP_cmd(&head , arr , tsp));
        }
    }

    deleteGraph_cmd(&head); // deleting graph at end of use

    return 0;
}
