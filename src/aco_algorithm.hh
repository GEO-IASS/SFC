#ifndef ACO_ACO_ALGORITHM
#define ACO_ACO_ALGORITMH

#include "ant_population.hh"
#include "graph.hh"
#include "random_provider.hh"

#include <cfloat>

namespace ACO
{
  class ACOAlgorithm;
}

class ACO::ACOAlgorithm
{
private: // private data types
  // ants withou wrapping object
  typedef std::vector<Ant*> RawPopulation;
  typedef Ant::Path Path;
  typedef Ant::PathCost PathCost;

private: // private data memebers
  AntPopulation population_;
  Graph graph_;
  RandomProvider random_;
  int maxIteration_;
  PathCost bestPathCost_;
  Path bestPath_;

public: // constructors
  ACOAlgorithm(AntPopulation population, Graph graph, RandomProvider random, int maxIter) :
    population_(population), graph_(graph), random_(random),
    maxIteration_(maxIter), bestPathCost_(FLT_MAX)
  {}

public: // public methods
  void compute();
  void getResult(std::vector<Vertex>);

private: // private methods
  void setRandomVertices();
  void createAntSolution();
  bool isGoalReached(Ant& ant);
  void saveBestPath();
};

#endif