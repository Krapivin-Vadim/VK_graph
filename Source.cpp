#include "graph.h"

using namespace std;

int main() {
	graph test("graph.txt");
	test.bfs();
	test.show_dist();
	return 0;
}