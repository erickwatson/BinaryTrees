#include "BinaryTreesApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "BinaryTree.h"
#include <imgui.h>

aie::Font* g_systemFont = nullptr;


BinaryTreesApp::BinaryTreesApp() {

}

BinaryTreesApp::~BinaryTreesApp() {

}

bool BinaryTreesApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	g_systemFont = new aie::Font("./bin/font/consolas.ttf", 32);
	//m_font = g_systemFont;
	BinaryTree* bTree;

	int value;
	TreeNode *node, *nodeParent;



	return true;
}

void BinaryTreesApp::shutdown() {

	delete g_systemFont;
	delete m_2dRenderer;
}

void BinaryTreesApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	static int value = 0;
	ImGui::InputInt("Value", &value);
	
	if (ImGui::Button("Insert", ImVec2(50, 0)))
	{
		m_binaryTree.insert(value);
		m_selectedNode = m_binaryTree.find(value);
	}

	if (ImGui::Button("Remove", ImVec2(50, 0)))
	{
		m_binaryTree.remove(value);
	}

	if (ImGui::Button("Find", ImVec2(50, 0)))
	{
		m_selectedNode = m_binaryTree.find(value);
	}
	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void BinaryTreesApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_binaryTree.draw(m_2dRenderer, m_selectedNode);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(g_systemFont, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}