#include "graph.h"

using namespace std;

graph::graph(string file_name) {
	ifstream file(file_name);
	string reader;
	getline(file, reader); //get number of vertexes
	//fill matrix
	int vertexes = stoi(reader); // << probably we dont need 'vertexes'
	matrix.resize(vertexes);
	for (auto i = matrix.begin(); i != matrix.end(); ++i) {
		(*i).resize(vertexes, 0);
	}
	all_routes_from_start_vertex.resize(vertexes, 0);
	reader.shrink_to_fit();
	getline(file, reader); //get number of routes
	int routes = stoi(reader);
	for (int route = 0; route != routes; ++route) { //go through all routes in matrix
		reader.shrink_to_fit();
		getline(file, reader);
		stringstream vertex_to_vertex(reader);
		int vertex_A, vertex_B;
		vertex_to_vertex >> vertex_A >> vertex_B;
		matrix[vertex_A][vertex_B] = matrix[vertex_B][vertex_A] = 1; //set '1' where is a route between vertexes
	}
	reader.shrink_to_fit();
	getline(file, reader);
	start_vertex = stoi(reader);
}

void graph::bfs() {
	queue<unsigned int> q;
	vector<bool> visited(matrix.size(), 0);
	all_routes_from_start_vertex[start_vertex] = 0;
	q.push(start_vertex);
	visited[start_vertex] = 1;
	while (!q.empty()) {
		int current_vertex = q.front();
		q.pop();
		for (auto i = 0; i != matrix[current_vertex].size(); ++i) { //go through all vertexes where we can go from current vertex
			if (matrix[current_vertex][i] == 1) { //if route exists
				if (!visited[i]) { //if we didnt visit this vertex
					q.push(i);
					visited[i] = true;
					all_routes_from_start_vertex[i] = all_routes_from_start_vertex[current_vertex] + 1;
				}
			}
		}
	}
}

void graph::show_dist() {
		for (auto i = all_routes_from_start_vertex.begin(); i != all_routes_from_start_vertex.end(); ++i) {
			cout << *i << endl;
		}
	}

ostream& operator << (ostream& stream, const graph& item) {
	for (auto line = item.matrix.begin(); line != item.matrix.end(); ++line) {
		for (auto item = (*line).begin(); item != (*line).end(); ++item) {
			stream << *item << ' ';
		}
		stream << endl;
	}
	return stream;
}
