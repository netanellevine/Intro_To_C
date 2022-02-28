
typedef struct QUEUE {
    ptrNode Vertex;
    int shortestDist;
    int visited;
    struct QUEUE *next;
}Queue, *ptrQueue;

ptrQueue initQueue(ptrNode head, int src);
void sortQueue(ptrQueue *head);
ptrQueue deQueue(ptrQueue *head);
ptrQueue getFirstUnvisited(ptrQueue head);
ptrQueue getQNode(ptrQueue head, int id);
ptrQueue getQNodeByInd(ptrQueue head, int ind);
int shortestPath(ptrQueue head, int dest);
int getAmountOfPermutaions(int num);
void heapPermuteTSP(ptrNode head,int cities_to_visit[], int size, int original_size);
void swap (int *x, int *y);
void calculateTSP(ptrNode head, int *arr, int size);
void freeQueue(ptrQueue *head);


