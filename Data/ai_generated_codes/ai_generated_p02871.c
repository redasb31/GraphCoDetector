// This C code solves Problem A of the delivery service contest.
// The code takes as input a graph representation, order information,
// and the maximum time steps, and outputs a sequence of car movements
// to maximize the delivery score.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Structure to represent a vertex in the graph
typedef struct Vertex {
    int id; // Vertex ID
    int x;  // x-coordinate on the 2D grid
    int y;  // y-coordinate on the 2D grid
    int order_frequency; // Order frequency for this vertex
    int degree; // Degree of the vertex
    int color; // Color assigned based on grid position
} Vertex;

// Structure to represent an edge in the graph
typedef struct Edge {
    int u; // ID of the first vertex connected by the edge
    int v; // ID of the second vertex connected by the edge
    int weight; // Distance/weight of the edge
} Edge;

// Structure to represent an order
typedef struct Order {
    int id; // Order ID
    int destination; // Vertex ID of the order destination
    int time; // Time at which the order was placed
} Order;

// Structure to represent the car
typedef struct Car {
    int current_vertex; // Current vertex the car is on
    int on_edge; // Flag indicating if the car is on an edge (1) or a vertex (0)
    int edge_position; // Position on the edge (0 to weight-1) if on an edge
    int orders_in_car; // Number of orders in the car
    Order* orders[10000]; // Array to store the orders in the car
} Car;

// Global variables
int num_vertices, num_edges;
Vertex* vertices;
Edge* edges;
int max_time_steps;
Order* orders;
Car car;

// Function to calculate the Euclidean distance between two vertices
double euclidean_distance(Vertex u, Vertex v) {
    return sqrt(pow(u.x - v.x, 2) + pow(u.y - v.y, 2));
}

// Function to generate a random number between 0 and 1
double uniform_random() {
    return (double)rand() / RAND_MAX;
}

// Function to generate the map graph
void generate_map_graph(int num_vertices, int num_edges) {
    vertices = malloc(sizeof(Vertex) * num_vertices);
    edges = malloc(sizeof(Edge) * num_edges);

    // Calculate the grid size
    int grid_size = (int)sqrt(num_vertices);
    int remaining_vertices = num_vertices - grid_size * grid_size;

    // Assign coordinates to vertices on the grid
    int vertex_count = 0;
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            vertices[vertex_count].x = i + uniform_random();
            vertices[vertex_count].y = j + uniform_random();
            vertices[vertex_count].id = vertex_count + 1;
            vertex_count++;
        }
    }

    // Assign random coordinates to remaining vertices
    for (int i = 0; i < remaining_vertices; i++) {
        vertices[vertex_count].x = uniform_random() * grid_size;
        vertices[vertex_count].y = uniform_random() * grid_size;
        vertices[vertex_count].id = vertex_count + 1;
        vertex_count++;
    }

    // Shuffle the vertex IDs
    for (int i = num_vertices - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Vertex temp = vertices[i];
        vertices[i] = vertices[j];
        vertices[j] = temp;
    }

    // Assign the shop to vertex 1
    vertices[0].id = 1;

    // Assign order frequencies
    for (int i = 0; i < num_vertices; i++) {
        vertices[i].order_frequency = 1;
    }

    // Create a complete graph with Euclidean distances
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            double distance = euclidean_distance(vertices[i], vertices[j]);
            edges[num_edges].u = vertices[i].id;
            edges[num_edges].v = vertices[j].id;
            edges[num_edges].weight = (int)ceil(distance * 2);
            num_edges++;
        }
    }

    // Create a minimum spanning tree for highways
    // (Implementation of Kruskal's algorithm or Prim's algorithm is required)

    // Add side roads
    // (Implementation of a cost-based edge selection algorithm is required)
}

