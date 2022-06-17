#include <stdio.h>

#include <stdlib.h>

 

struct edge{

int weight, src, des;

};

 

typedef struct edge edge;

 

struct graph{

int e, v;

edge *arr;

};

 

typedef struct graph graph;

 

 

void addedge(graph *g, int w, int s, int d)

{

edge x;

x.weight = w;

x.src = s;

x.des = d;

g->arr = (edge*)realloc(g->arr, (g->e+1) * sizeof(edge));

int i = g->e;

g->e++;

for(; i > 0 && w < g->arr[i-1].weight ; i--)

g->arr[i] = g->arr[i - 1];

g->arr[i] = x;

}

 

graph *creategraph(int v)

{

graph *g = (graph*)malloc(sizeof(graph));

g->arr = (edge*)malloc(sizeof(edge));

g->v = v;

g->e = 0;

return g;

}

 

void printGraph(graph *g)

{

printf("WEIGHT\tSOURCE\tDESTINATION\n");

for(int i = 0 ; i < g->e ; i++)

printf("%d\t%d\t%d\n", g->arr[i].weight, g->arr[i].src, g->arr[i].des);

}

 

struct node{

int data, rank;

struct node *next;

};

 

typedef struct node node;

 

node *makeset(int data)

{

node *newnode = (node*)malloc(sizeof(node));

newnode->data = data;

newnode->rank = 0;

newnode->next = newnode;

return newnode;

}

 

node *findset(node *value)

{

if(value->next->data == value->data)

return value;

return findset(value->next);

}

 

void makeunion(node *u, node *v)

{

node *un = findset(u), *vn = findset(v);

if(un->rank > vn->rank)

vn->next = un;

else

{

un->next = vn;

if(un->rank == vn->rank)

vn->rank++;

}

}

 

void kruskal(graph *g)

{

graph *a = creategraph(g->v);

int i;

node **setaddr = (node **)malloc(g->v * sizeof(node*));

for(i = 0 ; i < g->v ; i++)

setaddr[i] = makeset(i);

for(i = 0 ; i < g->e ; i++)

{

if(findset(setaddr[g->arr[i].src]) != findset(setaddr[g->arr[i].des]))

{

addedge(a, g->arr[i].weight, g->arr[i].src, g->arr[i].des);

makeunion(setaddr[g->arr[i].src], setaddr[g->arr[i].des]);

}

}

printGraph(a);

}

 

int main()

{

graph *g = creategraph(7);

addedge(g, 1, 0, 1);

addedge(g, 1, 0, 2);

addedge(g, 1, 1, 2);

addedge(g, 1, 2, 5);

addedge(g, 1, 5, 3);

addedge(g, 1, 5, 4);

addedge(g, 1, 4, 3);

// printGraph(g);

kruskal(g);

return 0;

}

