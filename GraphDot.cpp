/*----------------------------------------------------------------
file: GraphDot.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has GraphDot class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "GraphDot.h"

/*----------------------------------------------------------------
              write dot called from graph
write dot
-----------------------------------------------------------------*/
void Graph::writeDot(const string& f) const {
	//WRITE CODE
	// Build an interface with GraphDot class to write the graphs in .dot files using available functions in class Graph
	GraphDot b(*this, f);
}

/*----------------------------------------------------------------
	This functions _writeGraph() would be called from constructor to write the graph
-----------------------------------------------------------------*/
void GraphDot::_writeGraph() const {
	int GraphType = _g.getType();
	ofstream fout;
	fout.open(_f);
	if (fout.fail()) {
		cout << "Error opening file: " << _f;
		return;
	}

	fout << "digraph g {" << endl;
	if (GraphType::Type::UNDIRECTED == GraphType || GraphType::Type::WEIGHTED_UNDIRECTED == GraphType) {
		fout << "edge [dir=none, color=red]" << endl;
	}
	else {
		fout << "edge [color=red]" << endl;
	}

	for (int i = 0; i < _g.getnumV(); i++) {
		//cout << "Node is :" << getNodeRealName(i) << endl;
		if (_g.numFanout(i) == 0) {
			//cout << "No Fan Outs ";
		}
		else {
			//cout << "Fan outs are : ";
		}
		for (int j = 0; j < _g.numFanout(i); j++) {
			if (GraphType::Type::UNDIRECTED == GraphType || GraphType::Type::WEIGHTED_UNDIRECTED == GraphType) {
				//to print only edges only once for undirected graphs
				if (_g.getNodeFanout(i, j) >= _g.getNodeName(i)) {
					fout << _g.getNodeRealName(i) << " -> " << _g.getNodeRealName(_g.getNodeFanout(i, j));
					if (GraphType::Type::WEIGHTED_UNDIRECTED == GraphType) {
						fout << " [label = " << _g.getNodeFanoutEdgeWeight(i, j) << "]";
					}
					fout << endl;
				}
			}
			else {
				fout << _g.getNodeRealName(i) << " -> " << _g.getNodeRealName(_g.getNodeFanout(i, j));
				if (GraphType::Type::WEIGHTED_DIRECTED == GraphType) {
					fout << " [label = " << _g.getNodeFanoutEdgeWeight(i, j) << "]";
				}
				fout << endl;
			}

			//cout << getNodeRealName(getNodeFanout(i, j)) << " ";
			if (GraphType::Type::WEIGHTED_UNDIRECTED == GraphType || GraphType::Type::WEIGHTED_DIRECTED == GraphType) {
			}
		}
	}

	fout << "}" << endl;
	fout.close();
}


//EOF
