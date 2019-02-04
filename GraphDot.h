/*----------------------------------------------------------------
file: GraphDot.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has GraphDot class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef GraphDot_H
#define GraphDot_H

#include "Graph.h"

/*----------------------------------------------------------------
Declaration of GraphDot class
-----------------------------------------------------------------*/
class GraphDot {
public:
	GraphDot(const Graph& g, const string& f) : _g(g), _f(f) {
		_writeGraph();
	}
	~GraphDot() {}
	GraphDot(const GraphDot& from) = delete;
	GraphDot& operator=(const GraphDot& from) = delete;
private:
	const Graph& _g;
	const string& _f;
	void _writeGraph() const;
};


#endif