/*
 * Graph.cpp
 *
 *  Created on: Nov 5, 2015
 *      Author: root
 */

#include "Graph.h"


Graph::Graph() {

	std::ifstream f("./graph.txt");
	if(!f.is_open()){
		perror("graph.txt open failed");
		exit(-1);
	}
	f >> column >> row;
	g.resize(column);
	for(int i = 0; i < column; ++i)
	{
		g[i].resize(row);
		for(int j = 0; j < row; ++j)
		{
			f >> g[i][j];
		}
	}

	int Xsrc,Ysrc,Xdst,Ydst;
	f >> Xsrc >> Ysrc >> Xdst >> Ydst;

	src.setXY(Xsrc,Ysrc);
	dst.setXY(Xdst,Ydst);

	f.close();
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

void Graph::display()
{
	for(int i = 0; i < column; ++i)
	{
		for(int j = 0; j < row; ++j)
		{
			if(i == src.getX() && j == src.getY()) std::cout << "s" << " ";
			else if(i == dst.getX() && j == dst.getY()) std::cout << "d" << " ";
			else std::cout << g[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Point Graph::getLeft(Point cur){
	if(cur.getY() - 1 >= 0){
		return Point(cur.getX(),cur.getY()-1);
	}

	throw "out of border";
}

Point Graph::getRight(Point cur){
	if(cur.getY() + 1 < getColumn()){
		return Point(cur.getX(),cur.getY()+1);
	}

	throw "out of border";
}

Point Graph::getUp(Point cur){
	if(cur.getX() - 1 >= 0){
		return Point(cur.getX()-1,cur.getY());
	}

	throw "out of border";
}

Point Graph::getDown(Point cur){
	if(cur.getX() + 1 < getRow()){
		return Point(cur.getX()+1,cur.getY());
	}

	throw "out of border";
}
