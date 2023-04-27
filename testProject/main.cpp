#include <SFML/Graphics.hpp>
#include "Test.hpp"

int main()
{
    Test test;

    test.testMove();
    test.testCapture();
    test.testEnPassant();
    test.testCastle();
    test.testPromotion();

    GraphicsChess chess;
    chess.game();
    
    return 0;
}