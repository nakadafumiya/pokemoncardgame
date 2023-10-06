#include "PadInput.h"

char PAD_INPUT::oldKey[BUTTONS];    //�O��̓��̓L�[
char PAD_INPUT::nowKey[BUTTONS];    //����̓��̓L�[
PADSTATE PAD_INPUT::state = PADSTATE::NOT;
XINPUT_STATE PAD_INPUT::Input;

void PAD_INPUT::UpdateKey()
{
    // ���̓L�[�擾
    GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);
    for (int i = 0; i < BUTTONS; i++)
    {
        oldKey[i] = nowKey[i];
        nowKey[i] = Input.Buttons[i];
    }

}
