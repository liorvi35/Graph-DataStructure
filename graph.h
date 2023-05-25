/**
 * @brief This file contains declarations for a graph structure.
 *
 * The graph data structure has the following features:
 * 'A' - Create a new graph.
 * 'B <new-node-num>' - Create a new node in an existing graph.
 * 'D <existing-node-num>' - Delete an existing node and all its edges.
 * 'S <existing-node-num-1> <existing-node-num-2>' - Print the shortest paths between two nodes.
 * 'T <K> <existing-node-num-1> ... <existing-node-num-K>' - Print the shortest path that passes through K nodes.
 *
 * This data structure is represented as a linked list of linked lists.
 * The use of linked lists for representation is more space-efficient than an adjacency matrix
 */


#ifndef GRAPH_H

    /**
     * @brief A flag to mark the header file (so wont be included more than once in total).
     */
	#define GRAPH_H

    /**
     * @brief Pointer to a graph node structure.
     */
	typedef struct GRAPH_NODE_ *pnode;

    /**
     * @brief A structure that represents edge in graph.
     * sub linked-list
     */
	typedef struct edge_
	{
        /* edges weight */
	    int weight;

        /* 'right' node in edge */
	    pnode endpoint;

        /* next */
	    struct edge_ *next;
	} edge, *pedge;

    /**
     * @brief a structure that represents node in graph.
     * main linked-list
     */
	typedef struct GRAPH_NODE_
	{
        /* sub list of neighbors */
	    pedge edges;

        /* node number */
        int node_num;

        /* next */
	    struct GRAPH_NODE_ *next;

        /* shortest distance */
        int dist;

        /* is visited flag */
	    int visited;
	} node, *pnode;

    /**
     * @brief Constructs a graph command by creating and connecting nodes.
     * @param pnode* Pointer to the head of the existing graph.
     * @param pnode* Pointer to the tail of the existing graph.
     * @param int Number of nodes to create and add to the graph.
     */
	void build_graph_cmd(pnode*, pnode*, int);

    /**
     * @brief Inserts a node command by adding a new node to the graph and connecting it with existing nodes.
     * @param pnode* Pointer to the head of the graph.
     * @param int The vertex number of the new node to be inserted.
     */
	void insert_node_cmd(pnode*, int);

    /**
     * @brief Deletes a node command by removing a node from the graph along with its edges.
     * @param pnode* Pointer to the head of the graph.
     * @param int The vertex number of the node to be deleted.
     */
	void delete_node_cmd(pnode*, int);

    /**
     * @brief Prints the graph command by displaying each node and its connected edges.
     * @param pnode Pointer to the head of the graph.
     */
	void printGraph_cmd(pnode);

    /**
     * @brief Deletes the entire graph command by removing all nodes and edges.
     * @param pnode* Pointer to the head of the graph.
     */
	void deleteGraph_cmd(pnode*);

    /**
     * @brief Calculates the shortest path between two nodes in the graph.
     * @param pnode Pointer to the head of the graph.
     * @param int The starting node
     * @param int The destination node.
     * @return The shortest path distance between n1 and n2. If no path exists, it returns -1.
     */
	int shortsPath_cmd(pnode, int, int);

    /**
     * @brief Calculates the shortest path that visits a given set of nodes in the graph.
     * @param pnode* Pointer to the head of the graph.
     * @param int* Array of nodes to be visited.
     * @param int Number of nodes in the array.
     * @return The shortest path distance that visits all the nodes exactly once and returns to the starting node. If no path exists, it returns -1.
     */
	int TSP_cmd(pnode*,int*, int);

    /**
     * @brief Adds an edge between two nodes in the graph.
     * @param pnode Pointer to the head of the graph.
     * @param int The source node number.
     * @param int The destination node number.
     * @param int The weight of the edge.
     */
	void addEdge(pnode, int, int, int);

    /**
     * @brief Deletes all edges connected to a specific node in the graph.
     * @param pnode* Pointer to the head of the graph.
     * @param int The vertex number of the node whose edges are to be deleted.
     */
	void delete_edges(pnode*, int);

    /**
     * @brief Removes an edge connected to a specific node.
     * @param pnode Pointer to the node from which the edge is to be removed.
     * @param int The vertex number of the endpoint node of the edge to be removed.
     */
	void removeEdge(pnode, int);

    /**
     * @brief Removes the first edge from a node.
     * @param pnode Pointer to the node from which the first edge is to be removed.
     */
	void removeFirstEdge(pnode);

    /**
     * @brief Traveling Salesman Problem (TSP).
     * @param pnode* Pointer to the head of the graph
     * @param int Array of nodes to be visited.
     * @param int The starting node
     * @param int* Number of nodes in the array
     * @return The minimum distance of the TSP path that visits all the nodes exactly once and returns to the starting node. If no path exists, it returns -1.
     */
	int TSPalgorithm(pnode*, int*, int, int);

    /**
     * @brief Creates a deep copy of an integer array with an element removed.
     * @param int* The original integer array.
     * @param int The index of the element to be removed.
     * @param int The size of the original array.
     * @return A deep copy of the original array with the specified element removed. If memory allocation fails, it returns NULL.
     */
    int* deepcopy(int*, int, int);

    /**
     * @brief Finds the shortest path.
     * @param int First vertex.
     * @param int Second vertex.
     * @param int Third vertex.
     * @return The shortest path.
     */
    int getMin(int, int, int)

#endif
