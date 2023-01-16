
int TSP_cmd(pnode *head,int *nodes, int size){
    int distance = -1;
    int i = -1;
    int *copy = NULL;
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

int TSPalgorithm(pnode *head,int *nodes,int start,int size){
    int res = -1,distance = -1,i, path,tsp;
    if(size == 0)
        res = 0;
    else if(size == 1)
        res =  shortsPath_cmd(*head,start,nodes[0]);
    else{
        for (i = 0; i < size; i++)
        {
            int *copy = deepcopy(nodes,i,size);
            path = shortsPath_cmd(*head,start,nodes[i]);
            if(path != -1){
                tsp = TSPalgorithm(head,copy,nodes[i],size-1);
                distance = getMin(distance, tsp,path);
            }
            else{
                free(copy);
            }
        }
        res = distance;
    }
    free(nodes);
    return res;
}


