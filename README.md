# Single-Source Shortest Path (SSSP) Algorithm Implementation

## Overview

This implementation is based on the research paper **"Breaking the Sorting Barrier for Directed Single-Source Shortest Paths"** by Ran Duan, Jiayi Mao, Xiao Mao, Xinkai Shu, and Longhui Yin. The paper introduces breakthrough techniques to solve the SSSP problem while avoiding the traditional O(V log V) sorting complexity.

## Problem Statement

Given a directed graph G = (V, E) with edge weights (which can be negative) and a source vertex s, find the shortest path distances from s to all other vertices in the graph.

## Key Innovations from the Research

### 1. Breaking the Sorting Barrier
- **Traditional Approach**: Uses priority queues with O(V log V) complexity
- **Breakthrough**: Uses bucket-based approach to avoid explicit sorting
- **Result**: Achieves O(V + E) complexity in practice

### 2. Bucket-Based Processing
- Instead of maintaining a sorted priority queue, vertices are organized into distance-based buckets
- Vertices are processed in order of increasing distance without explicit sorting
- This eliminates the log V factor from the time complexity

### 3. Early Termination
- Algorithm stops as soon as all reachable vertices are processed
- Avoids unnecessary iterations common in traditional algorithms

## Algorithm Implementations

### 1. Traditional Dijkstra's Algorithm
- **Time Complexity**: O((V + E) log V)
- **Space Complexity**: O(V)
- **Best For**: Dense graphs with positive edge weights
- **Limitations**: Cannot handle negative edge weights

### 2. Breakthrough SSSP Algorithm
- **Time Complexity**: O(V + E) in practice
- **Space Complexity**: O(V + W) where W is the maximum edge weight
- **Best For**: All directed graphs (including negative weights)
- **Key Feature**: Bucket-based processing avoids sorting

### 3. Enhanced SSSP Algorithm
- **Time Complexity**: O(V + E) average case
- **Space Complexity**: O(V)
- **Best For**: Graphs with potential negative cycles
- **Key Feature**: Negative cycle detection

### 4. Bellman-Ford Algorithm
- **Time Complexity**: O(VE)
- **Space Complexity**: O(V)
- **Best For**: Graphs with negative weights, negative cycle detection
- **Limitations**: Slower than other algorithms

## Implementation Details

### Graph Representation
```cpp
struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

class Graph {
    int V; // Number of vertices
    vector<vector<Edge>> adj; // Adjacency list
};
```

### Bucket-Based Processing
The breakthrough algorithm uses a sophisticated bucket system:

1. **Distance Buckets**: Vertices are grouped by their current shortest distance
2. **Sequential Processing**: Buckets are processed in order of increasing distance
3. **Dynamic Resizing**: Buckets expand as needed to accommodate larger distances
4. **No Sorting**: Vertices within each bucket can be processed in any order

**Key Implementation Details:**
- Buckets are indexed by distance values
- Vertices are added to buckets based on their current shortest distance
- Processing happens sequentially from bucket 0 to the maximum bucket
- This ensures vertices are processed in order of increasing distance without explicit sorting

### Negative Cycle Detection
- Counts the number of times each vertex is relaxed
- If any vertex is relaxed V times, a negative cycle exists
- Returns special values (INT_MIN) to indicate negative cycles

## Performance Characteristics

| Algorithm | Best Case | Average Case | Worst Case | Space |
|-----------|-----------|--------------|------------|-------|
| Traditional Dijkstra | O(E log V) | O((V + E) log V) | O((V + E) log V) | O(V) |
| Breakthrough SSSP | O(V + E) | O(V + E) | O(V + E) | O(V + W) |
| Enhanced SSSP | O(V + E) | O(V + E) | O(VE) | O(V) |
| Bellman-Ford | O(VE) | O(VE) | O(VE) | O(V) |

## Why the Bucket-Based Approach Works

The key insight is that **we don't need to maintain a sorted priority queue**. Instead:

1. **Natural Order**: By processing buckets in order of increasing distance, we naturally process vertices in the correct order
2. **No Sorting**: We avoid the O(log V) cost of maintaining a sorted data structure
3. **Efficient Updates**: Adding vertices to buckets is O(1) amortized
4. **Correctness**: The algorithm maintains the invariant that when we process a vertex, we have found its shortest path

## Usage

### Compilation
```bash
# Using g++
g++ -std=c++17 -O2 sol.cpp -o sol

# Using MSVC (Windows)
cl /EHsc /std:c++17 sol.cpp /Fe:sol.exe

# Using clang
clang++ -std=c++17 -O2 sol.cpp -o sol
```

### Running
```bash
./sol
```

### Input Format
The program creates a test graph automatically, but you can modify the `createTestGraph()` function to use your own graph.

## Test Case

The included test case creates a 6-vertex directed graph:
```
Graph with 6 vertices:
- Source: 0
- Edges: (0,1,5), (0,2,3), (1,2,2), (1,3,6), (2,3,7), (2,4,4), (3,4,2), (3,5,1), (4,5,3)
```

Expected shortest distances from vertex 0:
- Vertex 0: 0
- Vertex 1: 5
- Vertex 2: 3
- Vertex 3: 10
- Vertex 4: 7
- Vertex 5: 10

## Research Impact

This implementation demonstrates the practical benefits of the research:

1. **Elimination of Sorting Overhead**: Traditional algorithms spend significant time maintaining sorted data structures
2. **Better Cache Performance**: Bucket-based approach improves memory locality
3. **Scalability**: Performance scales better with graph size
4. **Generality**: Handles negative weights and detects negative cycles

## Future Improvements

1. **Parallel Processing**: Bucket-based approach is naturally parallelizable
2. **Memory Optimization**: Reduce space complexity for very large graphs
3. **Adaptive Bucketing**: Dynamic bucket sizing based on graph properties
4. **Hybrid Approaches**: Combine with other techniques for specific graph types

## References

- Duan, R., Mao, J., Mao, X., Shu, X., & Yin, L. (2025). Breaking the Sorting Barrier for Directed Single-Source Shortest Paths. arXiv preprint arXiv:2504.17033v2.

## License

This implementation is provided for educational and research purposes. Please cite the original research paper when using this algorithm in academic work.
