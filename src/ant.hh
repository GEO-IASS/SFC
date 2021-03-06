#ifndef ACO_ANT
#define ACO_ANT

/****************************************************************
 * ACO algorithm
 * Project to Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Ant class header
 ****************************************************************/


#include <vector>
#include <unordered_set>
#include <string>
#include <cfloat>
#include <string>
#include <stdexcept>

#include "aco_classes.hh"
#include "random_provider.hh"

namespace ACO
{
  class ASImplementation;
}

class ACO::Ant
{
public: // public data types
  typedef std::vector<Vertex *> Path;
  typedef float PathCost;
private: // private data types
  typedef std::unordered_set<Vertex *> Vertices;
  typedef std::unordered_set<Edge *> Edges;

private: // private data members
  int id_;
  Vertex* actualVertex_;
  Vertices visitedVertices_;
  Path path_;
  Edges visitedEdges_;
  PathCost pathCost_;
  bool goalSatisfied_;
  const float pheromonCoef_;
  const float distanceCoef_;
  RandomProvider random_;
  bool randomChoice_; // random choice when more paths have same probability

private: // private error messages
  std::string e_vertexAlreadyVisited;
  std::string e_noBestEdge;

public: // public constructors
  Ant(int id, float pheromonCoef, float distanceCoef, bool randomChoice = true) :
    id_(id), actualVertex_(NULL),
    pathCost_(0), goalSatisfied_(false), pheromonCoef_(pheromonCoef),
    distanceCoef_(distanceCoef), random_(), randomChoice_(randomChoice),
    e_vertexAlreadyVisited("Vrchol jiz byl navstiven"),
    e_noBestEdge("Zadna hrana pro pokracovani cesty nebyla nalezena")
    {};


public: // public methods
  void makeStep(ASImplementation& as);
  void restart();
  void returnToStart();

private: // private methods
  void addVertexToVisited(Vertex* v);
  float sumAllEdges(); // sum pheromon times distance for all edges
  // get edge with best probability to be chosen
  Edge* getBestEdge(float allEdges, ASImplementation& as);
  bool isNewBest(float best, float value);
 
public: // operators
  bool operator==(Ant& a) {return a.getId() == getId();}
  bool operator!=(Ant& a) {return a.getId() != getId();}

public: // getters
  int getId() {return id_;}
  const Vertices& getVisitedVertices() const {return visitedVertices_;}
  unsigned int getVisitedVerticesNumber() {return visitedVertices_.size();}
  bool isGoalSatisfied() {return goalSatisfied_;}
  PathCost getPathCost() {return pathCost_;}
  Path& getPath() {return path_;}
  Vertex* getActualVertex() {return actualVertex_;}

public: // setters
  void setGoalStatisfied(bool goal) {goalSatisfied_ = goal;}
  void setActualVertex(Vertex* v);
};
#endif
