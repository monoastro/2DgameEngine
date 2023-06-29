#include "stateManager.hpp"

Engine::stateManager::stateManager() 
: 
	m_globalState(nullptr),
	m_add(false), m_replace(false), m_remove(false)
{
}

Engine::stateManager::~stateManager()
{
}

void Engine::stateManager::addState(std::unique_ptr<State> newState, bool replace)
{
	m_add = true;
	m_newState = std::move(newState);
	m_replace = replace;
}

void Engine::stateManager::popCurrent() 
{
	m_remove = true;
}

void Engine::stateManager::processStateChange()
{
	if (m_remove && (!m_stateStack.empty()))
	{
		m_stateStack.pop();

		if (!m_stateStack.empty())
		{
			m_stateStack.top()->Start();
		}

		m_remove = false;
	}

	if (m_add)
	{
		if (m_replace && (!m_stateStack.empty())) //if replace, pop top state, pause the then top state, add the new state
		{
			m_stateStack.pop();
			m_replace = false;
		}

		if (!m_stateStack.empty()) //pause the current top state if the stack is not empty
		{
			m_stateStack.top()->Pause();
		}

		/* 
		//alternative //better but it uses nested ifs
		//this assumes that the top stack that got replaced paused it's stack below when it was added
		//so it doesn't pause the second state when it gets replaced while the previous logic pauses it anyway
		if(!m_stateStack.empty()) 
		{
		if(m_replace) {m_stateStack.pop(); m_replace = false;}
		else { m_stateStack.top()->Pause(); }
		} 
		*/

		m_stateStack.push(std::move(m_newState)); //move the ownership of the new state(unique_ptr) to the top of the stack
		m_stateStack.top()->Init();
		m_stateStack.top()->Start();
		m_add = false;
	}
}

void Engine::stateManager::addGlobalState(std::unique_ptr<State> globalState)
{
	if(m_globalState != nullptr) { m_globalState.reset(); }
	m_globalState = std::move(globalState);
	m_globalState->Init();
	m_globalState->Start();
}

		


