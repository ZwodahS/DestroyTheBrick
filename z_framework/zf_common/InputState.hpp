#ifndef _ZF_COMMON_INPUTSTATE_H_
#define _ZF_COMMON_INPUTSTATE_H_
struct InputState
{
    bool thisDown; // bool representing if this key is down this frame.
    bool lastDown;
    bool thisPressed; // bool representing if this key is pressed this frame.
    bool thisHeld; // bool representing if this key is pressed this frame and last frame.
    bool thisReleased; // bool representing if this key is released this frame.
    //thisPressed = Keystates[keycode]  && !lastDown
    //thisHeld = Keystates[keycode] && lastDown
    //thisReleased = !Keystates[keycode] && lastDown
};
#endif
