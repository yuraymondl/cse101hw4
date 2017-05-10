#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

using namespace std;

/* Functions as a vertex in the actor graph */
class Node {

public:

  Node();
  int order;
  bool inI;
  vector<Node*> adj;
};

#endif //NODE_H
