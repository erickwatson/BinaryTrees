#include "BinaryTree.h"

// (predicate) ? (action if true) : (action if false)
// currentNode = (a_nValue < currentNode->getData()) ? currentNode->getLeft() : currentNode->getRight();

BinaryTree::BinaryTree()
{
}


BinaryTree::~BinaryTree()
{
}

void BinaryTree::insert(int a_nValue)
{
	TreeNode* newNode = new TreeNode(a_nValue);


	// If the tree is empty, the value is inserted at the root (and STOP)
	if (m_pRoot == nullptr) {
		m_pRoot = newNode;
		return;
	}


	TreeNode *currentNode = m_pRoot;


	while (currentNode != nullptr)
	{
		if (a_nValue == currentNode->getData()) // Already exists, so exit
			return;

		if (a_nValue < currentNode->getData())
		{
			// check to the left
			if (currentNode->hasLeft())
				currentNode = currentNode->getLeft(); // keep on looking
			else
			{
				// if Left node is null
				currentNode->setLeft(newNode); // set our place here
				return;
			}
		}
		else
		{
			// check to the right
			if (currentNode->hasRight())
				currentNode = currentNode->getRight(); // keep on looking
			else
			{
				// if Right node is null
				currentNode->setRight(newNode); // set our place here
				return;
			}
		}
	}
}

// TreeNode** is a pointer to a TreeNode pointer, (or  (TreeNode*)* )
bool BinaryTree::findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent) {

	// pointer lastNode becomes null
	TreeNode* lastNode = nullptr;

	// pointer currentNode becomes root
	TreeNode* currentNode = m_pRoot;

	// while currentNode isn't null
	while (currentNode != nullptr)
	{
		// take the searchvalue input and check if it's equal to getData
		if (a_nSearchValue == currentNode->getData()) { // Already exists, so exit
			// (Go to allocated memory referenced by ppOutNode) and set set value within to be same as currentNode
			(*ppOutNode) = currentNode;

			// (Go to allocated memory referenced by ppOutParent) and set set value within to be same as lastNode
			(*ppOutParent) = lastNode;
			return true;
		}

		// Else Move down tree
		lastNode = currentNode;

		if (a_nSearchValue < currentNode->getData())
			currentNode = currentNode->getLeft(); 
		else
			currentNode = currentNode->getRight(); 
		
	}

	return false;
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* selected)
{
	draw(renderer, m_pRoot, 640, 680, 640, selected);

}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* pNode, int x, int y,
	int horizontalSpacing, TreeNode* selected)
{
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->hasLeft()) {
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing,
				y - 80, horizontalSpacing, selected);
		}

		if (pNode->hasRight()) {
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing,
				y - 80, horizontalSpacing, selected);
		}

		pNode->draw(renderer, x, y, (selected == pNode));
	}
}