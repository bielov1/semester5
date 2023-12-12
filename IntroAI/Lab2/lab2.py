# Вступ до штучного інтелекту. ЛР2
#
# Розробити інтелектуального агента-машину, що рахується
# по графу-дорозі з попередньої лабораторної роботи за заданими
# правилами та метою. Отримати практичні навички роботи з
# інтелектуальними агентами
#
# Бєлов Олег, IO-11, 11.12.2023


import networkx as nx
import matplotlib.pyplot as plt
import random
from queue import Queue

all_nodes = []

def neightbors(node):
    dirs = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    result = []
    for dir in dirs:
        neightbor = (node[0] + dir[0], node[1] + dir[1])
        if neightbor in all_nodes:
            result.append(neightbor)
    return result

def is_connected(graph):
    visited = set()
    stack = [list(graph.nodes)[0]]

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            stack.extend([n for n in graph.neighbors(node) if n not in visited])

    return len(visited) == len(graph.nodes)

def generate_graph(n, ke):
    for x in range(n):
        for y in range(n):
            all_nodes.append((x, y))

    G = nx.Graph()
    for node in all_nodes:
        G.add_node(node)
        for neigh in neightbors(node):
            G.add_edge(node, neigh)

    edges_removed = 0
    edges = list(G.edges)
    random.shuffle(edges)
    for edge in edges:
        if edges_removed >= ke:
            break

        G.remove_edge(*edge)
        if not is_connected(G):
            G.add_edge(*edge)
        else:
            edges_removed += 1

    return G

def bfs_path(graph, start, goal):
    visited_cities = set()
    queue = Queue()
    queue.put((start, [start]))

    while not queue.empty():
        current, path = queue.get()
        if current == goal:
            return path

        for neighbor in graph.neighbors(current):
            if neighbor not in visited_cities:
                visited_cities.add(neighbor)
                queue.put((neighbor, path + [neighbor]))

def visualize_graph(G, start_point, end_point, path=None):
    pos = {node: (node[0], node[-1]) for node in G.nodes()}
    nx.draw(G, pos, with_labels=False, node_size=300, node_color='grey', width=10, edge_color='orange')

    labels = {start_point: f"{start_point}", end_point: f"{end_point}"}
    nx.draw_networkx_labels(G, pos, labels, font_size=12)

    if path:
        path_edges = list(zip(path, path[1:]))
        nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color='purple', width=2)
        nx.draw_networkx_nodes(G, pos, nodelist=path, node_color='pink', node_size=300)

    plt.show()

if __name__ == '__main__':
    try:
        n = int(input("Enter n: "))
        kill_e = int(input("Enter number of edges to remove: "))
        if n < 0 or kill_e < 0:
            print("Please enter positive numbers for n and number of edges to remove.")
        else:
            G = generate_graph(n, kill_e)

            while True:
                print("Starting point:")
                start_row = int(input("Row: "))
                start_column = int(input("Column: "))
                if 0 <= start_row < n and 0 <= start_column < n:
                    start_point = (start_row, start_column)
                    break
                else:
                    print("Invalid start point. Please enter values between 0 and", n-1)

            while True:
                print("Ending point:")
                end_row = int(input("Row: "))
                end_column = int(input("Column: "))
                if 0 <= end_row < n and 0 <= end_column < n:
                    end_point = (end_row, end_column)
                    break
                else:
                    print("Invalid end point. Please enter values between 0 and", n-1)

            path = bfs_path(G, start_point, end_point)
            if path:
                print("Path found:", path)
                visualize_graph(G, start_point, end_point, path)
            else:
                print("No path found.")
    except ValueError:
        print("Invalid input. Please enter a number.")
