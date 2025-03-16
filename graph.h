#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

class graph {
	int start_vertex;
	std::vector<std::vector<unsigned short>> matrix;
	std::vector<unsigned int> all_routes_from_start_vertex;
public:
	graph(string file_name);
	void bfs();
	void show_dist();
	friend ostream& operator << (ostream& stream, const graph& item);
};

ostream& operator << (ostream& stream, const graph& item);

