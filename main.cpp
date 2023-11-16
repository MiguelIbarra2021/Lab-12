#include "Dijkstra_Algorithm.h"

int main()
{
	Dijkstra_Algorithm da(5); // 5 for 5 vertices

	// Step 3 Example
	da.Get_Graph()->Add_Edge(1, 4, 5);
	da.Get_Graph()->Add_Edge(1, 2, 2);
	da.Get_Graph()->Add_Edge(2, 3, 14);
	da.Get_Graph()->Add_Edge(2, 4, 5);
	da.Get_Graph()->Add_Edge(2, 5, 4);
	da.Get_Graph()->Add_Edge(3, 5, 34);
	da.Get_Graph()->Add_Edge(4, 5, 58);

	// Display in console
	da.Get_Graph()->Display_Matrix();

	// Start
	da.Start_Dijkstra(1);
	da.Start_Dijkstra(2);
	da.Start_Dijkstra(3);
	da.Start_Dijkstra(4);
	da.Start_Dijkstra(5);

	return 0;
}