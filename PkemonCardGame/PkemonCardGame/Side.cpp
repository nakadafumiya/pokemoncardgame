#include "Side.h"
#include "AbstractScene.h"
#include "DxLib.h"
#include"common.h"
#include"PadInput.h"

#define PI    3.1415926535897932384626433832795f

Side::Side()
{
	BackCard = LoadGraph("images/Pokemon_Card_D1/CardBack.png");


	for (count = 0; count <= 5; ++count)
	{
		side[count];
	}

	/*todo*/
	for (int i = 0; i < 6; i++)
	{
		side[i] = -1;
	}
	count = 0;
	//�����܂�
}
//�����o�ϐ��̒l������������̂��A�b�v�f�[�g�֐�
//AbstractScene* Side::Update()
//{
//	if (PAD_INPUT::OnClick(XINPUT_BUTTON_Y))
//	{
//		count--;
//	}
//	return 0;
//}

//�`�揈���݂̂��s���֐�
void Side::Draw() const
{
	//player �T�C�h

	//DrawFormatString(0,0,0x000000,"%d",count);
	
	if (0 < count)
	{
		DrawRotaGraph(470, 959, 1, 0, BackCard, FALSE);//����
	}
	if (1 < count)
	{
		DrawRotaGraph(470, 799, 1, 0, BackCard, FALSE);//����
	}
	if (2 < count)
	{
		DrawRotaGraph(470, 639, 1, 0, BackCard, FALSE);//����
	}
	if (3 < count)
	{
		DrawRotaGraph(495, 935, 1, 0, BackCard, FALSE);//��O��
	}
	if (4 < count) 
	{
		DrawRotaGraph(495, 775, 1, 0, BackCard, FALSE);//��O��
	}
	if (5 < count) 
	{
		DrawRotaGraph(495, 615, 1, 0, BackCard, FALSE);//��O��
	}
	

	//�G�@�T�C�h
	DrawRotaGraph(1460, 420, 1, PI, BackCard, FALSE);//����
	DrawRotaGraph(1460, 260, 1, PI, BackCard, FALSE);//����
	DrawRotaGraph(1460, 100, 1, PI, BackCard, FALSE);//����

	DrawRotaGraph(1435, 453, 1, PI, BackCard, FALSE);//��O��
	DrawRotaGraph(1435, 293, 1, PI, BackCard, FALSE);//��O��
	DrawRotaGraph(1435, 133, 1, PI, BackCard, FALSE);//��O��
}