#pragma once
#include "TreeNode.h"
#include "Application.h"
#include "Renderer2D.h"
#include "BinaryTree.h"

class BinaryTreesApp : public aie::Application {
public:

	BinaryTreesApp();
	virtual ~BinaryTreesApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();



protected:

	aie::Renderer2D*	m_2dRenderer;
	//aie::Font*			m_font;
	BinaryTree m_binaryTree;
	TreeNode* m_selectedNode;
};