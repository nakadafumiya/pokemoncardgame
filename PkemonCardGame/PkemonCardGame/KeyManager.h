#pragma once
#include"DxLib.h"

class KeyManager
{
private:
    static char oldKey[256];    //�O��̓��̓L�[
    static char nowKey[256];    //����̓��̓L�[
private:
    KeyManager() = default;


public:
    static void Update()
    {
        for (int i = 0; i < 256; i++)
        {
            oldKey[i] = nowKey[i];
        }
        //nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
        if (GetHitKeyStateAll(nowKey) == 1)
        {
            throw - 1;//�G���[���o���ꍇ�A�I��
        }
    }
    //�{�^�����������u��
    static bool OnClick(int inputKey)
    {
        bool ret = (nowKey[inputKey] == 1 && oldKey[inputKey] == 0);
        return ret;
    }
    //�{�^���������Ă��
    static bool OnPressed(int inputKey)
    {
        bool ret = (nowKey[inputKey] == 1);
        return ret;
    }
    //�{�^���𗣂����u��
    static bool OnRelease(int inputKey)
    {
        bool ret = (oldKey[inputKey] == 1 && nowKey[inputKey] == 0);
        return ret;
    }
};
