#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Node.h"

using namespace std;

int main(int argc, char** argv) {

  int n = 10;

  vector<Node> vertices(n);

  srand(time(NULL));

  //initialize n vertices
  for(int i=0; i<vertices.size(); i++) {
    vertices[i] = new Node();
  }

  //link vertices based on rng
  for(int i=0; i<vertices.size()-1; i++) {
    for(int j=i+1; j<vertices.size(); j++) {
      //roll, if so then link vertices
      if(rand()%10+1 > 5) {
        vertices[i].adj->push_back(&vertices[j]);
        vertices[j].adj->push_back(&vertices[i]);
        vertices[i].order++;
        vertices[j].order++;
      }
    }
  }

  //sort, do greedy alg
  sort(vertices.begin(), vertices.end(), myfunction);

  for(int i=0; i<vertices.size(); i++) {
    if(vertices[i].inI) {
      for(int j=0; j<vertices[i].adj.size(); j++) {
        vertices[i].adj[j]->inI = false;
      }
    }
  }

  
}

bool myfunction(Node left, Node right) {
  return left.order < right.order;
}
