#include "Basic_Graph.h"

Basic_Graph::Basic_Graph()
{ 
	vertices = 0;
	adj_matrix = nullptr; 
}

Basic_Graph::Basic_Graph(int a_vertices)
{
	// Record vertice info
	vertices = a_vertices;
	adj_matrix = new int*[vertices];

	// Initalize Basic_Graph
	for (int i = 0; i < vertices; i++)
	{
		adj_matrix[i] = new int[vertices];

		for (int j = 0; j < vertices; j++)
		{
			adj_matrix[i][j] = 0;
		}
	}
}

Basic_Graph::~Basic_Graph()
{
	for (int i = 0; i < vertices; i++) 
	{
		delete[] adj_matrix[i];
	}

	delete[] adj_matrix;
}

void Basic_Graph::Add_Edge(int scr, int dest, int weight)
{
	adj_matrix[scr - 1][dest - 1] = weight;
	adj_matrix[dest - 1][scr - 1] = weight;
}

int Basic_Graph::Get_Vertices()
{ return vertices; }

int** Basic_Graph::Get_Matrix()
{ return adj_matrix; }

void Basic_Graph::Display_Matrix()								// Prints Full Matrix
{
	std::cout << "Adjacency Matrix:" << std::endl;
	std::cout << "     ";

	for (int i = 0; i < vertices; i++)
	{
		std::cout << "_" << i + 1 << " ";
	}

	std::cout << std::endl << "    ";

	for (int i = 0; i < vertices; i++)
	{
		std::cout << "---";
	}

	std::cout << std::endl;

	for (int i = 0; i < vertices; i++)
	{
		std::cout << "_" << i + 1 << " | ";

		for (int j = 0; j < vertices; j++)
		{
			if(adj_matrix[i][j] < 10)
				std::cout << "_" << adj_matrix[i][j] << " ";
			else
				std::cout << adj_matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}