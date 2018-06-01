#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
}


BinaryTree::~BinaryTree()
{
}

void BinaryTree::insert(int a_nValue)
{
	TreeNode* newNode = new TreeNode(a_nValue);

	TreeNode* node = m_pRoot;

	while (true)
	{
		if (a_nValue < node->getData())
		{
			// check to the left
			if (node->hasLeft())
				node = node->getLeft(); // keep on looking
			else
			{
				node->setLeft(newNode); // set our place here
				return;
			}
		}
		else
		{
			// check to the right
			if (node->hasRight())
				node = node->getRight(); // keep on looking
			else
			{
				node->setRight(newNode); // set our place here
				return;
			}
		}
	}

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