#include <SFML/Graphics.hpp>
#include "Test.hpp"
#include "MiniGameTest.hpp"

bool TEST_MINIGAME = true;

int main()
{
    if (!TEST_MINIGAME)
    {
        Test test;

        test.testMove();
        test.testCapture();
        test.testEnPassant();
        test.testCastle();
        test.testPromotion();

        GraphicsChess chess;
        chess.game();
    }
    else //Runs only the minigame.
    {
        MiniGameTest mgTester;
        mgTester.testOpenWindow();
    }
    


    
    return 0;
}