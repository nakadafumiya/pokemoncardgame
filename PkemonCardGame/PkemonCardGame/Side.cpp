#include "Side.h"
#include "AbstractScene.h"
#include "DxLib.h"
#include"common.h"
#define PI    3.1415926535897932384626433832795f

Side::Side()
{
	BackCard = LoadGraph("images/Pokemon_Card_D1/CardBack.png");




	for (count = 1; count <= 6; ++count)
	{
		side[count];
	}
}
//�����o�ϐ��̒l������������̂��A�b�v�f�[�g�֐�
AbstractScene* Side::Update()
{





	return 0;
}

//�`�揈���݂̂��s���֐�
void Side::Draw() const
{
	//player �T�C�h
	
	DrawRotaGraph(470, 639, 1, 0, BackCard, FALSE);//����
	DrawRotaGraph(495, 615, 1, 0, BackCard, FALSE);//��O��

	DrawRotaGraph(470, 799, 1, 0, BackCard, FALSE);//����
	DrawRotaGraph(495, 775, 1, 0, BackCard, FALSE);//��O��

	DrawRotaGraph(470, 959, 1, 0, BackCard, FALSE);//����
	DrawRotaGraph(495, 935, 1, 0, BackCard, FALSE);//��O��


	//�G�@�T�C�h
	DrawRotaGraph(1460, 420, 1, PI, BackCard, FALSE);//����
	DrawRotaGraph(1435, 453, 1, PI, BackCard, FALSE);//��O��

	DrawRotaGraph(1460, 260, 1, PI, BackCard, FALSE);//����
	DrawRotaGraph(1435, 293, 1, PI, BackCard, FALSE);//��O��

	DrawRotaGraph(1460, 100, 1, PI, BackCard, FALSE);//����
	DrawRotaGraph(1435, 133, 1, PI, BackCard, FALSE);//��O��
}