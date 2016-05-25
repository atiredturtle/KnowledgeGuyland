
#include <stdio.h>
#include <stdlib.h>

#define NO_ONE 0
#define NUM_NODES 13

typedef struct _node *link;
typedef struct _node {
   // the number of the node (for testing purposes)
   int ID;
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

void joinNodes (link n, link l1, link l2, link l3);
void populateMap (link *map);
void printMap (link map[]);

int main (int argc, char *argv[]){
   link map[NUM_NODES];

   populateMap(map);

   printf ("\n \n");

   /* association table for joining nodes (? is no link)
      |  link1  |  link2  |  link3  |
   0  |    ?    |    1    |    6    |
   1  |    ?    |    2    |    0    |
   2  |    1    |    3    |    8    |
   3  |    ?    |    4    |    2    |
   4  |    3    |    ?    |    5    |
   5  |    4    |    ?    |    9    |
   6  |    0    |    7    |    ?    |
   7  |    6    |    8    |    10   |
   8  |    3    |    10   |    8    |
   9  |    8    |    5    |    12   |
   10 |    7    |    11   |    ?    |
   11 |    10   |    12   |    ?    |
   12 |    9    |    ?    |    11   |
   */



   // join all nodes
   joinNodes (map[0], NULL, map[1], map[6]);
   joinNodes (map[1], NULL, map[2], map[0]);
   joinNodes (map[2], map[1], map[3], map[8]);
   joinNodes (map[3], NULL, map[4], map[2]);
   joinNodes (map[4], map[3], NULL, map[5]);
   joinNodes (map[5], map[4], NULL, map[9]);
   joinNodes (map[6], map[0], map[7], NULL);
   joinNodes (map[7], map[6], map[8], map[10]);
   joinNodes (map[8], map[2], map[9], map[7]);
   joinNodes (map[9], map[8], map[5], map[12]);
   joinNodes (map[10], map[7], map[11], NULL);
   joinNodes (map[11], map[10], map[12], NULL);
   joinNodes (map[12], map[9], NULL, map[11]);

   printMap (map);

   return EXIT_SUCCESS;
}

void joinNodes (link n, link l1, link l2, link l3){
   n->link1 = l1;
   n->link2 = l2;
   n->link3 = l3;
}

void populateMap (link *map){
   int i = 0;

   while (i < NUM_NODES){
      // create new node
      map[i] = malloc(sizeof(node));
      // set the ID for the node
      map[i]->ID = i;
      i++;
   }
}

void printMap (link map[NUM_NODES]){
    int i = 0;
    while (i < NUM_NODES){
        printf ("node%d:   ", i);
        if (map[i]->link1 != NULL){
           printf ("link1 -> %d    |  ", map[i]->link1->ID);
        } else {
           printf ("link1 -> NULL  |  ");
        }

        if (map[i]->link2 != NULL){
           printf ("link2 -> %d    |  ", map[i]->link2->ID);
        } else {
           printf ("link2 -> NULL  |  ");
        }

        if (map[i]->link3 != NULL){
           printf ("link3 -> %d    |  \n", map[i]->link3->ID);
        } else {
           printf ("link3 -> NULL  |  \n");
        }
        i++;
    }
}
