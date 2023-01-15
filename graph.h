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
} node, *pnode;

void build_graph_cmd(pnode *head, pnode *tail, int nodes);
void insert_node_cmd(pnode *head , int vertice);
void delete_node_cmd(pnode *head , int vertice);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

void addEdge(pnode head , int src , int dest , int weight);
void delete_edges(pnode *head , int ver);
void removeEdge(pnode node,int node_id);
void removeFirstEdge(pnode node);


#endif
