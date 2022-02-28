#include <stdio.h>
#include <stdlib.h>
#include "MyGraph.h"
#include "MyQueue.h"

#define true 1
#define false 0
#define BIG_NUM 99999999



extern int shortestPathWeight;


/**
 * this method receives a pointer to the head of the graph and the starting node.
 * The method create(using dynamically allocation) a struct of Queue that is similar to the struct graph
 * but with an addition of visited, shortestDist parameters, at the initQueue each Node of the
 * queue starts with the value of 0 in the visited parameter, and value of BIG_NUM(9999999). only the @src
 * initiated with 0 in his shortestDist parameter.
 * @param head pointer to the head of the queue
 * @param src
 * @return a pointer to the head of the queue
 */
ptrQueue initQueue(ptrNode head, int src){
    ptrQueue queue;
    queue = (ptrQueue) malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory didn't allocated!\n");
        exit(0);
    }
    queue->visited = 0;
    queue->shortestDist =0;
    queue->Vertex = getNode(head, src);
    ptrNode curr;
    ptrQueue last = NULL;
    int firstTime = false;
    curr = head;
    while(curr) {
        if (curr->node_num != src) {
            ptrQueue q = (ptrQueue) malloc(sizeof(Queue));
            if (!q) {
                free(queue);
                printf("Memory didn't allocated!\n");
                exit(0);
            }
            q->visited = 0;
            q->shortestDist = BIG_NUM;
            q->Vertex = curr;
            q->next = NULL;
            if (!firstTime) {
                queue->next = q;
                last = q;
                firstTime = true;
            } else {
                last->next = q;
                last = q;
            }
        }
        curr = curr->next;
    }
    return queue;
}


/**
 * this method receives a pointer to the head of the queue
 * returns the size of the queue.
 * @param head pointer to the head of the queue
 * @return the size
 */
int Qsize(ptrQueue head){
    ptrQueue curr = head;
    int size = 0;
    while(curr){
        size++;
        curr = curr->next;
    }
    return size;
}


/**
 * this method sorts the given queue using the bubbleSort algorithm.
 * running time O(n^2)
 * @param head pointer to the head of the queue
 */
void bubbleSort(ptrQueue *head){
    ptrQueue curr = *head, q1, q2;
    int size = Qsize((ptrQueue) head);
    for(int i = 1; i < size - 1; i++){
        ptrQueue prev = curr;
        for(int j = 1; j < size - i - 1 ; j++){
            q1 = getQNodeByInd(curr, j);
            q2 = q1->next;
            if(q1->shortestDist > q2->shortestDist){
                ptrQueue q2_next = q2->next;
                ptrQueue temp;
                temp = q1;
                q1 = q2;
                q2 = temp;
                q1->next = q2;
                q2->next = q2_next;
                prev->next = q1;
            }
            prev = q1;
        }
    }
}


/**
 * this method returns the first element of the queue and then removes
 * it from the queue.
 * @param head pointer to the head of the queue
 * @return the Node that was removed.
 */
ptrQueue deQueue(ptrQueue *head){
    ptrQueue last, newHead;
    newHead = (*head)->next;
    last = *head;
    *head = newHead;
    return last;
}


/**
 * this method returns the first Node in the queue that it's visited value is 0.
 * @param head pointer to the head of the queue
 * @return  the first Node that owns 0 in his visited paramter.
 */
ptrQueue getFirstUnvisited(ptrQueue head){
    ptrQueue  curr;
    curr = head;
    while(curr->visited != 0){
        curr = curr->next;
    }
    return curr;
}


/**
 * this method returns a Node from the queue according to his matching Node in the graph.
 * @param head pointer to the head of the queue
 * @param id of the Node in the graph.
 * @return Node from the queue who has the same id as given.
 */
ptrQueue getQNode(ptrQueue head, int id){
    ptrQueue curr = head;
    while(curr){
        if(curr->Vertex->node_num == id) {
            break;
        }
        curr = curr->next;
    }
    return curr;
}


/**
 * this method returns a Node from the queue according to his position in the queue.
 * @param head pointer to the head of the queue
 * @param ind of the Node the user asked for
 * @return Node from the queue located at the @ind's position.
 */
