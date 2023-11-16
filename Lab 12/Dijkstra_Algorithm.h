#ifndef DIJKSTRA_ALGORITHM_H
#define DIJKSTRA_ALGORITHM_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// External Libraries
#include "Basic_Graph.h"

class Dijkstra_Algorithm
{
public:
	// Constructors
	Dijkstra_Algorithm(int);
	~Dijkstra_Algorithm();

	// Algorithm Functions
	void Start_Dijkstra(int scr);		// Source vertice

	// Get/Set Functions
	Basic_Graph* Get_Graph();

private:
	int *distance;
	bool *visited;

	Basic_Graph* graph;
};

#endif // !DIJKSTRA_ALGORITHM_H
