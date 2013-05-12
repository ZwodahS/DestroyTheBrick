#include "f_inputs.hpp"

namespace zf_inputs
{
    void processKey(InputState &inputState, bool newState)
    {
        inputState.lastDown = inputState.thisDown;
        inputState.thisDown = newState;
        inputState.thisPressed = inputState.thisDown && !(inputState.lastDown) ;
        inputState.thisHeld = inputState.thisDown && inputState.lastDown;
        inputState.thisReleased = !inputState.thisDown && inputState.lastDown;
    }
}

