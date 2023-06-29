#pragma once

//default values 
#define WIDTH 1920 
#define HEIGHT 1080

//ALERT: The max height one can work with in sfml is Height = totalScreenHeight - height of titleBar - height of taskbar
//Outside of fullScreenMode sfml can't make a window of height greater than the Height* from the (top + height of titleBar to the task bar) 
//The total window will occupy a larger height that the above Height* because of the titleBar 

//for height generalization 
//#define HEIGHT sf::VideoMode::getFullscreenModes()[0].height - taskBarHeight(varies from OS to OS)
//sfml does automatically reajust the window height so there's not necessarily a need to subtract these values
// but keep this in mind when making the backgrounds and things for your game.

#define fullscreen 0
#define Title "capybara"
#define transitionTime 3

//define all assets and their path here
#define fontPATH "resources/fonts/Hack.ttf"

#define hack_ttfPATH "resources/fonts/Hack.ttf"
#define arialPATH "resources/fonts/arial.ttf"
#define verdanaPATH "resources/fonts/verdana.ttf"
#define fontSize 18.5f

#define splashScreenPATH "resources/img/splashBackground.png"

enum assetIDs
{
    mainFONT = 0,
    splashSCREEN  = 1 //other assets definitons here etc
};

#define splashScreenHeight 1080
#define splashScreenWidth 1920 

