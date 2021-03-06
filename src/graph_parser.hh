#ifndef ACO_GRAPH_PARSER
#define ACO_GRAPH_PARSER

/****************************************************************
 * ACO algorithm
 * Project to Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Class for parsing of input graph
 ****************************************************************/


// standard libraries
#include <fstream>
#include <string>

// ACO libraries
#include "graph.hh"

namespace ACO
{
  class GraphParser;
}

class ACO::GraphParser
{
private: // private data types
  typedef std::string String;

private: // private constants
  const String e_cannotRead;
  const String e_badFormat;
  const String e_warning;

public: // public methods
  GraphParser() :
    e_cannotRead("Vstupni soubor nelze cist"),
    e_badFormat("Soubor porusuje vstupni format: "),
    e_warning("POZOR!!!: Tato hrana jiz byla definovana a bude ignorovana")

  {}
  void parseGraphFromFile(std::ifstream& graphFile, Graph& graph);

private: // private methods
  void parseFormatedLine(String& line, Graph& graph);
  void addTransitionToGraph(String& node1, String& node2,
      Graph::Distance distance, Graph& graph);
};

#endif
