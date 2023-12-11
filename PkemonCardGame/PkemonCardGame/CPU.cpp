#include "CPU.h"
#define PI    3.1415926535897932384626433832795f

CPU::CPU()
{
	DeckType = 0;
	CardBack = LoadGraph("images/Pokemon_Card_D2/CardBack.png");
	BattleField = -1;
	tCount = 0;

	for (int i = 0; i < 19; i++)
	{
		poke_data[i] = poke.GetPokeID2(i);
	}
	for (int i = 0; i < 60; i++)
	{
		Trash[i] = -1;
	}
}

void CPU::Update()
{
}

void CPU::Draw()const
{
	//DrawString(1100, 680, "��D", 0xffffff);
	//for (int i = 0; i < 6; i++) //HandNum
	//{
	//	DrawFormatString(500 + 25 * i, 100, 0xffffff, "%d", GetSide(i));//hand[i]
	//}

	//�R�D
	if (CheckCard()) //�R�D�ɃJ�[�h��1���ł����݂��鎞�`�悷��
	{
		DrawRotaGraph(479, 275, 1, PI, CardBack, FALSE);
	}
	//�g���b�V��
	if (Trash[0] != -1) //�g���b�V���ɃJ�[�h��1���ł����݂��鎞�`�悷��
	{
		DrawRotaGraph(479, 105, 1, PI, CardBack, FALSE);
	}
	//�T�C�h
	if (1 < count)
	{
		DrawRotaGraph(1460, 420, 1, PI, CardBack, FALSE);//����
	}
	if (2 < count)
	{
		DrawRotaGraph(1460, 260, 1, PI, CardBack, FALSE);//����
	}
	if (3 < count)
	{
		DrawRotaGraph(1460, 100, 1, PI, CardBack, FALSE);//����
	}
	if (4 < count)
	{
		DrawRotaGraph(1435, 453, 1, PI, CardBack, FALSE);//��O��
	}
	if (5 < count)
	{
		DrawRotaGraph(1435, 293, 1, PI, CardBack, FALSE);//��O��
	}
	if (6 <= count)
	{
		DrawRotaGraph(1435, 133, 1, PI, CardBack, FALSE);//��O��
	}
	//��D
	for (int i = 0; i < HandNum; i++)
	{
		if (hand[i] != -1)
		{
			DrawRotaGraph(1100 + i * Push_X, 0, 1.0, PI, CardBack, TRUE);
		}
	}

	
}
