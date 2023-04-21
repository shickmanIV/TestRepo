#include "PawnGraphic.hpp"

bool PawnGraphic::isPromoted()
{
    return promoted;
}

void PawnGraphic::promote()
{
    promoted = true;
    if (isWhite) {
        setTexture(t.whiteQueen, true);
    }
    else setTexture(t.blackQueen, true);
}
