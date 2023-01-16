import random
import sys
import subprocess
passed = 1
'''
import itertools
import networkx as nx
import matplotlib.pyplot as plt
'''
def run_cmd(cmd , verbos = 1):
    if verbos == 1:
        print("running: " ,cmd)
    try:
        proc = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE , stderr=subprocess.PIPE)
        proc.wait()
        if proc.returncode != 0:
           raise Exception(" failed p.returncode= " + str(proc.returncode))
    except Exception as inst:
        print("command failed")
        print(inst)
        raise Exception(" failed p.returncode= " + str(proc.returncode))
    
def test_memory(prog , input_f ):
    global passed
    try:
        run_cmd("valgrind --leak-check=full --error-exitcode=1 ./%s < %s > /dev/null"%(prog ,input_f ))
    except Exception as inst:
        print("valgrind failed on input %s"%(input_f) )
        passed = 0


class Node:
    def __init__(self, num):
        self.num = num
        self.edges = {}

    def add_edge(self, node, weight):
        self.edges[node] = weight
   

class Graph:
    def __init__(self):
        self.nodes = {}

    def add_node(self, num):
        new_node = Node(num)
        self.nodes[num] = new_node

    def add_edge(self, start, end, weight):
        if start not in self.nodes:
            self.add_node(start)
        if end not in self.nodes:
            self.add_node(end)
        self.nodes[start].add_edge(self.nodes[end], weight)
        
    def __str__(self):
        graph_str = ""
        for node in self.nodes.values():
            graph_str += f"n {node.num} "
            for edge, weight in node.edges.items():
                graph_str += f"{edge.num} {weight} "

        return graph_str

'''
    def Dijkstra(self, start_node, end_node):
        """
        Find the shortest path between start_node and end_node
        """
        # initialize distances to infinity for all nodes
        distances = {node: float('inf') for node in self.nodes.values()}
        # distance from start_node to start_node is 0
        distances[start_node] = 0
        # initialize previous node for all nodes to None
        previous = {node: None for node in self.nodes.values()}
        # initialize unvisited set with all nodes
        unvisited = set(self.nodes.values())
        
        # while there are still unvisited nodes
        while unvisited:
            # find the unvisited node with the smallest distance
            current = min(unvisited, key=lambda node: distances[node])
            # mark the current node as visited
            unvisited.remove(current)
            # if current node is the end node, we have found the shortest path
            if current == end_node:
                # initialize empty path
                path = []
                # starting from the current node
                node = current
                # go backwards through previous nodes to construct the path
                while node:
                    path.append(node)
                    node = previous[node]
                # reverse the path and return it
                return list(reversed(path))
            
            # if not, update the distances and previous nodes for all neighboring nodes
            for neighbor, weight in current.edges.items():
                if neighbor in unvisited:
                    new_distance = distances[current] + weight
                    if new_distance < distances[neighbor]:
                        distances[neighbor] = new_distance
                        previous[neighbor] = current


def shortest_path(graph, nodes_list):
    """
    Find the shortest path through a list of nodes
    """
    start_node = graph.nodes[nodes_list[0]]
    path = 0
    for i in range(len(nodes_list) - 1):
        end_node = graph.nodes[nodes_list[i+1]]
        pathIToI1 = graph.Dijkstra(start_node, end_node)
        if pathIToI1 == None:
            return -1
        nodes_num = [node.num for node in pathIToI1]
        #print(nodes_num)
        path += sum(nodes_num)
        start_node = end_node
    return path
'''

# create a graph with X nodes
num_of_edges = int(sys.argv[1])
graph = Graph()
for i in range(num_of_edges):
    graph.add_node(i)

# create edges between nodes with random weights
for node in graph.nodes.values():
    num_edges = random.randint(2, 10)
    for i in range(num_edges):
        end_node = random.choice(list(graph.nodes.values()))
        while end_node == node:
            end_node = random.choice(list(graph.nodes.values()))
        weight = random.randint(1, 10)
        node.add_edge(end_node, weight)
s = "A "+str(num_of_edges)+" "+str(graph)
print(s)
with open('tmp.txt', 'w') as f:
    f.write(s+str("D 0 "))
test_memory("graph" , "tmp.txt" )
if passed == 1:
    print("You have PASSED the initial checks.")
else:
    print("You have FAILED the initial checks. go fix your code.")
    


'''
G = nx.DiGraph()

for node in graph.nodes.values():
    G.add_node(node.num)
    for neighbor, weight in node.edges.items():
        G.add_edge(node.num, neighbor.num, weight=weight)

pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True)
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)
plt.show()

k = int(input("Enter a number between 1 and 6: "))

#get all possible permutations of k randomly chosen nodes
random_nodes = random.sample(list(graph.nodes.values()), k)
random_nodes_num = [node.num for node in random_nodes]
permutations = list(itertools.permutations(random_nodes_num))
print(random_nodes_num)


# keep track of the shortest path and its length
min_path = float('inf')

# find the shortest path through all permutations
for perm in permutations:
    #start_node = perm[0]
    print(perm)    
    path = shortest_path(graph,perm)
    print(path)
    #path_length = sum([edge.edges[path[i + 1]] for i in range(len(path) - 1)])
    #print(path_length)
    if path < min_path:
        min_path = path

        
print("TSP shortest path: {}".format(min_path))
'''

