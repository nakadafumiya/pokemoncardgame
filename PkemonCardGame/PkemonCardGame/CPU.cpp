#include "CPU.h"
#define PI    3.1415926535897932384626433832795f

CPU::CPU()
{
	DeckType = 1;
	Battle = -1;
	tCount = 0;
	EndFirstDraw = false;
	EndSet = false;

	for (int i = 0; i < 19; i++)
	{
		poke_data[i] = poke.GetPokeID2(i);
	}
	for (int i = 0; i < 60; i++)
	{
		Trash[i] = -1;
	}
	for (int i = 0; i < 5; i++)
	{
		Bench[i] = -1;
	}

	LoadImages();
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
	//�o�g���t�B�[���h
	BattleFieldDraw();
	//�x���`
	for (int i = 0; i < 5; i++)
	{
		if (Bench[i] != -1)
		{
			switch (DetermineCard(Bench[i], DeckType))
			{
			case 0:  //�A���Z�E�X
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[1], FALSE);
				break;
			case 1:  //���b�N�E�U
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[3], FALSE);
				break;
			case 2:  //�}�t�H�N�V�[
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[4], FALSE);
				break;
			case 3:  //�l�I�����g
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[5], FALSE);
				break;
			case 4:  //�J���{�E
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[6], FALSE);
				break;
			case 5:  //�o�P�b�`��
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[8], FALSE);
				break;
			case 6:  //�z�V�K���X
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[9], FALSE);
				break;
			case 7:  //�q�[�h����
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[10], FALSE);
				break;
			case 8:  //�G�l���M�[
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[12], FALSE);
				break;
			}
		}
	}

	DrawString(1100, 150, "CPU ��D", 0xffffff);
	for (int i = 0; i < HandNum; i++)//6
	{
		DrawFormatString(1100 + 25 * i, 300, 0xffffff, "%d", hand[i]); //GetSide(i)
	}
	DrawFormatString(1100 + 25, 400, 0xffffff, "BattleField %d", Battle);
}

void CPU::LoadImages()
{
	const char* card[] = { "images/Pokemon_Card_D2/Arceus_VSTAR.png","images/Pokemon_Card_D2/Arceus_V.png","images/Pokemon_Card_D2/Rayquaza_VMAX.png","images/Pokemon_Card_D2/Rayquaza_V.png"
			,"images/Pokemon_Card_D2/Delphox_V.png","images/Pokemon_Card_D2/Lumineon_V.png","images/Pokemon_Card_D2/Charcadet.png","images/Pokemon_Card_D2/Armarouge.png"
			,"images/Pokemon_Card_D2/Pumpkaboo.png","images/Pokemon_Card_D2/Skwovet.png","images/Pokemon_Card_D2/ShiningHeatran.png","images/Pokemon_Card_D2/FireEnergy .png","images/Pokemon_Card_D2/LightningEnergy.png"
			,"images/Pokemon_Card_D2/DoubleTurboEnergy.png","images/Pokemon_Card_D2/MagmaBasin.png","images/Pokemon_Card_D2/NestBall.png","images/Pokemon_Card_D2/UltraBall.png","images/Pokemon_Card_D2/CaptureAroma.png"
			,"images/Pokemon_Card_D2/BattleVIPPath.png","images/Pokemon_Card_D2/Switch.png","images/Pokemon_Card_D2/PalPad.png","images/Pokemon_Card_D2/ChoiceBelt.png","images/Pokemon_Card_D2/ProfessorsResearch_Sada.png"
			,"images/Pokemon_Card_D2/BosssOrders_GCis.png","images/Pokemon_Card_D2/Serena.png","images/Pokemon_Card_D2/Raihan.png","images/Pokemon_Card_D2/Judge.png" };

	for (int i = 0; i < 27; i++)
	{
		cardImg[i] = LoadGraph(card[i]);
	}

	CardBack = LoadGraph("images/Pokemon_Card_D2/CardBack.png");
}