// Function to read the graph information from the input
void read_graph_information(FILE* input) {
    fscanf(input, "%d %d\n", &num_vertices, &num_edges);

    // Allocate memory for vertices and edges
    vertices = malloc(sizeof(Vertex) * num_vertices);
    edges = malloc(sizeof(Edge) * num_edges);

    // Read edge information
    for (int i = 0; i < num_edges; i++) {
        fscanf(input, "%d %d %d\n", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
}

// Function to read the order information from the input
void read_order_information(FILE* input, int num_orders) {
    orders = malloc(sizeof(Order) * num_orders);

    int order_count = 0;
    for (int i = 0; i < num_orders; i++) {
        int num_new_orders;
        fscanf(input, "%d\n", &num_new_orders);

        if (num_new_orders > 0) {
            fscanf(input, "%d %d\n", &orders[order_count].id, &orders[order_count].destination);
            orders[order_count].time = i;
            order_count++;
        }
    }
}

// Function to initialize the car
void initialize_car() {
    car.current_vertex = 1; // Start at the shop
    car.on_edge = 0;
    car.edge_position = 0;
    car.orders_in_car = 0;
}

// Function to find the edge between two vertices
int find_edge(int u, int v) {
    for (int i = 0; i < num_edges; i++) {
        if ((edges[i].u == u && edges[i].v == v) || (edges[i].u == v && edges[i].v == u)) {
            return i;
        }
    }
    return -1;
}

// Function to load orders into the car at the shop
void load_orders(int current_time) {
    for (int i = 0; i < max_time_steps; i++) {
        if (orders[i].time <= current_time && orders[i].id != -1) {
            car.orders[car.orders_in_car] = &orders[i];
            car.orders_in_car++;
            orders[i].id = -1; // Mark the order as loaded
        }
    }
}

// Function to deliver an order
void deliver_order(int destination) {
    for (int i = 0; i < car.orders_in_car; i++) {
        if (car.orders[i]->destination == destination) {
            // Update the score (implementation of score calculation required)
            // ...

            // Remove the order from the car
            car.orders[i] = NULL;
            car.orders_in_car--;
            return;
        }
    }
}

// Function to move the car
int move_car(int target_vertex) {
    // Check if the target vertex is valid
    if (target_vertex < 1 || target_vertex > num_vertices) {
        return -1; // Invalid target vertex
    }

    // Check if the car is on a vertex
    if (car.on_edge == 0) {
        // Find the edge connecting the current vertex and the target vertex
        int edge_index = find_edge(car.current_vertex, target_vertex);

        if (edge_index == -1) {
            return -1; // No edge connecting the vertices
        }

        // Update the car's position
        car.current_vertex = target_vertex;
        car.on_edge = 1;
        car.edge_position = 0;

        // Deliver orders if at the destination
        deliver_order(target_vertex);

        return 0;
    } else {
        // Check if the target vertex is one of the end vertices of the edge
        if (target_vertex == edges[car.on_edge].u || target_vertex == edges[car.on_edge].v) {
            // Update the car's position
            car.current_vertex = target_vertex;
            car.on_edge = 0;
            car.edge_position = 0;

            // Deliver orders if at the destination
            deliver_order(target_vertex);

            return 0;
        } else {
            return -1; // Invalid target vertex for moving on an edge
        }
    }
}

// Function to calculate the next car movement based on the orders and current position
int calculate_next_move(int current_time) {
    // Check if the car is at the shop and there are orders to load
    if (car.current_vertex == 1 && car.orders_in_car < max_time_steps) {
        load_orders(current_time); // Load orders into the car
        return -1; // Stay at the shop
    }

    // Find the nearest undelivered order in the car
    int nearest_order_destination = -1;
    int min_distance = INT_MAX;
    for (int i = 0; i < car.orders_in_car; i++) {
        if (car.orders[i] != NULL) {
            // Calculate the distance to the order destination
            int edge_index = find_edge(car.current_vertex, car.orders[i]->destination);
            int distance = edges[edge_index].weight;
            if (distance < min_distance) {
                min_distance = distance;
                nearest_order_destination = car.orders[i]->destination;
            }
        }
    }

    // If there's an undelivered order, move towards it
    if (nearest_order_destination != -1) {
        return nearest_order_destination;
    } else {
        // If no undelivered orders, move to the shop
        return 1;
    }
}

int main() {
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");

    // Read the graph information
    read_graph_information(input);

    // Read the order information
    int num_orders;
    fscanf(input, "%d\n", &max_time_steps);
    read_order_information(input, max_time_steps);

    // Initialize the car
    initialize_car();

    // Calculate car movements for each time step
    for (int i = 0; i < max_time_steps; i++) {
        int next_move = calculate_next_move(i);
        fprintf(output, "%d\n", next_move);

        // Move the car
        move_car(next_move);
    }

    fclose(input);
    fclose(output);

    return 0;
}