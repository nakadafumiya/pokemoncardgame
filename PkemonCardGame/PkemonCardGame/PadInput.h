#pragma once
#include "DxLib.h"

#define BUTTONS 16
#define MARGIN 32767*0.25
#define TRIGGER 255*0.25

enum class PADSTATE
{
    NOT = 0,
    ON,
    DOWN
};


class PAD_INPUT
{
private:
    static char oldKey[BUTTONS];    //前回の入力キー
    static char nowKey[BUTTONS];    //今回の入力キー
    static PADSTATE state;
    static XINPUT_STATE Input;

private:
    PAD_INPUT() = default;
public:
    static void UpdateKey();
    static int GetPadThumbLX() { return Input.ThumbLX; }
    static int GetPadThumbLY() { return Input.ThumbLY; }
    static int GetPadLeftTrigger() { return Input.LeftTrigger; }
    static int GetPadRightTrigger() { return Input.RightTrigger; }
    //ボタンを押した瞬間
    static bool OnClick(int inputKey)
    {
        bool ret = (nowKey[inputKey] == 1 && oldKey[inputKey] == 0);
        return ret;
    }
    //ボタンを押してる間
    static bool OnPressed(int inputKey)
    {
        bool ret = (nowKey[inputKey] == 1);
        return ret;
    }
    //ボタンを離した瞬間
    static bool OnRelease(int inputKey)
    {
        bool ret = (oldKey[inputKey] == 1 && nowKey[inputKey] == 0);
        return ret;
    }
};
