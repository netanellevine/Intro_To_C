
typedef struct GRAPH *ptrNode;

typedef struct edge_ {
    int weight;
    ptrNode endpoint;
    struct edge_ *next;
} Edge, *ptrEdge;


typedef struct GRAPH {
    int node_num;
    int edges_s;
    ptrEdge edges;
    struct GRAPH *next;
} Node, *ptrNode;


void printGraph_cmd(ptrNode head);
void freeGraph(ptrNode *head);
void freeEdges(ptrNode *node);
void initGraph(ptrNode *head, int size);
void addEdge(ptrNode *head, int source, int dest, int weight);
void addNode(ptrNode *head, int id);
ptrNode getNode(ptrNode head, int id);
int contains(ptrNode head, int id);
void removeEdge(ptrNode *node, int dest);
void remove_in_edges(ptrNode *head, int id);
void removeNode(ptrNode *head, int id);


