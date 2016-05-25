#include <stdio.h>
#include <stdlib.h>

#define NO_ONE 0
#define NUM_NODES 54
#define NON 999

typedef struct _node *link;
typedef struct _node {
   // the number of the node (for testing purposes)
   int id;
   // all links
   link link1;
   link link2;
   link link3;

   int owner1;
   int owner2;
   int owner3;
} node;


/*                      HOW LINKS ARE DEFINED 
          NODE_TYPE_2             ||         NODE_TYPE_2
                link2             ||    link1
              /                   ||         \
 link1 -- node                    ||          node -- link2
              \                   ||         /
                link3             ||    link3
*/

void joinNodes (int nodeID, link *map, int nodeLink1, int nodeLink2, int nodeLink3);
void populateMap (link *map);
void printMap (link map[]);

int main (int argc, char *argv[]){
   link map[NUM_NODES];

   populateMap(map);

   printf ("\n \n");


   // join all nodes
   // FORMAT: node, map, link1, link2 ,link3
   joinNodes (0,  map,  NON, 1,    12);
   joinNodes (1,  map,  NON, 2,     0);
   joinNodes (2,  map,  1,   3,    14);
   joinNodes (3,  map,  NON, 4,     2);
   joinNodes (4,  map,  3,   5,    16);

   joinNodes (5,  map,  NON, 6,     4);
   joinNodes (6,  map,  5,   NON,   7);
   joinNodes (7,  map,  6,   8,    17);
   joinNodes (8,  map,  7,   NON,   9);
   joinNodes (9,  map,  8,   10,   19);

   joinNodes (10, map,  9,   NON,  11);
   joinNodes (11, map,  10,  NON,  21);
   joinNodes (12, map,  0,   13,   22);
   joinNodes (13, map,  12,  14,   23);
   joinNodes (14, map,  2,   15,   13);

   joinNodes (15, map,  14,  16,   25);
   joinNodes (16, map,  4,   17,   15);
   joinNodes (17, map,  16,  7,    18);
   joinNodes (18, map,  17,  19,   26);
   joinNodes (19, map,  18,  9,    20);

   joinNodes (20, map,  19,  21,   28);
   joinNodes (21, map,  20,  11,   31);
   joinNodes (22, map,  NON, 12,   32);
   joinNodes (23, map,  13,  24,   33);
   joinNodes (24, map,  23,  25,   36);

   joinNodes (25, map,  15,  26,   24);
   joinNodes (26, map,  25,  18,   27);
   joinNodes (27, map,  26,  28,   37);
   joinNodes (28, map,  27,  20,   29);
   joinNodes (29, map,  28,  30,   39);

   joinNodes (30, map,  29,  31,   42);
   joinNodes (31, map,  21,  NON,  30);
   joinNodes (32, map,  22,  33,   43);
   joinNodes (33, map,  32,  23,   34);
   joinNodes (34, map,  33,  35,   45);

   joinNodes (35, map,  34,  36,   48);
   joinNodes (36, map,  24,  37,   35);
   joinNodes (37, map,  36,  27,   38);
   joinNodes (38, map,  37,  39,   49);
   joinNodes (39, map,  38,  29,   40);

   joinNodes (40, map,  39,  41,   51);
   joinNodes (41, map,  40,  42,   NON);
   joinNodes (42, map,  30,  NON,  41);
   joinNodes (43, map,  NON,  32,  44);
   joinNodes (44, map,  43,   45,  NON);

   joinNodes (45, map,  44,  34,   46);
   joinNodes (46, map,  45,  47,  NON);
   joinNodes (47, map,  46,  48,   52);
   joinNodes (48, map,  35,  49,    47);
   joinNodes (49, map,  48,   38,   50);

   joinNodes (50, map,  49,  51,   53);
   joinNodes (51, map,  50,  40,   NON); 
   joinNodes (52, map,  47,  53,   NON);
   joinNodes (53, map,  52,  50,   NON);

   printMap (map);

   return EXIT_SUCCESS;
}

void joinNodes (int nodeID, link *map, int nodeLink1, int nodeLink2, int nodeLink3){
   if (nodeLink1 != NON){
      map[nodeID]->link1 = map[nodeLink1];
   } else {
      map[nodeID]->link1 = NULL;
   }

   if (nodeLink2 != NON){
      map[nodeID]->link2 = map[nodeLink2];
   } else {
      map[nodeID]->link2 = NULL;
   }

   if (nodeLink3 != NON){
      map[nodeID]->link3 = map[nodeLink3];
   } else {
      map[nodeID]->link3 = NULL;
   }

}
/*
void joinNodes (link n, link l1, link l2, link l3){
   n->link1 = l1;
   n->link2 = l2;
   n->link3 = l3;
}*/

void populateMap (link *map){
   int i = 0;

   while (i < NUM_NODES){
      // create new node
      map[i] = malloc(sizeof(node));
      // assign id
      map[i]->id = i;
      i++;
   }
}

void printMap (link map[NUM_NODES]){
    int i = 0;
    while (i < NUM_NODES){
        printf ("node%d:   ", i);
        if (map[i]->link1 != NULL){
           printf ("link1 -> %d    |  ", map[i]->link1->id);
        } else {
           printf ("link1 -> NULL  |  ");
        }

        if (map[i]->link2 != NULL){
           printf ("link2 -> %d    |  ", map[i]->link2->id);
        } else {
           printf ("link2 -> NULL  |  ");
        }

        if (map[i]->link3 != NULL){
           printf ("link3 -> %d    |  \n", map[i]->link3->id);
        } else {
           printf ("link3 -> NULL  |  \n");
        }
        i++;
    }
}
