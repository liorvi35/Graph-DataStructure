int shortest_path_held_karp(int num_nodes, int *nodes_list, int num_of_specific_nodes, int **dist) {
    // create a lookup table for storing the minimum distances
    int **lookup_table = (int**)malloc(sizeof(int*) * (1 << num_of_specific_nodes));
    for (int i = 0; i < (1 << num_of_specific_nodes); i++) {
        lookup_table[i] = (int*)malloc(sizeof(int) * num_of_specific_nodes);
        for (int j = 0; j < num_of_specific_nodes; j++) {
            lookup_table[i][j] = INFINITE;
        }
    }
    // set the distance from a node to itself to 0
    for (int i = 0; i < num_of_specific_nodes; i++) {
        lookup_table[1 << i][i] = 0;
    }
    // fill the lookup table using dynamic programming
    for (int i = 0; i < (1 << num_of_specific_nodes); i++) {
        for (int j = 0; j < num_of_specific_nodes; j++) {
            if (lookup_table[i][j] == INFINITE) {
                continue;
            }
            for (int k = 0; k < num_of_specific_nodes; k++) {
                if (i & (1 << k)) {
                    continue;
                }
                int new_dist = lookup_table[i][j] + dist[nodes_list[j]][nodes_list[k]];
                lookup_table[i | (1 << k)][k] = min(lookup_table[i | (1 << k)][k], new_dist);
            }
        }
    }
    // find the minimum distance
    int min_distance = INFINITE;
    for (int i = 0; i < num_of_specific_nodes; i++) {
        min_distance = min(min_distance, lookup_table[(1 << num_of_specific_nodes) - 1][i]);
    }
    // free the lookup table
    for (int i = 0; i < (1 << num_of_specific_nodes); i++) {
        free(lookup_table[i]);
    }
    free(lookup_table);
    return min_distance;
}
