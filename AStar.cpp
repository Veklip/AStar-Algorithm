/*
 * AStar.cpp
 *
 *  Created on: Nov 5, 2015
 *      Author: root
 */

#include "AStar.h"

AStar::AStar(Graph g) {
	this->g = g;

}

AStar::~AStar() {
	// TODO Auto-generated destructor stub
}

void AStar::updateOpenList(Point newPoint,Point p){
	if(find(close.begin(), close.end(), newPoint) != close.end())
		return; //do nothing

	if(g.ok(newPoint) && find(open.begin(), open.end(), newPoint) == open.end()){
		newPoint.setGscore(1 + p.gScore);
		newPoint.setFscore(newPoint.gScore + calcH(newPoint,g.getSrc(),g.getDst()));
		open.push_back(newPoint);

		parent[std::make_pair(newPoint.x,newPoint.y)] = std::make_pair(p.x,p.y);
	}
	else if(g.ok(newPoint) && p.gScore + 1 < newPoint.gScore){
		newPoint.gScore = p.gScore + 1;
		newPoint.fScore = newPoint.gScore + calcH(newPoint,g.getSrc(),g.getDst());
		parent[std::make_pair(newPoint.x,newPoint.y)] = std::make_pair(p.x,p.y);
	}
}

void AStar::checkNeighber(Point p){
	//check left direction
	try{
		Point newPoint = g.getLeft(p);
		updateOpenList(newPoint,p);
	}catch(...){}


	//check right direction
	try{
		Point newPoint = g.getRight(p);
		updateOpenList(newPoint,p);
	}catch(...){}


	//check up direction
	try{
		Point newPoint = g.getUp(p);
		updateOpenList(newPoint,p);
	}catch(...){}

	//check down direction
	try{
		Point newPoint = g.getDown(p);
		updateOpenList(newPoint,p);
	}catch(...){}
}


void AStar::resolve(Point src,Point dst){
	src.setGscore(0);
	src.setFscore(calcH(src,src,dst) + 0);
	open.push_back(src);

	while(!open.empty()){
		Point min_f_elem;
		for(int i=0;i<open.size();++i){
			if(i == 0 || min_f_elem.fScore > open[i].fScore){
				min_f_elem=open[i];
			}

		}

		std::cout <<"min elem"<< "(" << min_f_elem.getX() << "," << min_f_elem.getY()  << ")" << std::endl;

		if(min_f_elem.getX() == g.getDst().getX() && min_f_elem.getY() == g.getDst().getY())
		{
			std::cout << "hit!!!" << std::endl;
			reconstructPath(std::make_pair(dst.x,dst.y));
			break;
		}



		open.erase(find(open.begin(), open.end(), min_f_elem));
		close.push_back(min_f_elem);

		checkNeighber(min_f_elem);


	}
}

int AStar::calcF(Point cur,Point src,Point dst){
	return calcG(cur,src,dst)+calcH(cur,src,dst);
}


int AStar::calcG(Point cur,Point src,Point dst){
	return abs(cur.getX() - src.getX()) + abs(cur.getY() - src.getY());
}

int AStar::calcH(Point cur,Point src,Point dst){
	return abs(cur.getX() - dst.getX()) + abs(cur.getY() - dst.getY());
}

void AStar::displayPath(){
	for(int i=0;i<path.size();++i)
	{
		std::cout << "(" << path[i].first << "," << path[i].second  << ")" << std::endl;
	}
}


void AStar::reconstructPath(point_t currentNode){

	if(parent.find(currentNode) != parent.end())
	{
		path.insert(path.begin(),currentNode);
		reconstructPath(parent[currentNode]);
	}
}
