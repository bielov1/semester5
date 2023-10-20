# Вступ до штучного інтелекту. ЛР1
#
# Розробити алгоритм генерації дороги у вигляді графу.
# Зі згенерованого графу видалити певну кількість ребер так,
# щоб результуючий граф залишився повністю зв'язним.
#
# Бєлов Олег, IO-11, 20.10.2023


import networkx as nx
import matplotlib.pyplot as plt
import random

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

	# removing fixed number of edges so the graph keeps being connected
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


		
	pos = {node: (node[0], node[-1]) for node in G.nodes()}
	nx.draw(G, pos, with_labels=False, node_size=300, node_color='grey', width = 10, edge_color='orange')
	plt.show()

if __name__ == '__main__':
	while True:
		try:
			n = int(input("Enter n: "))
			kill_e = int(input("Enter number of edges to remove: "))
			if(n < 0 or kill_e < 0):
				print("Something went wrong. Please, enter positive number for values ")
			else:
				break
		except ValueError:
			print("Panic! wrong input")
	generate_graph(n, kill_e)
