/*
 * Graph.h
 *
 *  Created on: Nov 5, 2015
 *      Author: root
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>

#define point_t std::pair<int,int>

struct Point{
	int x;
	int y;
	int fScore;
	int gScore;
	int hScore;  //not yet used
	point_t xy;  //pair

	Point(){}

	Point(int x,int y){
		setXY(x,y);
		xy.first=x;
		xy.second=y;
	}
	void setXY(int x,int y){
		this->x = x;
		this->y = y;
	}

	int getX(){return x;}
	int getY(){return y;}

	void setFscore(int val){this->fScore=val;}
	void setGscore(int val){this->gScore=val;}
	void setHscore(int val){this->hScore=val;}

	/* std::find required an equal operator*/
	bool operator==(const Point& a){
		return (x == a.x && y == a.y);
	}

	/* std::map required an less operator*/
	bool operator<(const Point& a) const{
		if(x < a.x && y < a.y) return true;
		else return false;
	}

};


class Graph {
public:
	Graph();
	~Graph();
	Point getSrc(){return src;}
	Point getDst(){return dst;}

	/* check whether this grid is obstacle*/
	bool ok(Point p){return !g[p.getX()][p.getY()];}
	int getColumn(){return column;}
	int getRow(){return row;}
	void display();
	Point getLeft(Point cur);
	Point getRight(Point cur);
	Point getUp(Point cur);
	Point getDown(Point cur);
private:
	std::vector< std::vector<int> > g;
	int column, row;
	Point src;
	Point dst;
};

#endif /* GRAPH_H_ */
