#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    int dist;
    int visited;
} node, *pnode;

void build_graph_cmd(pnode *head, pnode *tail, int nodes);
void insert_node_cmd(pnode *head , int vertice);
void delete_node_cmd(pnode *head , int vertice);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
int shortsPath_cmd(pnode head, int n1, int n2);
int TSP_cmd(pnode *head,int *cities, int length,int amount_of_Nodes);

void addEdge(pnode head , int src , int dest , int weight);
void delete_edges(pnode *head , int ver);
void removeEdge(pnode node,int node_id);
void removeFirstEdge(pnode node);
int TSPalgorithm(pnode *head,int *cities,int start,int length,int amount_of_Nodes);



#endif
