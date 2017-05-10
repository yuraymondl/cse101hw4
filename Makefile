# A simple makefile for CSE 100 PA4

CC=g++
CXXFLAGS=-std=c++11
LDFLAGS=

all: pathfinder actorconnections extension

pathfinder: ActorGraph.o Movie.o ActorNode.o util.o

actorconnections: util.o ActorGraph.o Movie.o ActorNode.o disjointSet.o dsMovie.o dsActorNode.o

ActorGraph.o: ActorNode.h Movie.h ActorGraph.h ActorGraph.cpp

ActorNode.o: ActorNode.h Movie.h ActorNode.cpp

Movie.o: Movie.h Movie.cpp ActorNode.h

dsActorNode.o: dsActorNode.h dsMovie.h dsActorNode.cpp

dsMovie.o: dsMovie.h dsMovie.cpp dsActorNode.h

disjointSet.o: dsActorNode.h dsMovie.h disjointSet.h disjointSet.cpp 

util.o: util.h

extension: extGraph.o person.o

extGraph.o: extGraph.h extGraph.cpp person.h

person.o: person.h person.cpp

clean:
	rm -f pathfinder actorconnections extension *.o core*

