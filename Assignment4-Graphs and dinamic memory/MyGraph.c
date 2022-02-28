#include <stdio.h>
#include <stdlib.h>
#include "MyGraph.h"

#define true 1
#define false 0
#define BIG_NUM 99999999

 extern int graphSize;
extern ptrNode lastNode; // pointer to the last node added to the graph


/**
 * this method receives a pointer from a type of struct GRAPH @head
 * and an int number with the amount of nodes @size.
 * the method creates @size Nodes and connects them to each other with a pointer(linkedList).
 * each node will have id starting from 0->(@size-1).
 * it uses the heaps memory using the alloc method.
 * @param head pointer to the head of the linkedList
 * @param size  amount of nodes to add
 */
void initGraph(ptrNode *head, int size){
    int amount_of_nodes = size;
    // initiating the Graph nodes.
    ptrNode last = NULL;
    ptrNode node;
    for (int i = 0; i < amount_of_nodes; ++i) {
        node = (ptrNode) malloc(sizeof(Node));
        if (node == NULL) {
            printf("Memory didn't allocated!\n");
            exit(0);
        }
        node->node_num = i;
        node->next = NULL;
        node->edges_s = 0;
        node->edges = NULL;
        if (i == 0) {
            *head = node;
            last = *head;
        } else if (i > 0) { // last is not NULL
            last->next = node;
            last = node;
        }
    }
    lastNode = last;
    graphSize = amount_of_nodes;
}


/**
 * this method connects between @source Node with the @dest Node with an edge.
 * the connection will be saved only in the @source Node, in the field *edges.
 * @param head pointer to the head of the graph
 * @param source the id number of the source node
 * @param dest the id number of the dest node
 * @param weight the weight of the new edge
 */
void addEdge(ptrNode *head, int source, int dest, int weight) {
    ptrNode curr_n, temp;
    ptrNode end = NULL;

    curr_n = (*head);
    while (curr_n != NULL && curr_n->node_num != source) {
        if (curr_n->node_num == dest) {
            end = curr_n;
        }
        curr_n = curr_n->next;
    }

    temp = (*head);
    while (end == NULL) {
        if (temp->node_num == dest) {
            end = temp;
        }
        temp = temp->next;
    }
    if (curr_n->edges_s == 0) {
        ptrEdge e;
        e = (ptrEdge) malloc(sizeof(Edge));
        if (e == NULL) {
            printf("Memory didn't allocated!\n");
            exit(0);
        }
        e->endpoint = end;
        e->weight = weight;
        e->next = NULL;
        curr_n->edges_s++;
        curr_n->edges = e;
    } else {
        ptrEdge curr_e = curr_n->edges;
        while (curr_e != NULL && curr_e->next != NULL) {
            curr_e = curr_e->next;
        }
        ptrEdge newEdge;
        newEdge = (ptrEdge) malloc(sizeof(Edge));
        if (newEdge == NULL) {
            printf("Memory didn't allocated!\n");
            exit(0);
        }
        newEdge->endpoint = end;
        newEdge->weight = weight;
        newEdge->next = NULL;
        curr_e->next = newEdge;
        curr_n->edges_s++;
    }
}


/**
 * this method prints the graph.
 * @param head pointer to the head of the graph
 */
void printGraph_cmd(ptrNode head) {
    ptrNode temp;
    temp = head;
    while (temp != NULL) {
        int id = temp->node_num;
        printf("(ID: %d, [", id);
        ptrEdge e = temp->edges;
        while (e != NULL) {
            int dest = e->endpoint->node_num;
            int weight = e->weight;
            printf("E(%d->%d,%d) ", id, dest, weight);
            e = e->next;
        }
        int next_id = -1;
        if(temp->next != NULL) {
            next_id = temp->next->node_num;
        }
        printf("], next -> %d)\n", next_id);
        temp = temp->next;
    }
}


/**
 * this method checks the node with the id @id is contained in the graph.
 * @param head pointer to the head of the graph
 * @param id index of a node in the graph
 * @return if true returns 1, otherwise false = 0
 */
