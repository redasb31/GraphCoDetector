#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_MAPS 50
#define MAX_VERTICES 20
#define MAX_EDGES MAX_VERTICES * (MAX_VERTICES - 1) / 2
#define MAX_WARP_GATES MAX_VERTICES

// Structure to represent a vertex
typedef struct Vertex {
    int x;
    int y;
    int warp_gate_map; // Map index where the warp gate is located (0 if no warp gate)
    int warp_gate_vertex; // Vertex index in the warp gate destination map (0 if no warp gate)
} Vertex;

// Structure to represent an edge
typedef struct Edge {
    int start;
    int end;
} Edge;

// Structure to represent a map
typedef struct Map {
    Vertex vertices[MAX_VERTICES];
    Edge edges[MAX_EDGES];
    int num_vertices;
    int num_edges;
    int num_warp_gates;
} Map;

// Function to calculate the Euclidean distance between two vertices
double distance(Vertex v1, Vertex v2) {
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}

// Function to check if two maps are identical after rotation and translation
bool is_identical(Map map1, Map map2) {
    // Check if the number of vertices is the same
    if (map1.num_vertices != map2.num_vertices) {
        return false;
    }

    // Check if the distances between corresponding vertices are the same
    for (int i = 0; i < map1.num_vertices; i++) {
        for (int j = i + 1; j < map1.num_vertices; j++) {
            double dist1 = distance(map1.vertices[i], map1.vertices[j]);
            double dist2 = distance(map2.vertices[i], map2.vertices[j]);
            if (fabs(dist1 - dist2) > 1e-6) {
                return false;
            }
        }
    }

    return true;
}

// Function to unify maps (removes duplicates and updates warp gate information)
void unify_maps(Map maps[MAX_MAPS], int num_maps) {
    for (int i = 0; i < num_maps; i++) {
        // Check if the map has already been unified
        if (maps[i].num_vertices == 0) {
            continue;
        }

        // Check for identical maps
        for (int j = i + 1; j < num_maps; j++) {
            if (is_identical(maps[i], maps[j])) {
                // Update warp gate information for the unified map
                for (int k = 0; k < maps[j].num_warp_gates; k++) {
                    int warp_gate_vertex = maps[j].vertices[maps[j].edges[k].start].warp_gate_vertex;
                    if (warp_gate_vertex != 0) {
                        // Find the corresponding vertex in the unified map
                        for (int l = 0; l < maps[i].num_vertices; l++) {
                            if (distance(maps[i].vertices[l], maps[j].vertices[maps[j].edges[k].start]) < 1e-6) {
                                maps[i].vertices[l].warp_gate_map = maps[j].edges[k].end;
                                maps[i].vertices[l].warp_gate_vertex = warp_gate_vertex;
                                break;
                            }
                        }
                    }
                }
                // Reset the duplicate map
                maps[j].num_vertices = 0;
                maps[j].num_edges = 0;
                maps[j].num_warp_gates = 0;
            }
        }
    }
}

