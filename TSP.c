int TSP(pnode head, int size) {
    int *visited = calloc(size, sizeof(int));
    int *path = calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        scanf("%d", &path[i]);
    }

    int min_cost = INT_MAX;
    do {
        int cost = 0;
        int prev = path[0];
        visited[prev - 1] = 1;
        for (int i = 1; i < size; i++) {
            int current = path[i];
            pnode start = head;
            while (start) {
                if (start->node_num == prev) {
                    pedge e = start->edges;
                    while (e) {
                        if (e->endpoint->node_num == current) {
                            cost += e->weight;
                            break;
                        }
                        e = e->next;
                    }
                    break;
                }
                start = start->next;
            }
            prev = current;
            visited[prev - 1] = 1;
        }
        if (cost < min_cost) {
            min_cost = cost;
        }
        memset(visited, 0, size*sizeof(int));
    } while (next_permutation(path, path + size));

    free(visited);
    free(path);
    return min_cost;
}

void next_permutation(int *arr, int size) {
    int i = size - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }
    if (i >= 0) {
        int j = size - 1;
        while (j > i && arr[j] <= arr[i]) {
            j--;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    reverse(arr + i + 1, arr + size);
}

void reverse(int *begin, int *end) {
    while (begin < --end) {
        int temp = *begin;
        *begin++ = *end;
        *end = temp;
    }
}