ptrQueue getQNodeByInd(ptrQueue head, int ind){
    ptrQueue curr;
    curr = head->next;
    int i = 1;
    while(i != ind){
        i++;
        curr = curr->next;
    }
    return curr;
}


/**
 * this method calculates the shortestPath (according to the weight of each Edge),
 * between @head Node and the @dest Node in the graph.
 * The method calculates the shortestPath according to Dijkstra's Algorithm.
 * @param head pointer to the head of the queue
 * @param dest the ind of the dest Node in the graph.
 * @return the number(int) of the cost(weight) to get from @head to @dest.
 */
int shortestPath(ptrQueue head, int dest){
    ptrQueue queue;
    int size = Qsize(head);
    queue = head;
    int visited = 0;
    while(visited < size){
        ptrQueue current = getFirstUnvisited(queue);
        current->visited = 1;
        visited++;
        ptrEdge edges = current->Vertex->edges;
        while(edges) {
            ptrQueue adj = getQNode(head, edges->endpoint->node_num);
            if (adj->visited == 0) {
                int new_dist = edges->weight + current->shortestDist;
                int old_dist = adj->shortestDist;
                if (new_dist < old_dist) {
                    adj->shortestDist = new_dist;
                }
            }
            edges = edges->next;
        }
        bubbleSort(&queue);
    }
    int minDist = getQNode(head, dest)->shortestDist;
    return minDist;
}


/**
 * this method swaps between to numbers in an array using pointers.
 * @param x
 * @param y
 */
void swap (int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


/**
 * this method's purpose is to calculate the shortestPath between multiple
 * Nodes(greedy Algorithms for the TSP problem).
 * there are 3 steps to this method:
 *      1) calculate permutation of the Nodes using Heap's Algorithm (@cities_to_visit).
 *      2) call method calculateTSP()
 *      3) calculateTSP() method goes over pairs in the @cities_to_visit array and
 *      activates shortestPath() method on each pair until it finishes to go through all.
 *      4) then the global variable @shortestPathWeight will be updated with the shortestPathDist
 *      to go through all those Nodes.
 *
 * @param head pointer to the head of the queue
 * @param cities_to_visit Nodes that needs to check the min path between them.
 * @param size size of the @cities_to_visit array(change every recursive call)
 * @param original_size size of the @cities_to_visit (doesn't change).
 */
void heapPermuteTSP(ptrNode head, int cities_to_visit[], int size, int original_size) {
    int i;
    if (size == 1) {
        calculateTSP(head, cities_to_visit, original_size);
    }
    else {
        for (i = 0; i < size; i++) {
            heapPermuteTSP(head ,cities_to_visit, size-1, original_size);
            if (size % 2 == 1) {
                swap(&cities_to_visit[0], &cities_to_visit[size-1]);
            }
            else {
                swap(&cities_to_visit[i], &cities_to_visit[size-1]);
            }
        }
    }
}


/**
 * this method frees the memory allocated to the queue.
 * @param head pointer to the head of the queue
 */
void freeQueue(ptrQueue *head){
    if (head == NULL) {
        return;
    }
    ptrQueue curr_q;
    curr_q = *head;
    while (curr_q) {
        ptrQueue next_q = curr_q->next;
        free(curr_q);
        curr_q = next_q;
    }
}


/**
 * this method sum the shortest path it will cost to go over all the Node in the array.
 * @param head pointer to the head of the queue
 * @param arr of nodes to visit
 * @param size of the array
 */
void calculateTSP(ptrNode head, int *arr, int size){
    int i = 0, j = 1, currentMinDist = 0, currDist, src, dest;
    while(j < size){
        src = *(arr + i);
        dest = *(arr + j);
        ptrQueue queue = initQueue(head, src);
        currDist = shortestPath(queue, dest);
        if(currDist == BIG_NUM){
            currentMinDist = BIG_NUM;
            freeQueue(&queue);
            break;
        }
        currentMinDist += currDist;
        freeQueue(&queue);
        i++;
        j++;
    }
    if(currentMinDist < shortestPathWeight){
        shortestPathWeight = currentMinDist;
    }
}