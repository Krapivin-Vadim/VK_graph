#include "graph.h"

using namespace std;

int main() {
	graph test("C:/Users/krapi/source/repos/vk_contest/vk_contest/graph.txt");
	test.bfs();
	test.show_dist();
	return 0;
}