int contains(ptrNode head, int id){
    ptrNode curr_n = head;
    while(curr_n != NULL){
        if(curr_n->node_num == id){
            return true;
        }
        curr_n = curr_n->next;
    }
    return false;
}


/**
 * this method frees the entire graph memory that was allocated.
 * @param head pointer to the head of the graph
 */
void freeGraph(ptrNode *head) {
    if (head == NULL) {
        return;
    }
    ptrNode curr_n;
    curr_n = *head;
    while (curr_n) {
        ptrNode next_node = curr_n->next;
        freeEdges(&curr_n);
        free(curr_n);
        curr_n = next_node;
    }
}


/**
 * this method goes over all the edges linkedList of a single node @node
 * and frees their memory.
 * @param node pointer to the node in the graph
 */
void freeEdges(ptrNode *node) {
    if (node == NULL) {
        return;
    }
    ptrEdge curr_e = (*node)->edges;
    while (curr_e) {
        ptrEdge next_edge = curr_e->next;
        free(curr_e);
        curr_e = next_edge;
    }
}


/**
 * this method receives an @id of a new node and creates it as the last node in the linkedList
 * then it sets the @lastNode to be the new node added.
 * @param head pointer to the head of the graph
 * @param id number of the new node's id.
 */
void addNode(ptrNode *head, int id){
    ptrNode newNode;
    newNode = (ptrNode) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory didn't allocated!\n");
        exit(0);
    }
    newNode->node_num = id;
    newNode->next = NULL;
    newNode->edges = NULL;
    newNode->edges_s = 0;
    lastNode->next = newNode;
    lastNode = newNode;
    graphSize++;
}


/**
 * this method loops the linkedList of the graph and returns node
 * with the matching id number as @id.
 * @param head pointer to the head of the graph
 * @param id id number of the desired node.
 * @return the struct node with id equals to @id
 */
ptrNode getNode(ptrNode head, int id){
    ptrNode curr_n;
    curr_n = head;
    while(curr_n->node_num != id){
        curr_n = curr_n->next;
    }
    return curr_n;
}


/**
 * this method removes the edge between the @node given to the node with id = @dest.
 * @param node pointer to the node which this method will work on.
 * @param dest the id of the node that is connected to the @node with an edge.
 */
void removeEdge(ptrNode *node, int dest){
    ptrEdge edges = (*node)->edges;
    ptrEdge last = (*node)->edges;
    if((*node)->edges->endpoint->node_num == dest){
        (*node)->edges = edges->next;
        free(edges);
        (*node)->edges_s--;
        return;
    }
    while(edges != NULL){
        if(edges->endpoint->node_num == dest){
            last->next = edges->next;
            free(edges);
            (*node)->edges_s--;
            break;
        }
        last = edges;
        edges = edges->next;
    }
}


/**
 * this method removes all the edges that are connected to @id node
 * edges the @id is their dest(endpoint).
 * @param head pointer to the head of the graph
 * @param id of the node that needs to be disconnected (edges)
 */
void remove_in_edges(ptrNode *head, int id){
    ptrNode curr = *head;
    while(curr != NULL){
        ptrEdge edges = curr->edges;
        while(edges != NULL){
            if(edges->endpoint->node_num == id){
                removeEdge(&curr, id);
                break;
            }
            edges = edges->next;
        }
        curr = curr->next;
    }
}


/**
 * this method removes a node with id number matching to @id
 * in the graph.
 * @param head pointer to the head of the graph
 * @param id number of the node that needs to be removed.
 */
void removeNode(ptrNode *head, int id){
    ptrNode curr = *head;
    ptrNode last;
    if(curr->node_num == id){
        (*head) = curr->next;
    }
    else {
        while (curr->node_num != id) {
            last = curr;
            curr = curr->next;
        }
        last->next = curr->next;
    }
    freeEdges(&curr);
    remove_in_edges(head, id);
    free(curr);
    graphSize++;
}