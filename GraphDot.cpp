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
	for (int i = 0; i < _nodes.size(); i++) {
		//cout <<getNodeRealName(i) << "->";
		//cout << "Number of Fan out : " << numFanout(i) << " " << endl;
		for (int j = 0; j < numFanout(i); j++) {
			cout << getNodeRealName(i) << " -> " <<getNodeRealName(getNodeFanout(i, j)) << endl;
		}
		//cout << endl;
    }
}


//EOF
