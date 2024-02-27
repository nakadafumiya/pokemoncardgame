#include "CPU.h"
#define PI    3.1415926535897932384626433832795f

CPU::CPU()
{
	DeckType = 1;
	Battle = -1;
	tCount = 0;
	Turn = START;
	EndFirstDraw = false;
	EndFirstSet = false;
	EndSetSide = false;
	EndStartDraw = false;

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
	HandDraw();

	//�X�^�[�g�̎��̓J�[�h�𗠂ɂ���
	if (Turn == START)
	{
		//�o�g���t�B�[���h
		DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, CardBack, FALSE);
		//�x���`
		for (int i = 0; i < 5; i++)
		{
			if (Bench[i] != -1)
			{
				DrawRotaGraph(1200 + i * 140, 100, 1, PI, CardBack, FALSE);
			}
		}
	}
	else
	{
		//�o�g���t�B�[���h
		BattleFieldDraw();
		//�x���`
		BenchDraw();
	}

#ifndef DEBUG
	if (Battle != -1)
	{
		DrawFormatString(SCREEN_WIDTH / 2 - 70, 80, 0xff0000, "%s", poke_data[Battle].NAME);
		DrawFormatString(SCREEN_WIDTH / 2 - 70, 90, 0xff0000, "HP %d", poke_data[Battle].HP);
	}

	DrawString(1100, 150, "CPU ��D", 0xffff00);
	for (int i = 0; i < HandNum; i++)//6
	{
		DrawFormatString(1100 + 25 * i, 180, 0xffff00, "%d", hand[i]);
	}
	DrawFormatString(1100 + 25, 220, 0xffff00, "BattleField %d", Battle);

	DrawString(1300, 150, "CPU �x���`", 0xffff00);
	for (int i = 0; i < 5; i++)
	{
		DrawFormatString(1300 + 25 * i, 180, 0xffff00, "%d", Bench[i]);
	}
#endif
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
	//�Q�[���J�n�O�ɃJ�[�h��u���I����Ă��Ȃ���
	if (!EndFirstSet)
	{
		//��D�̂��˂��o�g���t�B�[���h�ɓ����
		for (int i = 0; i < HandNum; i++)
		{
			if (DetermineCard(hand[i], DeckType) <= 7)
			{
				SetTrashPosition(i);  //�폜�ʒu��ݒ�
				Battle = hand[i];
				TrashHand();		  //��D���폜
				break;
			}
		}
	}
}

void CPU::SetBench()
{
	//���˂��x���`�ɓ����Ă��Ȃ���
	for (int b = 0; b < 5; b++)
	{
		if (Bench[b] != -1) continue;

		//���˂��x���`�ɓ����
		for (int h = 0; h < HandNum; h++)
		{
			if (DetermineCard(hand[h], DeckType) <= 7)
			{
				SetTrashPosition(h);  //�폜�ʒu��ݒ�
				Bench[b] = hand[h];
				TrashHand();		  //��D���폜
				break;
			}
		}
	}
}

//��D��7������
void CPU::FirstDraw()
{
	//�ꖇ�������Ă��Ȃ���7����D�ɉ�����
	if (GetHand(0) == -1)
	{
		for (int i = 0; i < 7; i++)
		{
			AddHand(CardDraw());
		}
	}

	//��D��[����]�����邩�Ȃ������ׂ�
	if (!IsSeedInHand())//[����]���Ȃ��ꍇ
	{
		//��D�̃J�[�h��S�ĎR�D�ɖ߂�
		for (int i = 0; i < 7; i++)
		{
			ReturnCard(GetHand(i));
			DecreaseHandNum();
		}

		//�h���[������
		for (int i = 0; i < 7; i++)
		{
			AddHand(CardDraw());
		}
	}
	//[����]������ꍇ
	else
	{
		EndFirstDraw = true; //EndFirstDraw�t���O��true�ɂ���
	}
}

void CPU::HandDraw() const
{
	for (int i = 0; i < HandNum; i++)
	{
		if (hand[i] != -1)
		{
			//			  1100
			DrawRotaGraph(1400 + i * Push_X, 0, 1.0, PI, CardBack, TRUE);
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

void CPU::BenchDraw() const
{
	for (int i = 0; i < 5; i++)
	{
		if (Bench[i] != -1)
		{
			switch (DetermineCard(Bench[i], DeckType))
			{
			case 0:  //�A���Z�E�X
				DrawRotaGraph(1600 - i * 140, 100, 1, PI, cardImg[1], FALSE);
				break;
			case 1:  //���b�N�E�U
				DrawRotaGraph(1600 - i * 140, 100, 1, PI, cardImg[3], FALSE);
				break;
			case 2:  //�}�t�H�N�V�[
				DrawRotaGraph(1600 - i * 140, 100, 1, PI, cardImg[4], FALSE);
				break;
			case 3:  //�l�I�����g
				DrawRotaGraph(1600 - i * 140, 100, 1, PI, cardImg[5], FALSE);
				break;
			case 4:  //�J���{�E
				DrawRotaGraph(1600 - i * 140, 100, 1, PI, cardImg[6], FALSE);
				break;
			case 5:  //�o�P�b�`��
				DrawRotaGraph(1600 - i * 140, 100, 1, PI, cardImg[8], FALSE);
				break;
			case 6:  //�z�V�K���X
				DrawRotaGraph(1600 - i * 140, 100, 1, PI, cardImg[9], FALSE);
				break;
			case 7:  //�q�[�h����
				DrawRotaGraph(1600 - i * 140, 100, 1, PI, cardImg[10], FALSE);
				break;
			case 8:  //�G�l���M�[
				DrawRotaGraph(1600 - i * 140, 100, 1, PI, cardImg[12], FALSE);
				break;
			}
		}
	}
}

//�`�悷��J�[�h�𔻕�
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