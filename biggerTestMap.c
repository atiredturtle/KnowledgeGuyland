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
void assignID (link *map);
void printMap (link map[]);

int main (int argc, char *argv[]){
   link map[NUM_NODES];
   
   // create all nodes
   link node1  = malloc(sizeof(node));
   link node2  = malloc(sizeof(node));
   link node3  = malloc(sizeof(node));
   link node4  = malloc(sizeof(node));
   link node5  = malloc(sizeof(node));
   link node6  = malloc(sizeof(node));
   link node7  = malloc(sizeof(node));
   link node8  = malloc(sizeof(node));
   link node9  = malloc(sizeof(node));
   link node10 = malloc(sizeof(node));
   link node11 = malloc(sizeof(node));
   link node12 = malloc(sizeof(node));
   link node13 = malloc(sizeof(node));
   
   // place all nodes in map array
   map[0]  = node1;
   map[1]  = node2;
   map[2]  = node3;
   map[3]  = node4;
   map[4]  = node5;
   map[5]  = node6;
   map[6]  = node7;
   map[7]  = node8;
   map[8]  = node9;
   map[9]  = node10;
   map[10] = node11;
   map[11] = node12;
   map[12] = node13;
   
   assignID (map);
   
   printf ("\n \n");
   
   /* list of connections
   node1 -> node2    
   node1 -> node7    
   node2 -> node3    
   node3 -> node4    
   node3 -> node9    
   node4 -> node5    
   node5 -> node6    
   node7 -> node8    
   node8 -> node9    
   node8 -> node11     
   node9 -> node10      
   node10 -> node6     
   node10 -> node13  
   node11 -> node12  
   node12 -> node13 
   */
   
   /* association table for joining nodes (0 is no link)
      |  link1  |  link2  |  link3  |                          
   1  |    0    |    2    |    7    |                          
   2  |    0    |    3    |    1    |
   3  |    2    |    4    |    9    |
   4  |    0    |    5    |    3    |
   5  |    4    |    0    |    6    |
   6  |    5    |    0    |    10   |
   7  |    1    |    8    |    0    |
   8  |    7    |    9    |    11   |
   9  |    3    |    10   |    8    |
   10 |    9    |    6    |    13   |
   11 |    8    |    12   |    0    |
   12 |    11   |    13   |    0    |
   13 |    10   |    0    |    12   |
   */   
   

   
   // join all nodes
   joinNodes (node1, NULL, node2, node7);
   joinNodes (node2, NULL, node3, node1);
   joinNodes (node3, node2, node4, node9);
   joinNodes (node4, NULL, node5, node3);
   joinNodes (node5, node4, NULL, node6);
   joinNodes (node6, node5, NULL, node10);
   joinNodes (node7, node1, node8, NULL);
   joinNodes (node8, node7, node9, node11);
   joinNodes (node9, node3, node10, node8);
   joinNodes (node10, node9, node6, node13);
   joinNodes (node11, node8, node12, NULL);
   joinNodes (node12, node11, node13, NULL);
   joinNodes (node13, node10, NULL, node12);
   
   printMap (map);
   
   return EXIT_SUCCESS;
}

void joinNodes (link n, link l1, link l2, link l3){
   n->link1 = l1;
   n->link2 = l2;
   n->link3 = l3; 
}

void assignID (link *map){
   int i = 0;
   while (i < NUM_NODES){
      map[i]->ID = i+1;
      i++;
   }
}

void printMap (link map[NUM_NODES]){
    int i = 0;
    while (i < NUM_NODES){
        printf ("node%d:   ", i+1);
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