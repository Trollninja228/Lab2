import networkx as nx
from itertools import combinations

# Создание графа
G = nx.Graph()
G.add_weighted_edges_from([
    ('A', 'B', 2), ('B', 'C', 5), ('C', 'D', 4), ('D', 'E', 3),
    ('E', 'C', 6), ('E', 'F', 7), ('F', 'C', 6), ('F', 'B', 13),
    ('F', 'A', 7)
])

# Минимальный вес MST
mst_edges = list(nx.minimum_spanning_edges(G, data=True))
mst_weight = sum(edge[2]['weight'] for edge in mst_edges)
print("Минимальная длина дорог (вес MST):", mst_weight)

# Функция для подсчёта всех MST
def count_all_mst(graph, mst_weight):
    edges = list(graph.edges(data=True))
    total_nodes = len(graph.nodes)
    count = 0

    # Перебор всех подмножеств рёбер
    for subset in combinations(edges, total_nodes - 1):
        H = nx.Graph()
        H.add_edges_from((u, v, {'weight': d['weight']}) for u, v, d in subset)
        
        # Проверяем, соединены ли все вершины, и вес совпадает
        if nx.is_connected(H) and len(H.edges) == total_nodes - 1:
            if sum(d['weight'] for u, v, d in H.edges(data=True)) == mst_weight:
                count += 1

    return count

# Пересчитываем количество минимальных остовных деревьев
mst_count = count_all_mst(G, mst_weight)
print("Количество минимальных остовных деревьев:", mst_count)
