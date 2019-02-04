/*----------------------------------------------------------------
file: GraphBuilder.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has GraphBuilder class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef GraphBuilder_H
#define GraphBuilder_H

#include "Graph.h"

/*----------------------------------------------------------------
Declaration of GraphBuilder class
WRITE CODE
-----------------------------------------------------------------*/
class GraphBuilder {
public:
	GraphBuilder(Graph& g, const vector<string>& s): _g(g), _s(s) {
		_buildGraph();
	}
	~GraphBuilder() {}
private:
	Graph& _g;
	const vector<string> _s;
	void _buildGraph();
};
#endif


//EOF
