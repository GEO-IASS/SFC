#include "as_maxmin.hh"

#include "graph.hh"

/**
 * Compute pheromon delta for a given distance (legnth of edge) and constants
 * but only for an ant with the best solution
 */
float ACO::ASMaxMin::makeOneDelta(float pheromonConst,
    float distance, Ant* ant, int order)
{
  if (*ant != *bestAnt_)
  { // not best ant add no pheromon
    return 0;
  }
  return pheromonConst/ant->getPathCost();
}

/**
 * Update pheromon only on the best edges
 */
void ACO::ASMaxMin::updatePheromon(Graph& graph)
{
  std::unordered_set<Vertex *> bestPathSet(bestPath_.begin(), bestPath_.end());
  for (Edge* e : graph.getEdges())
  {
    if (bestPathSet.count(&e->getVertex1()) && bestPathSet.count(&e->getVertex2()))
    {
      e->updatePheromon(*this);
    }
  }
}

float ACO::ASMaxMin::maxMinCorrection(float pheromon)
{
  if (pheromon > pheromonMax_)
  {
    return pheromonMax_;
  }
  else if (pheromon < pheromonMin_)
  {
    return pheromonMin_;
  }
  return pheromon;
}