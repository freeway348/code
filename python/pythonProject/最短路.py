from math import inf
from typing import List


class Graph:
    def __init__(self, n: int, edges: List[List[int]]):  # edges为有向边三元组(x, y, 权重)
        self.a = [[] for _ in range(n)]
        self.n = n

        # 邻接表
        for x, y, w in edges:
            self.a[x].append((w, y))


    def dijkstra(self, start: int, end: int):  # 返回最短路径及其长度，找不到返回-1
        n = self.n
        vis = [False] * n
        dis = [inf] * n
        path = [None] * n  # 初始化路径数组
        dis[start] = 0
        path[start] = [start]  # 起点到自己的路径只有一个点

        pq = [(0, start)]  # 优先队列，用于存储待处理的节点

        while pq:
            current_distance, current_node = heapq.heappop(pq)

            if current_node == end:  # 如果已经到达目标节点，提前返回
                return dis[end], path[end]

            if vis[current_node]:
                continue

            vis[current_node] = True

            for neighbor_weight, neighbor_node in self.a[current_node]:
                if not vis[neighbor_node] and current_distance + neighbor_weight < dis[neighbor_node]:
                    dis[neighbor_node] = current_distance + neighbor_weight
                    path[neighbor_node] = path[current_node] + [neighbor_node]  # 更新路径
                    heapq.heappush(pq, (dis[neighbor_node], neighbor_node))

        return -1, []  # 如果没有找到路径，返回-1和空列表


if __name__ == '__main__':
    import heapq  # 导入heapq库以使用heapq.heappop和heapq.heappush

    # 图的顶点数和边
    n = int(input("请输入图的点的数目："))
    m = int(input("请输入图的边的数目："))
    # 测试数据
    edges = []
    for i in range(m):
        element1 = int(input(f"请输入第{i + 1}条边的起点: "))
        element2 = int(input(f"请输入第{i + 1}条边的终点: "))
        element3 = int(input(f"请输入这两个点之间的距离: "))
        edges.append((element1, element2, element3))
        # 创建图对象
    graph = Graph(n, edges)

    # 要测试的起点和终点
    node1 = int(input("请输入起点："))
    node2 = int(input("请输入终点："))

    shortest_distance, shortest_path = graph.dijkstra(node1, node2)

    if shortest_distance != -1:
        print("最短距离:", shortest_distance)
        print("最短路径:", shortest_path)
    else:
        print("没有找到路径")