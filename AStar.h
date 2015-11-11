/*
 * AStar.h
 *
 *  Created on: Nov 5, 2015
 *      Author: root
 */

#ifndef ASTAR_H_
#define ASTAR_H_

#include <iostream>
#include <algorithm>
#include <map>
#include <cstdlib>
#include "Graph.h"

class AStar {
public:
	AStar(Graph);
	~AStar();
	void displayPath();
	void reconstructPath(point_t dst);
	void resolve(Point src,Point dst);
private:
	void checkNeighber(Point p);
	void updateOpenList(Point newpoint,Point partern);
	int calcF(Point cur,Point src,Point dst);
	int calcG(Point cur,Point src,Point dst);
	int calcH(Point cur,Point src,Point dst);
private:
	Graph g;
	std::vector< Point > open;
	std::vector< Point > close;
	std::map<point_t , point_t> parent;  //key:a point  value: father of a point
	/* reslove path  */
	std::vector< point_t > path;
};

#endif /* ASTAR_H_ */
