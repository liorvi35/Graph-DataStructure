#include <stdio.h>
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

    pnode head = NULL;
    pnode tail = NULL;

    while(scanf("%c" , &ch) != EOF)
    {
        if(ch == 'A')
        {
            printf("in if number 1\n");
            //deleteGraph_cmd(&head);
            scanf("%d" , &nodes);
            printf("nodes is: %d\n" , nodes);
            build_graph_cmd(&head, &tail , nodes);
            printGraph_cmd(head);
            scanf(" %c" , &ch);
            printf("ch is: %c\n" , ch);
            if(ch == 'n')
            {
                printf("in if number 2\n");

                scanf("%d" , &src);
                printf("src is: %d\n" , src);

                // 2 ints 
                // char and int

                while (scanf("%d" , &dest) == 1)
                {
                    printf("dest is: %d\n" , dest);
                    printf("in while\n");
                    scanf("%d" , &w);
                    printf("w is: %d\n" , w);
                    addEdge(head , src , dest , w);
                }
            }
        }
    }

    if(head == NULL)
    {
        printf("error\n");
    }
    printGraph_cmd(head);

    return 0;
}
