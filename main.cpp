/*
 * main.cpp
 *
 *  Created on: Nov 5, 2015
 *      Author: root
 */

#include <iostream>
#include "Graph.h"
#include "AStar.h"

int main(){
	Graph g;
	g.display();
	std::cout << std::endl;

	/* output src and dst point*/
	std::cout << "src: ( " << g.getSrc().getX() << ", " << g.getSrc().getY() << " )" << std::endl;
	std::cout << "dst: ( " << g.getDst().getX() << ", " << g.getDst().getY() << " )" << std::endl;
	std::cout << std::endl;

	AStar astar(g);
	astar.resolve(g.getSrc(),g.getDst());
	astar.displayPath();
	return 0;
}
