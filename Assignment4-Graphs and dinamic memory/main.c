#include <stdio.h>
#include <stdlib.h>
#include "MyGraph.h"
#include "MyQueue.h"

#define true 1
#define false 0
#define BIG_NUM 99999999

ptrNode lastNode;
int graphSize;
int shortestPathWeight = BIG_NUM;

int main() {
    //printf("START!\n");
    char input;
    int DONE = 0;
    int amount_of_nodes = 0;
    ptrNode ptrGraph = NULL;
    while (DONE != EOF) {
        DONE = scanf("%c", &input);
        switch (input) {
            case 'A': { // build a new graph, case a graph is already existed delete the old and create a new one.
                if(ptrGraph != NULL){
                    freeGraph(&ptrGraph);
                }
                // initiating the Graph nodes.
                scanf("%d", &amount_of_nodes);
                initGraph(&ptrGraph, amount_of_nodes);
                break;
            }
            case 'n': {
                // adding an edges to a specific node.
                int src = -1; // the node that the new edges will start from
                int dest = -1;
                int weight = -1;
                int num = -1;
                scanf("%d", &src);
                // scan two numbers first one for dest second one for weight
                while (scanf("%d", &num)) {
                    if (src != -1 && dest == -1 && weight == -1) {
                        dest = num;
                    } else if (src != -1 && dest != -1 && weight == -1) {
                        weight = num;
                    }
                    // after scanned two numbers we have all the data we need to create a new edge.
                     if (src != -1 && dest != -1 && weight != -1) {
                        addEdge(&ptrGraph, src, dest, weight);
                        dest = -1;
                        weight = -1;
                    }
                }
                break;
            }
            case 'B':{
                // add new node, case this node already exist in the graph
                // it will remove his old edges and will update to the new ones given.
                int new_id;
                ptrNode curr_n = NULL;
                int hasEdges = false;
                int count_new_edges = 0;
                scanf("%d", &new_id);
                if(!contains(ptrGraph, new_id)){
                    addNode(&ptrGraph, new_id);
                }
                else{
                    hasEdges = true;
                    curr_n = getNode(ptrGraph, new_id);
                }
                int dest = -1;
                int weight = -1;
                int num = -1;
                while (scanf("%d", &num)) {
                    if (new_id != -1 && dest == -1 && weight == -1) {
                        dest = num;
                    } else if (new_id != -1 && dest != -1 && weight == -1) {
                        weight = num;
                    }
                    if (new_id != -1 && dest != -1 && weight != -1) {
                        if(hasEdges){
                            freeEdges(&curr_n);
                            curr_n->edges = NULL;
                            curr_n->edges_s = 0;
                            hasEdges = false;
                        }
                        addEdge(&ptrGraph, new_id, dest, weight);
                        dest = -1;
                        weight = -1;
                        count_new_edges++;
                    }
                }
                break;
            }
            case 'D':{ // removes a node from the graph
                int id;
                scanf("%d", &id);
                if(contains(ptrGraph, id)){
                    removeNode(&ptrGraph, id);
                    graphSize--;
                }
                break;
            }
//             case 'P':{ // for me
//                 printGraph_cmd(ptrGraph);
//                 break;
//             }
            case 'S':{ // shortest path between two nodes
                int source, dest;
                scanf("%d", &source);
                scanf("%d", &dest);
                ptrQueue queue = initQueue(ptrGraph, source);
                int ans = shortestPath(queue, dest);
                if(ans == BIG_NUM){
                    ans = -1;
                }
                freeQueue(&queue);
                printf("Dijsktra shortest path: %d \n", ans);
                break;
            }
            case 'T': // shortest path between multiple nodes.
            {
                int amount_of_cities, num;
                scanf("%d", &amount_of_cities);
                int *cities;
                cities = (int*)malloc(sizeof(int) * amount_of_cities);
                if(!cities){
                    printf("Memory didn't allocated!\n");
                    exit(0);
                }
                for(int i = 0; i < amount_of_cities; i++){
                    scanf("%d", &num);
                   *(cities + i) =  num;
                }
                heapPermuteTSP(ptrGraph, cities, amount_of_cities, amount_of_cities);
                if(shortestPathWeight == BIG_NUM){
                    shortestPathWeight = -1;
                }
                printf("TSP shortest path: %d \n", shortestPathWeight);
                shortestPathWeight = BIG_NUM;
                free(cities);
                break;
            }
//             case 'E': { // for me
//                 exit(0);
//             }
            default:{
                break;
            }
        }
    }
    freeGraph(&ptrGraph);
    return 0;
}

