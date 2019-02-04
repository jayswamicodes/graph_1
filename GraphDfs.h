/*----------------------------------------------------------------
file: GraphDfs.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has GraphDfs class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef GraphDfs_H
#define GraphDfs_H

#include "Graph.h"

/*----------------------------------------------------------------
Declaration of GraphDfs class
-----------------------------------------------------------------*/
class GraphDfs {
public:
	GraphDfs(Graph& g, const char* t, const string& s, bool& cycle, int& work, vector<string>& ans) : _g(g), _t(t), _s(s), _cycle(cycle), _work(work), _ans(ans) {
		_assert = true;
		_buildTopologicalOrder();
	}
	~GraphDfs() {}
	GraphDfs(const GraphDfs& from) = delete;
	GraphDfs& operator=(const GraphDfs& from) = delete;
private:
	Graph& _g;
	const char* _t;
	const string _s;
	bool _cycle;
	int _work;
	bool _assert;
	vector<string> _ans;
	vector<string> _color;
	vector<string> _assertArr;
	void _buildTopologicalOrder();
	void _dfsBuild(const string& node);
	void _dfsAssert();
};

#endif

//eof
