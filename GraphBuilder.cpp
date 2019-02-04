/*----------------------------------------------------------------
file: GraphBuilder.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has GraphBuilder class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "GraphBuilder.h"

/*----------------------------------------------------------------
WRITE CODE HERE
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
            DFS called from graph
Build graph from string
-----------------------------------------------------------------*/
void Graph::buildGraph(const vector<string>& s) {
  //WRITE CODE
	// Build the interface GraphBuilder to build the graph, using only the public functions available in class Graph
  GraphBuilder b(*this,s) ;
}

/*----------------------------------------------------------------
	This functions _buildGraph() would be called from constructor to build the graph
-----------------------------------------------------------------*/
void GraphBuilder::_buildGraph() {
	int GraphType = _g.getType();
	//cout << "Display Graph type : " << GraphType << endl;

	if (GraphType::Type::UNDIRECTED == GraphType || GraphType::Type::DIRECTED == GraphType) {
		for (int i = 0; i < _s.size(); i+=2) {
			int node1_position = _g.insertOrFind(_s[i], false);
			int node2_position = _g.insertOrFind(_s[i + 1], false);
			_g.createEdge(node1_position, node2_position, 0, true);
			if (GraphType::Type::UNDIRECTED == GraphType) {
				_g.createEdge(node1_position, node2_position, 0, false);
				_g.createEdge(node2_position, node1_position, 0, true);
				_g.createEdge(node2_position, node1_position, 0, false);
			}
			else {
				_g.createEdge(node1_position, node2_position, 0, false);
			}
		}
	}

	if (GraphType::Type::WEIGHTED_UNDIRECTED == GraphType || GraphType::Type::WEIGHTED_DIRECTED == GraphType) {
		for (int i = 0; i < _s.size(); i += 3) {
			int node1_position = _g.insertOrFind(_s[i], false);
			int node2_position = _g.insertOrFind(_s[i + 1], false);
			_g.createEdge(node1_position, node2_position, _g.string2double(_s[i + 2]), true);
			if (GraphType::Type::WEIGHTED_UNDIRECTED == GraphType) {
				_g.createEdge(node1_position, node2_position, _g.string2double(_s[i + 2]), false);
				_g.createEdge(node2_position, node1_position, _g.string2double(_s[i + 2]), true);
				_g.createEdge(node2_position, node1_position, _g.string2double(_s[i + 2]), false);
			}
			else {
				_g.createEdge(node1_position, node2_position, _g.string2double(_s[i + 2]), false);
			}
		}
	}
}


//EOF





