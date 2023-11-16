#include "Dijkstra_Algorithm.h"

Dijkstra_Algorithm::Dijkstra_Algorithm(int vertices)
{ 
	graph = new Basic_Graph(vertices); 
	distance = new int[vertices];
	visited = new bool[vertices];
}

Dijkstra_Algorithm::~Dijkstra_Algorithm()
{
	delete[] distance;
	delete[] visited;
}

void Dijkstra_Algorithm::Start_Dijkstra(int src)
{
	// Get Calls
	int vertices = graph->Get_Vertices();
	int** matrix = graph->Get_Matrix();

	// Required Variables
	int infinity = std::numeric_limits<int>::max(); // Closest possible to infinity
	int distance_min = infinity, index_min = -1;

	// Shortest Path Variables
	std::vector<int> path(vertices, -1);

	// Initalization
	for (int i = 0; i < vertices; i++)
	{
		distance[i] = infinity;
		visited[i] = false;
	}

	// Clear source
	distance[src - 1] = 0;								// Distance to self

	// Algorithm
	for (int i = 0; i < vertices - 1; i++)				// Src not included
	{
		distance_min = infinity;
		index_min = -1;

		for (int j = 0; j < vertices; j++)
		{
			if (!visited[j] && distance[j] < distance_min)
			{
				distance_min = distance[j];
				index_min = j;
			}
		}

		visited[index_min] = true;

		for (int j = 0; j < vertices; j++)
		{
			if (!visited[j] && matrix[index_min][j] != 0 && distance[index_min] != infinity && distance[index_min] + matrix[index_min][j] < distance[j])
			{
				distance[j] = distance[index_min] + matrix[index_min][j];
				path[j] = index_min;
			}
		}
	}

	// Print the calculated distances and paths
	std::cout << "Shortest paths from source " << src << ":" << std::endl;
	for (int i = 0; i < vertices; ++i)
	{
		std::cout << "To vertex " << i + 1 << ": Distance = " << distance[i] << ", Path = ";
		int current = i;
		while (current != -1)
		{
			std::cout << current + 1 << " ";
			current = path[current];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

Basic_Graph* Dijkstra_Algorithm::Get_Graph()
{ return graph; }