// Function to find the shortest path using Dijkstra's algorithm
double shortest_path(Map maps[MAX_MAPS], int start_map, int start_vertex, int end_map, int end_vertex) {
    // Initialize distances to infinity
    double distances[MAX_MAPS][MAX_VERTICES];
    for (int i = 0; i < MAX_MAPS; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            distances[i][j] = INFINITY;
        }
    }

    // Initialize distance from the starting vertex to 0
    distances[start_map][start_vertex] = 0;

    // Create a priority queue to store vertices and their distances
    int queue[MAX_MAPS * MAX_VERTICES][2];
    int queue_size = 0;
    queue[queue_size][0] = start_map;
    queue[queue_size][1] = start_vertex;
    queue_size++;

    // Iterate until the queue is empty
    while (queue_size > 0) {
        // Find the vertex with the shortest distance
        int min_index = 0;
        for (int i = 1; i < queue_size; i++) {
            if (distances[queue[i][0]][queue[i][1]] < distances[queue[min_index][0]][queue[min_index][1]]) {
                min_index = i;
            }
        }

        // Extract the vertex from the queue
        int current_map = queue[min_index][0];
        int current_vertex = queue[min_index][1];
        queue[min_index][0] = queue[queue_size - 1][0];
        queue[min_index][1] = queue[queue_size - 1][1];
        queue_size--;

        // Check if we have reached the destination
        if (current_map == end_map && current_vertex == end_vertex) {
            return distances[current_map][current_vertex];
        }

        // Relax the edges for the current vertex
        for (int i = 0; i < maps[current_map].num_edges; i++) {
            int neighbor_vertex = maps[current_map].edges[i].end;
            if (maps[current_map].edges[i].start == current_vertex) {
                double new_distance = distances[current_map][current_vertex] + distance(maps[current_map].vertices[current_vertex], maps[current_map].vertices[neighbor_vertex]);
                if (new_distance < distances[current_map][neighbor_vertex]) {
                    distances[current_map][neighbor_vertex] = new_distance;

                    // Add the neighbor vertex to the queue
                    queue[queue_size][0] = current_map;
                    queue[queue_size][1] = neighbor_vertex;
                    queue_size++;
                }
            }
        }

        // Relax the warp gate for the current vertex
        if (maps[current_map].vertices[current_vertex].warp_gate_map != 0) {
            int warp_gate_map = maps[current_map].vertices[current_vertex].warp_gate_map;
            int warp_gate_vertex = maps[current_map].vertices[current_vertex].warp_gate_vertex;
            double new_distance = distances[current_map][current_vertex];
            if (new_distance < distances[warp_gate_map][warp_gate_vertex]) {
                distances[warp_gate_map][warp_gate_vertex] = new_distance;

                // Add the warp gate destination vertex to the queue
                queue[queue_size][0] = warp_gate_map;
                queue[queue_size][1] = warp_gate_vertex;
                queue_size++;
            }
        }
    }

    // If no path is found, return -1
    return -1;
}

int main() {
    // Read the number of maps
    int num_maps;
    while (scanf("%d", &num_maps) != EOF) {
        // Read the maps
        Map maps[MAX_MAPS];
        for (int i = 0; i < num_maps; i++) {
            maps[i].num_vertices = 0;
            maps[i].num_edges = 0;
            maps[i].num_warp_gates = 0;

            // Read the number of vertices
            int num_vertices;
            scanf("%d", &num_vertices);

            // Read the vertices
            for (int j = 0; j < num_vertices; j++) {
                scanf("%d %d", &maps[i].vertices[j].x, &maps[i].vertices[j].y);
                maps[i].vertices[j].warp_gate_map = 0;
                maps[i].vertices[j].warp_gate_vertex = 0;
                maps[i].num_vertices++;
            }

            // Read the number of edges
            int num_edges;
            scanf("%d", &num_edges);

            // Read the edges
            for (int j = 0; j < num_edges; j++) {
                scanf("%d %d", &maps[i].edges[j].start, &maps[i].edges[j].end);
                maps[i].num_edges++;
            }

            // Read the number of warp gates
            int num_warp_gates;
            scanf("%d", &num_warp_gates);

            // Read the warp gates
            for (int j = 0; j < num_warp_gates; j++) {
                int warp_gate_vertex, warp_gate_map, warp_gate_dest_vertex;
                scanf("%d %d %d", &warp_gate_vertex, &warp_gate_map, &warp_gate_dest_vertex);
                maps[i].vertices[warp_gate_vertex - 1].warp_gate_map = warp_gate_map;
                maps[i].vertices[warp_gate_vertex - 1].warp_gate_vertex = warp_gate_dest_vertex;
                maps[i].num_warp_gates++;
            }
        }

        // Read the entrance and exit locations
        int start_map, start_vertex, end_map, end_vertex;
        scanf("%d %d", &start_map, &start_vertex);
        scanf("%d %d", &end_map, &end_vertex);

        // Unify the maps
        unify_maps(maps, num_maps);

        // Find the shortest path
        double shortest_distance = shortest_path(maps, start_map - 1, start_vertex - 1, end_map - 1, end_vertex - 1);

        // Print the shortest distance
        printf("%.10lf\n", shortest_distance);
    }

    return 0;
}