#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void printGraph_cmd(pnode head){
    // Go over the nodes and print for each Id:_ ,edges{ d:_ ,w:_, ... , } 
    node *current = head;
    while(current != NULL)
    {
        printf("Id: %d, egdes{",current->node_num);
        edge *cur = current -> edges;
        while(cur != NULL){
            printf("d:%d w:%d, ",cur -> endpoint -> node_num,cur -> weight);
            cur = cur->next;
        }
        printf("}\n");
        current = current->next;
    }
}

int main()
{
    char ch = '\0';
    int nodes = 0;
    int dest = -1;
    int w = -1;
    int src = -1;
    int v = -1;
    int start = -1 , end = -1;
    int tsp = -1;
    int* arr = NULL;

    pnode head = NULL;
    pnode tail = NULL;

    while(scanf("%c" , &ch) != EOF)
    {
        BACK:
        if(ch == 'A')
        {
            deleteGraph_cmd(&head);
            scanf("%d" , &nodes);
            build_graph_cmd(&head, &tail , nodes);
        }

        if(ch == 'n')
        {
                        
            while (ch == 'n')
            {
                ch = '\0';
                scanf("%d" , &src);

                // 2 ints 
                // char and int

                while (scanf("%d" , &dest) == 1)
                {
                    scanf("%d" , &w);
                    addEdge(head , src , dest , w);
                }
                scanf(" %c" , &ch);
            }
            goto BACK;
        }

        if(ch == 'B')
        {
            scanf("%d" , &v);
            insert_node_cmd(&head , v);
            v = -1;
        }

        if(ch == 'D')
        {
            scanf("%d" , &v);
            delete_node_cmd(&head , v);
            v = -1;
        }

        if(ch == 'S')
        {
            scanf("%d" , &start);
            scanf("%d" , &end);
            printf("Dijsktra shortest path: %d \n" ,shortsPath_cmd(head , start , end));
        }

        if(ch == 'T')
        {
            scanf("%d" , &tsp);
            arr = (int*)calloc(tsp , sizeof(int));
            for (int i = 0; i < tsp; i++)
            {
                scanf("%d" , &arr[i]);
            }
            printf("TSP shortest path: %d \n" ,TSP_cmd(&head , arr , tsp));
        }
    }
    deleteGraph_cmd(&head);

    return 0;
}
