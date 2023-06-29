#pragma once

#include <stack>
#include <memory>

#include "state.hpp"

namespace Engine
{
	//typedef std::unique_ptr<State> stateRef; for easier use
	class stateManager
	{
	public:
		stateManager();
		~stateManager();

		void addState(std::unique_ptr<State> newState, bool replace = false);
		void popCurrent();
		void processStateChange();
		std::unique_ptr<State> &getCurrentState() { return m_stateStack.top(); }

		//Should be noted that I've made it assuming
		//there is only one global state at a time
		//THE NEW GLOBAL STATE WILL ALWAYS REPLACE THE 
		//PREVIOUS STATE
		void addGlobalState(std::unique_ptr<State> globalState);
		std::unique_ptr<State> &globalState() { return m_globalState; }
	private:
		std::stack<std::unique_ptr<State>> m_stateStack;
		std::unique_ptr<State> m_globalState;
		std::unique_ptr<State> m_newState;

		bool m_add;
		bool m_replace;
		bool m_remove;
	};

}
