import matplotlib.pyplot as plt
import numpy as np
import networkx as nx

G = nx.Graph()
G.add_edges_from([('A', 'B')], weight=4)
G.add_edges_from([('B', 'D')], weight=2)
G.add_edges_from([('D', 'C'), ('A', 'C'), ('C', 'E')], weight=3)
G.add_edges_from([('E', 'F')], weight= 4)
G.add_edges_from([('F', 'A')], weight=2) 

edge_labels=dict([((u,v,), d['weight']) for u,v,d in G.edges(data=True)])   #creates a dictionary with all edge labels

route = nx.shortest_path(G, 'E', 'B', weight='weight')      #calculate te path 
print(route)

red_edges = []              #auxiliar array to save all route edges

for i in range(0, len(route)-1):            #creates tuples of each read edge from the list (left to right)
    red_edges.append(tuple((route[i], route[i+1])))


for i in range(len(route)-1, 0, -1):        #creates tuples of each read edge from the list (right to left)
    red_edges.append(tuple((route[i], route[i-1])))

edge_colors = ['red' if edge in red_edges else 'black' for edge in G.edges()]

pos = nx.spring_layout(G)
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)
nx.draw(G,pos, node_color="skyblue", node_size=500, edge_color=edge_colors, with_labels=True)
plt.show()
