#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

#include "state.hpp"
#include "application.hpp" //for assets manager and state manager in it
#include "definitions.hpp"

namespace Engine
{
    class splashState : public Engine::State
    {
    public:
        splashState(std::shared_ptr<applicationData> &data);
        ~splashState();

        void Init() override;
        void processInput() override;
        void Update(const sf::Time& deltaTime) override;
        void Draw() override;
    
    private:
        std::shared_ptr<applicationData> m_data;
        sf::Text m_gameTitle;
        sf::Sprite m_background;

        bool m_isEnterButtonPressed = false;

        //remove these if the background is the same size as the window
        float bgHeightScaler = 1, bgWidthScaler = 1;
    };
}