void CPU::SetBattleField()
{
	for (int i = 0; i < HandNum; i++)
	{
		if (hand[i] < 13)
		{
			SetTrashPosition(i);
			Battle = hand[i];
			TrashHand();
			break;
		}
	}
}

void CPU::SetBench()
{
	for (int i = 0; i < HandNum; i++)
	{
		if (hand[i] < 13)
		{
			SetTrashPosition(i);
			Bench[i] = hand[i];
			TrashHand(); //��D���g���b�V������
			if (Bench[4] != -1) break; //�x���`�����܂����甲����
		}
	}
}

void CPU::BattleFieldDraw() const
{
	if (Battle != -1)
	{
		switch (DetermineCard(Battle, DeckType))
		{
		case 0:  //�A���Z�E�X
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[1], FALSE);
			break;
		case 1:  //���b�N�E�U
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[3], FALSE);
			break;
		case 2:  //�}�t�H�N�V�[
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[4], FALSE);
			break;
		case 3:  //�l�I�����g
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[5], FALSE);
			break;
		case 4:  //�J���{�E
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[6], FALSE);
			break;
		case 5:  //�o�P�b�`��
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[8], FALSE);
			break;
		case 6:  //�z�V�K���X
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[9], FALSE);
			break;
		case 7:  //�q�[�h����
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[10], FALSE);
			break;
		case 8:  //�G�l���M�[
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[12], FALSE);
			break;
		}
	}
}

int CPU::DetermineCard(int card_id, int dtype) const
{
	//�f�b�L�^�C�v��1�̎�
	if (dtype == 1)
	{
		if (strcmp(poke_data[card_id].NAME, "aruseusu") == 0
			|| strcmp(poke_data[card_id].NAME, "\naruseusu") == 0) //�A���Z�E�X
		{
			return 0;
		}
		if (strcmp(poke_data[card_id].NAME, "\nrekkuza") == 0) //���b�N�E�U
		{
			return 1;
		}
		if (strcmp(poke_data[card_id].NAME, "\nmafokushi") == 0)//�}�t�H�N�V�[
		{
			return 2;
		}
		if (strcmp(poke_data[card_id].NAME, "\nneoranto") == 0)//�l�I�����g
		{
			return 3;
		}
		if (strcmp(poke_data[card_id].NAME, "\nkarubou") == 0)//�J���{�E
		{
			return 4;
		}
		if (strcmp(poke_data[card_id].NAME, "\nbakettya") == 0)//�o�P�b�`��
		{
			return 5;
		}
		if (strcmp(poke_data[card_id].NAME, "\nhosigarisu") == 0)//�z�V�K���X
		{
			return 6;
		}
		if (strcmp(poke_data[card_id].NAME, "\nhi-doran") == 0)//�q�[�h����
		{
			return 7;
		}
		return 8;//�G�l���M�[

		//if (card_id <= 3) //������
		//{
		//	return 0;
		//}
		//if (card_id <= 7) //�����g�X
		//{
		//	return 1;
		//}
		//if (card_id == 8)//�f�B�A���V�[
		//{
		//	return 2;
		//}
		//if (card_id == 9)//�Q�b�R�E�K
		//{
		//	return 3;
		//}
		//if (card_id <= 22)//�G�l���M�[
		//{
		//	return 4;
		//}

		///*�|�P����*/
		//if (card_id <= 3) //������
		//{
		//	return 0;
		//}
		//if (card_id <= 7) //������VMAX
		//{
		//	return 1;
		//}
		//if (card_id <= 11)//�����g�X
		//{
		//	return 2;
		//}
		//if (card_id <= 14)//�L�����A
		//{
		//	return 3;
		//}
		//if (card_id <= 16)//�T�[�i�C�g
		//{
		//	return 4;
		//}
		//if (card_id == 17)//�f�B�A���V�[
		//{
		//	return 5;
		//}
		//if (card_id == 18)//�Q�b�R�E�K
		//{
		//	return 6;
		//}
		//if (card_id <= 31)//���G�l���M�[
		//{
		//	return 7;
		//}
	}
	return -1;
}
