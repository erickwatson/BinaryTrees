#include "BinaryTreesApp.h"
#include "TreeNode.h"
#include <iostream>

using namespace std;






int main() {
	
	// allocation
	auto app = new BinaryTreesApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}