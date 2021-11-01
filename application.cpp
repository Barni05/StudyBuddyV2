#include "application.h"
#include <QDebug>

Application* Application::m_Application = nullptr;;


void Application::addWord(WordStructure wordstruct)
{
	m_Words.push_back(wordstruct);
}

Application::Application()
{
}
