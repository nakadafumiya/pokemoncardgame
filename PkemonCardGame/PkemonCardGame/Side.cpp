#include "Side.h"
#include "AbstractScene.h"
#include "DxLib.h"
#include"common.h"


Side::Side()
{
	BackCard = LoadGraph("");

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
	

}