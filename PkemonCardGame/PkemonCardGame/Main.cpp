#include "DxLib.h"
#include "common.h"
#include "SceneManager.h"
#include "PadInput.h"
#include "Pokemon.h"
#include "GameMainScene.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    SetMainWindowText("Pokemon Card Game");  //�^�C�g���ݒ�
    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_BIT_16);

    ChangeWindowMode(TRUE);		//�E�B���h�E���[�h�ŋN��
    SetWindowIconID(01);

    if (DxLib_Init() == -1) return -1;	//DX���C�u�����̏���������

    SetDrawScreen(DX_SCREEN_BACK);  //�`����ʂ𗠂ɂ���

    SetFontSize(20);  //�����T�C�Y��ݒ�

    SceneManager sceneMng((AbstractScene*)new GameMainScene() );

  

    //�Q�[�����[�v
    while (ProcessMessage() == 0 && sceneMng.Update() != nullptr)
    {
        ClearDrawScreen();  //��ʂ̏�����

        sceneMng.Draw();

     
       

        ScreenFlip();  //����ʂ̔|�{��\��ʂɔ��f

        PAD_INPUT::UpdateKey();

      
    }

    DxLib_End();  //DX���C�u�����g�p�̏I������

    return 0;
}