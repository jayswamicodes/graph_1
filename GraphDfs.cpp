/*----------------------------------------------------------------
file: GraphDfs.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has GraphDfs class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "GraphDfs.h"

/*----------------------------------------------------------------
                         DFS called from graph
-----------------------------------------------------------------*/
void Graph::dfs(const char* t, const string& s, bool& cycle, int& work, vector<string>& ans) {
	// Build the interface GraphDfs to do dfs on the graph, using only the public functions available in class Graph
	GraphDfs topo(*this, t, s, cycle, work, ans);
}

void GraphDfs::_buildTopologicalOrder() {
	GraphType::Type type = _g.getType();
	cout << "#######################################" << endl;
	cout << _t << endl;
	cout << "Graph type is : " << type << endl;
	cout << "Starting node is : " << _s << endl;
	cout << "Number of nodes : " << _g.getnumV() << endl;
	cout << "Number of edges : " << _g.getnumE() << endl;
	for (int i = 0; i < _g.getnumV(); i++) {
		_color.push_back("green");
		_g.setTemp(i, i);
	}
	for (int i = 0; i < _g.getnumV(); i++) {
		_assertArr.push_back("false");
	}
	cout << endl;
	_dfsBuild(_s);
	cout << "Topological order : ";
	for (int i = 1; i <= _ans.size(); i++) {
		cout << _ans[_ans.size() - i] << " ";
	}
	cout << endl;
	cout << "Does Graph has cycle: " << _cycle << endl;
	cout << "Work Done is : " << _work << endl;
	_dfsAssert();
	cout << endl;
}

void GraphDfs::_dfsBuild(const string& node) {
	//cout << "in _dfs with node "<< node << endl;
	int nodeVal = _g.insertOrFind(node, true);
	if (_color[nodeVal] == "green") {
		_color[nodeVal] = "blue";
		_work++;
 		for (int i = 0; i < _g.numFanout(nodeVal); i++) {
			int fanOut = _g.getNodeFanout(nodeVal, i);
			_dfsBuild(_g.getNodeRealName(fanOut));
			_work++;
		}
		_color[nodeVal] = "red";
		//cout << node <<" ";
		_ans.push_back(node);
	}
	else if (_color[nodeVal] == "blue") {
		_cycle = true;
	}
	else if (_color[nodeVal] == "red") {
		
	}
}

void GraphDfs::_dfsAssert() {
	cout << "In DFS assert now: ";
	for (int i = 1; i <= _ans.size(); i++) {
		int nodeVal = _g.insertOrFind(_ans[_ans.size() - i], true);
		if (_g.numFanin(nodeVal) == 0) {
			_assertArr[i-1] = "true";
		}
		else {
			for (int j = 0; j < _g.numFanin(nodeVal); j++) {
				int fanin = _g.getNodeFanin(nodeVal, j);
				//cout << "Fan in is: " <
				//cout<< _g.getNodeRealName(fanin) << " ";
				if (_assertArr[fanin] == "true") {
					_assertArr[nodeVal] = "true";
				}
				else {
					_assert = false;
				}
			}
		}
	}
	for (int i = 0; i < _assertArr.size(); i++) {
		//cout << _assertArr[i] << " ";
	}
	if (_assert == true) {
		cout << "dfs assert passed" << endl;
	}
	else {
		cout << "dfs assert failed, cycle was found" << endl;
	}
	cout << endl;
}
//EOF

