#include "PadInput.h"

char PAD_INPUT::oldKey[BUTTONS];    //前回の入力キー
char PAD_INPUT::nowKey[BUTTONS];    //今回の入力キー
PADSTATE PAD_INPUT::state = PADSTATE::NOT;
XINPUT_STATE PAD_INPUT::Input;

void PAD_INPUT::UpdateKey()
{
    // 入力キー取得
    GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);
    for (int i = 0; i < BUTTONS; i++)
    {
        oldKey[i] = nowKey[i];
        nowKey[i] = Input.Buttons[i];
    }

}
