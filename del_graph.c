void deleteGraph_cmd(pnode *head) 
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
