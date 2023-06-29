#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "state.hpp"

namespace Engine
{
	class inputManager
	{
		public:
			inputManager();
			~inputManager();

			void getLetterBoxView(sf::View &view, int windowWidth, int windowHeight);
			void switchFullScreen(sf::RenderWindow &window);
			bool isHover(sf::Sprite &object, sf::RenderWindow &window, const sf::Vector2i &mousePosCache);

			void pollEvent(sf::RenderWindow& window, State& topState, State& globalState);
			sf::Event m_event;

			//void onEvent();
			// bool check(unsigned x, unsigned y, int dx, int dy);
			/* 
			   void qolCheck(); */ //quality of life checks - implement this
						     //void dispatchEventToCallbacks(Even &e); 
		private:
			//friend class State;
			bool isFullScreen = 0;

			/*
			   bool onKeyPressed(KeyPressedEvent &e);
			   bool onKeyReleased(KeyReleasedEvent &e)
			   */
	};
}
