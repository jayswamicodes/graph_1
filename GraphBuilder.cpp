/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
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
  GraphBuilder b(*this,s) ;

  cout << "Graph type is: " <<_type <<endl;
  if (_type == 1 || _type==2) {
	  int m = 2;
	  for (int i = 0; i < s.size(); i = i + 2) {
		  int position = insertOrFind(s[i], false);
		  position = insertOrFind(s[i + 1], false);
		  createEdge(_hm[s[i]], _hm[s[i + 1]], 0, true);
		  if (_type == 1) {
			  createEdge(_hm[s[i]], _hm[s[i + 1]], 0, false);
			  createEdge(_hm[s[i + 1]], _hm[s[i]], 0, true);
			  createEdge(_hm[s[i + 1]], _hm[s[i]], 0, false);
		  }
		  else {
			  createEdge(_hm[s[i + 1]], _hm[s[i]], 0, false);
		  }
		  //cout << "Edge : " << s[i] << " " << s[i + 1] << endl;
		  /*if (_type == 1) {
			  createEdge(_hm[s[i + 1]], _hm[s[i]], 0, true);
			  createEdge(_hm[s[i + 1]], _hm[s[i]], 0, false);
			  //cout << "Edge : " << s[i + 1] << " " << s[i] << endl;
		  }*/
	  }
  }
  if (_type == 3 || _type == 4) {
	  int m = 3;
	  for (int i = 0; i < s.size(); i = i + 3) {
		  int position = insertOrFind(s[i], false);
		  position = insertOrFind(s[i + 1], false);
		  createEdge(_hm[s[i]], _hm[s[i + 1]], string2double(s[i + 2]), true);
		  if (_type == 3) {
			  createEdge(_hm[s[i]], _hm[s[i + 1]], string2double(s[i + 2]), false);
			  createEdge(_hm[s[i + 1]], _hm[s[i]], string2double(s[i + 2]), true);
			  createEdge(_hm[s[i + 1]], _hm[s[i]], string2double(s[i + 2]), false);
		  }
		  else {
			  createEdge(_hm[s[i + 1]], _hm[s[i]], string2double(s[i + 2]), false);
		  }
		  //createEdge(_hm[s[i]], _hm[s[i + 1]], string2double(s[i + 2]), false);
		  //cout << "Edge : " << s[i] << " " << s[i + 1] << " " << s[i + 2] <<endl;
		  /*if (_type == 3) {
			  createEdge(_hm[s[i + 1]], _hm[s[i]], string2double(s[i + 2]), true);
			  createEdge(_hm[s[i + 1]], _hm[s[i]], string2double(s[i + 2]), false);
			  //cout << "Edge : " << s[i + 1] << " " << s[i] << endl;
		  }*/
	  }
  }
  cout << "Final Number of node & edges : " << _numV << " & " << _numE << endl;
}


//EOF





