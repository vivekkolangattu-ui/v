#include <stdio.h> 
#define MAX 100 
 
int queue[MAX], front = -1, rear = -1; 
int visited[MAX]; 
int adj[MAX][MAX]; 
int n; 
 
void enqueue(int v) { 
    if (rear == MAX - 1) 
        return; 
    if (front == -1) 
        front = 0; 
    rear++; 
    queue[rear] = v; 
} 
 
int dequeue() { 
    if (front == -1 || front > rear) 
        return -1; 
    int v = queue[front]; 
    front++; 
    return v; 
} 
 
void BFS(int start) { 
    int i, v; 
 
    for (i = 0; i < n; i++) 
        visited[i] = 0; 
 
    enqueue(start); 
    visited[start] = 1; 
 
    printf("BFS Traversal: "); 
 
    while (front <= rear) { 
        v = dequeue(); 
        printf("%d ", v); 
 
        for (i = 0; i < n; i++) { 
            if (adj[v][i] == 1 && visited[i] == 0) { 
                enqueue(i); 
                visited[i] = 1; 
            } 
        } 
    } 
    printf("\n"); 
} 
 
int main() { 
    int i, j, start; 
 
    printf("Enter number of vertices: "); 
    scanf("%d", &n); 
 
    printf("Enter adjacency matrix:\n"); 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n; j++) { 
            scanf("%d", &adj[i][j]); 
        } 
    } 
 
    printf("Enter starting vertex (0 to %d): ", n - 1); 
    scanf("%d", &start); 
 
    BFS(start); 
 
    return 0; 
}