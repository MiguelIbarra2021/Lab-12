#ifndef BASIC_GRAPH_H
#define BASIC_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Vertex
{
	int data;
};

class Basic_Graph
{
	public:
		// Constructors
		Basic_Graph();
		Basic_Graph(int);

		~Basic_Graph();

		// General Functions
		void Add_Edge(int scr, int dest, int weight);

		// Set/Get Functions
		int Get_Vertices();
		int **Get_Matrix();

		// Display Functions
		void Display_Matrix();

	private:
		int vertices;
		int **adj_matrix;

};

#endif // !BASIC_GRAPH_H
