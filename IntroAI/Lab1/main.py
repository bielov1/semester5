import networkx as nx
import matplotlib.pyplot as plt

all_nodes = []

def neightbors(node):
	dirs = [[1, 0], [0, 1], [-1, 0], [0, -1]]
	result = []
	for dir in dirs:
		neightbor = (node[0] + dir[0], node[1] + dir[1])
		if neightbor in all_nodes:
			result.append(neightbor)

	return result

def generate_graph(n):
	for x in range(n):
		for y in range(n):
			all_nodes.append((x, y))

	G = nx.Graph()
	for node in all_nodes:
		G.add_node(node)
		for neigh in neightbors(node):
			G.add_edge(node, neigh)


	pos = {node: (node[0], node[-1]) for node in G.nodes()}
	nx.draw(G, pos, with_labels=True, node_size=300, node_color='grey', width = 5, edge_color='pink')

	edges = list(G.edges)
	plt.show()

if __name__ == '__main__':
	n = int(input("Enter n: "))
	generate_graph(n)
