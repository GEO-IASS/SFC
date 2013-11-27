#include "edge.hh"
#include "vertex.hh"
#include "ant.hh"

#include <iostream>

/**
 * Get the second vertex when the first one is
 * given as a parameter.
 */
ACO::Vertex& ACO::Edge::getSecondVertex(Vertex& v)
{
  if (v == v1_)
  {
    return v2_;
  }
  else
  {
    return v1_;
  }
}

/**
 * Update current level of pheromon according to
 * passed ants.
 */
void ACO::Edge::updatePheromon(ASImplementation& as)
{
  float sumDelta = 0.0f;

  for (Ant *a : passedAnts_)
  {
    sumDelta += as.makeOneDelta(pheromonConst_, distance_, a->getPathCost());
  }
  // move to as implementation
  pheromon_ = (1-evaporationCoef_)*pheromon_ + sumDelta;
}

/**
 * Restarts edges data members before a next iteration
 */
void ACO::Edge::restart()
{
  passedAnts_.clear();
}
