/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
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
	ofstream fout;
	fout.open(f);
	if (fout.fail()) {
		cout << "Error opening file: " << f;
		return;
	}

	fout << "digraph g {" << endl;
	if (_type == 1 || _type == 3) {
		fout << "edge [dir=none, color=red]" << endl;
	}
	else {
		fout << "edge [color=red]" << endl;
	}
	vector<string> visited_nodes;

	for (int i = 0; i < _nodes.size(); i++) {
		//cout <<getNodeRealName(i) << "->";
		cout << "Node is :" << getNodeRealName(i) <<", Number of Fan out : " << numFanout(i) << " " << endl;
		for (int j = 0; j < numFanout(i); j++) {
			//string realname = getNodeRealName(i);
			//string fanoutedge = getNodeRealName(getNodeFanout(i, j));
			if (_type == 1 || _type == 3) {
				//to print only edges only once for undirected graphs
				if (getNodeFanout(i, j) >= getNodeName(i)) {
					fout << getNodeRealName(i) << " -> " << getNodeRealName(getNodeFanout(i, j));
					if (_type == 3) {
						fout << " [label = " << getNodeFanoutEdgeWeight(i, j) << "]";
					}
					fout << endl;
				}
			}
			else {
				fout << getNodeRealName(i) << " -> " << getNodeRealName(getNodeFanout(i, j));
				if (_type == 4) {
					fout << " [label = " << getNodeFanoutEdgeWeight(i, j) << "]";
				}
				fout << endl;
			}

			cout << "Fanout : " << getNodeRealName(getNodeFanout(i, j));
			cout << "Fanin : " << getNodeRealName(getNodeFanin(i, j));
			if (_type == 3 || _type == 4) {
				cout << " [label = " << getNodeFanoutEdgeWeight(i, j) << "]";
			}
			cout << endl;
		}
		cout << endl;
    }
	fout << "}" << endl;
	fout.close();
}


//EOF
