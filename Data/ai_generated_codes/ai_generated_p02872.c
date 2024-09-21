#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Structure to represent a vertex
typedef struct Vertex {
    int id;
    int x;
    int y;
    int degree;
    int color;
    int order_frequency;
} Vertex;

// Structure to represent an edge
typedef struct Edge {
    int u;
    int v;
    int weight;
} Edge;

// Structure to represent an order
typedef struct Order {
    int id;
    int destination;
    int time;
} Order;

// Structure to represent the car
typedef struct Car {
    int position;
    int on_edge; // 1 if on an edge, 0 otherwise
    int edge_position; // Distance from the first vertex of the edge
} Car;

// Function to generate a random number between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate the Euclidean distance between two vertices
double euclidean_distance(Vertex *u, Vertex *v) {
    return sqrt(pow(u->x - v->x, 2) + pow(u->y - v->y, 2));
}

// Function to generate the map graph
void generate_graph(int num_vertices, int num_edges, Vertex *vertices, Edge *edges) {
    // Calculate the grid size
    int R = (int)sqrt(num_vertices);
    int r = num_vertices - R * R;

    // Assign random positions to the vertices
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (i < R * R) {
            vertices[i].x = i / R + (double)rand_int(0, 1000) / 1000;
            vertices[i].y = i % R + (double)rand_int(0, 1000) / 1000;
        } else {
            vertices[i].x = rand_int(0, R);
            vertices[i].y = rand_int(0, R);
        }
    }

    // Assign random labels to the vertices
    for (i = 0; i < num_vertices; i++) {
        vertices[i].id = i + 1;
    }

    // Shuffle the vertex labels
    for (i = 0; i < num_vertices - 1; i++) {
        int j = rand_int(i + 1, num_vertices - 1);
        int temp = vertices[i].id;
        vertices[i].id = vertices[j].id;
        vertices[j].id = temp;
    }

    // Set the shop vertex
    vertices[0].id = 1;

    // Generate the highway network
    double **distances = malloc(num_vertices * sizeof(double *));
    for (i = 0; i < num_vertices; i++) {
        distances[i] = malloc(num_vertices * sizeof(double));
    }

    for (i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            distances[i][j] = distances[j][i] = euclidean_distance(&vertices[i], &vertices[j]);
        }
    }

    // Generate the minimum spanning tree using Prim's algorithm
    int *selected = malloc(num_vertices * sizeof(int));
    for (i = 0; i < num_vertices; i++) {
        selected[i] = 0;
    }

    selected[0] = 1;
    int edge_count = 0;
    while (edge_count < num_vertices - 1) {
        double min_distance = INFINITY;
        int u = -1, v = -1;

        for (i = 0; i < num_vertices; i++) {
            if (selected[i]) {
                for (int j = 0; j < num_vertices; j++) {
                    if (!selected[j] && distances[i][j] < min_distance) {
                        min_distance = distances[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        selected[v] = 1;
        edges[edge_count].u = vertices[u].id;
        edges[edge_count].v = vertices[v].id;
        edges[edge_count].weight = (int)ceil(2 * distances[u][v]);
        edge_count++;
    }

    // Free the distances array
    for (i = 0; i < num_vertices; i++) {
        free(distances[i]);
    }
    free(distances);
    free(selected);

    // Add side roads
    for (i = num_vertices - 1; i < num_edges; i++) {
        double min_cost = INFINITY;
        int u = -1, v = -1;

        for (int j = 0; j < num_vertices; j++) {
            for (int k = j + 1; k < num_vertices; k++) {
                if (edges[i].u == 0 && edges[i].v == 0) {
                    // Check if vertices are not already connected
                    int connected = 0;
                    for (int l = 0; l < i; l++) {
                        if ((edges[l].u == vertices[j].id && edges[l].v == vertices[k].id) ||
                            (edges[l].u == vertices[k].id && edges[l].v == vertices[j].id)) {
                            connected = 1;
                            break;
                        }
                    }

                    if (!connected) {
                        double cost = distances[j][k] * vertices[j].degree * vertices[k].degree *
                                      (vertices[j].color == vertices[k].color ? 5 : 1) *
                                      (vertices[j].degree < 5 ? 1 : INFINITY) * (vertices[k].degree < 5 ? 1 : INFINITY);
                        if (cost < min_cost) {
                            min_cost = cost;
                            u = j;
                            v = k;
                        }
                    }
                }
            }
        }

        edges[i].u = vertices[u].id;
        edges[i].v = vertices[v].id;
        edges[i].weight = (int)ceil(4 * distances[u][v]);
        vertices[u].degree++;
        vertices[v].degree++;
    }
}

// Function to generate the order frequencies
void generate_order_frequencies(int num_vertices, Vertex *vertices) {
    // Initialize the order frequencies
    int i;
    for (i = 0; i < num_vertices; i++) {
        vertices[i].order_frequency = 1;
    }

    // Determine the vertices with order frequency 2
    int R = (int)sqrt(num_vertices);
    int center_x = rand_int(R / 4, 3 * R / 4);
    int center_y = rand_int(R / 4, 3 * R / 4);

    for (i = 1; i < num_vertices; i++) {
        if (euclidean_distance(&vertices[i], &vertices[0]) <= R / 8 + (double)rand_int(0, R / 8) / 1000) {
            vertices[i].order_frequency = 2;
        }
    }
}

// Function to generate a new order
Order *generate_order(int time, Vertex *vertices, int num_vertices) {
    // Calculate the order probability
    double T_last = 0.95 * 10000; // T_max = 10000
    double T_peak = (double)rand_int(0, (int)T_last) / 1000;
    double p_order;
    if (time <= T_peak) {
        p_order = (double)time / T_peak;
    } else if (time <= T_last) {
        p_order = (T_last - time) / (T_last - T_peak);
    } else {
        p_order = 0;
    }

    // Generate a random number
    double r = (double)rand_int(0, 1000) / 1000;

    // Check if a new order should be generated
    if (r <= p_order) {
        // Select the order destination with probability proportional to the order frequency
        int total_frequency = 0;
        for (int i = 0; i < num_vertices; i++) {
            total_frequency += vertices[i].order_frequency;
        }

        int random_frequency = rand_int(1, total_frequency);
        int destination = 0;
        int current_frequency = 0;
        while (current_frequency < random_frequency) {
            destination++;
            current_frequency += vertices[destination].order_frequency;
        }

        // Create a new order
        Order *new_order = malloc(sizeof(Order));
        new_order->id = time + 1; // Assuming order ID starts from 1
        new_order->destination = vertices[destination].id;
        new_order->time = time;
        return new_order;
    }

    return NULL;
}

// Function to print the graph information
void print_graph(int num_vertices, int num_edges, Vertex *vertices, Edge *edges) {
    printf("%d %d\n", num_vertices, num_edges);
    for (int i = 0; i < num_edges; i++) {
        printf("%d %d %d\n", edges[i].u, edges[i].v, edges[i].weight);
    }

    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", vertices[i].order_frequency);
    }

    printf("\n10000\n");
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Set the number of vertices and edges
    int num_vertices = 300;
    int num_edges = (int)(1.5 * num_vertices);

    // Allocate memory for the vertices and edges
    Vertex *vertices = malloc(num_vertices * sizeof(Vertex));
    Edge *edges = malloc(num_edges * sizeof(Edge));

    // Generate the map graph
    generate_graph(num_vertices, num_edges, vertices, edges);

    // Generate the order frequencies
    generate_order_frequencies(num_vertices, vertices);

    // Print the graph information
    print_graph(num_vertices, num_edges, vertices, edges);

    // Initialize the car
    Car car;
    car.position = 1; // Start at the shop
    car.on_edge = 0;
    car.edge_position = 0;

    // Initialize the orders
    Order *orders = NULL;
    int num_orders = 0;

    // Initialize the delivered orders
    int *delivered_orders = NULL;
    int num_delivered_orders = 0;

    // Main loop for the simulation
    for (int t = 0; t < 10000; t++) {
        // Generate a new order
        Order *new_order = generate_order(t, vertices, num_vertices);
        if (new_order != NULL) {
            // Add the new order to the list of orders
            num_orders++;
            orders = realloc(orders, num_orders * sizeof(Order));
            orders[num_orders - 1] = *new_order;
            free(new_order);
        }

        // Print the new orders
        printf("%d\n", num_orders - num_delivered_orders);
        for (int i = num_delivered_orders; i < num_orders; i++) {
            printf("%d %d\n", orders[i].id, orders[i].destination);
        }

        // Check if the car is at the shop
        if (car.position == 1 && car.on_edge == 0) {
            // Load orders into the car
            printf("%d\n", num_orders - num_delivered_orders);
            for (int i = num_delivered_orders; i < num_orders; i++) {
                printf("%d\n", orders[i].id);
            }
        } else {
            printf("0\n");
        }

        // Get the car move from the user
        int move;
        scanf("%d", &move);

        // Check if the move is valid
        int valid_move = 0;
        if (move == -1) {
            valid_move = 1;
        } else if (car.on_edge == 0) {
            // Check if there is an edge connecting the current vertex and the move
            for (int i = 0; i < num_edges; i++) {
                if ((edges[i].u == car.position && edges[i].v == move) ||
                    (edges[i].u == move && edges[i].v == car.position)) {
                    valid_move = 1;
                    break;
                }
            }
        } else {
            // Check if the move is one of the end vertices of the edge
            if (move == edges[car.on_edge].u || move == edges[car.on_edge].v) {
                valid_move = 1;
            }
        }

        // Print the verdict
        if (valid_move) {
            printf("OK\n");
        } else {
            printf("NG\n");
            return 0; // Terminate the program if the move is invalid
        }

        // Update the car position
        if (move != -1) {
            if (car.on_edge == 0) {
                // Find the edge connecting the current vertex and the move
                for (int i = 0; i < num_edges; i++) {
                    if ((edges[i].u == car.position && edges[i].v == move) ||
                        (edges[i].u == move && edges[i].v == car.position)) {
                        car.on_edge = i;
                        car.edge_position = 0;
                        break;
                    }
                }
            } else {
                // Move along the edge
                if (move == edges[car.on_edge].u) {
                    car.edge_position++;
                    if (car.edge_position == edges[car.on_edge].weight) {
                        car.on_edge = 0;
                        car.position = move;
                    }
                } else {
                    car.edge_position--;
                    if (car.edge_position == 0) {
                        car.on_edge = 0;
                        car.position = move;
                    }
                }
            }
        }

        // Check if any orders have been delivered
        int delivered_orders_count = 0;
        for (int i = 0; i < num_orders; i++) {
            if (orders[i].time <= t && orders[i].destination == car.position &&
                car.on_edge == 0 && orders[i].id > num_delivered_orders) {
                // Mark the order as delivered
                delivered_orders_count++;
                delivered_orders = realloc(delivered_orders, (num_delivered_orders + 1) * sizeof(int));
                delivered_orders[num_delivered_orders] = orders[i].id;
                num_delivered_orders++;
            }
        }

        // Print the delivered orders
        printf("%d\n", delivered_orders_count);
        for (int i = num_delivered_orders - delivered_orders_count; i < num_delivered_orders; i++) {
            printf("%d\n", delivered_orders[i]);
        }
    }

    // Free the allocated memory
    free(vertices);
    free(edges);
    free(orders);
    free(delivered_orders);

    return 0;
}