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
	//DrawString(1100, 680, "手札", 0xffffff);
	//for (int i = 0; i < 6; i++) //HandNum
	//{
	//	DrawFormatString(500 + 25 * i, 100, 0xffffff, "%d", GetSide(i));//hand[i]
	//}

	//山札
	if (CheckCard()) //山札にカードが1枚でも存在する時描画する
	{
		DrawRotaGraph(479, 275, 1, PI, CardBack, FALSE);
	}
	//トラッシュ
	if (Trash[0] != -1) //トラッシュにカードが1枚でも存在する時描画する
	{
		DrawRotaGraph(479, 105, 1, PI, CardBack, FALSE);
	}
	//サイド
	if (1 < count)
	{
		DrawRotaGraph(1460, 420, 1, PI, CardBack, FALSE);//奥下
	}
	if (2 < count)
	{
		DrawRotaGraph(1460, 260, 1, PI, CardBack, FALSE);//奥中
	}
	if (3 < count)
	{
		DrawRotaGraph(1460, 100, 1, PI, CardBack, FALSE);//奥上
	}
	if (4 < count)
	{
		DrawRotaGraph(1435, 453, 1, PI, CardBack, FALSE);//手前下
	}
	if (5 < count)
	{
		DrawRotaGraph(1435, 293, 1, PI, CardBack, FALSE);//手前中
	}
	if (6 <= count)
	{
		DrawRotaGraph(1435, 133, 1, PI, CardBack, FALSE);//手前上
	}
	//手札
	for (int i = 0; i < HandNum; i++)
	{
		if (hand[i] != -1)
		{
			DrawRotaGraph(1100 + i * Push_X, 0, 1.0, PI, CardBack, TRUE);
		}
	}
	//バトルフィールド
	BattleFieldDraw();
	//ベンチ
	for (int i = 0; i < 5; i++)
	{
		if (Bench[i] != -1)
		{
			switch (DetermineCard(Bench[i], DeckType))
			{
			case 0:  //アルセウス
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[1], FALSE);
				break;
			case 1:  //レックウザ
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[3], FALSE);
				break;
			case 2:  //マフォクシー
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[4], FALSE);
				break;
			case 3:  //ネオラント
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[5], FALSE);
				break;
			case 4:  //カルボウ
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[6], FALSE);
				break;
			case 5:  //バケッチャ
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[8], FALSE);
				break;
			case 6:  //ホシガリス
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[9], FALSE);
				break;
			case 7:  //ヒードラン
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[10], FALSE);
				break;
			case 8:  //エネルギー
				DrawRotaGraph(550 + i * 140, 100, 1, PI, cardImg[12], FALSE);
				break;
			}
		}
	}

	DrawString(1100, 150, "CPU 手札", 0xffffff);
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
			TrashHand(); //手札をトラッシュする
			if (Bench[4] != -1) break; //ベンチが埋まったら抜ける
		}
	}
}

void CPU::BattleFieldDraw() const
{
	if (Battle != -1)
	{
		switch (DetermineCard(Battle, DeckType))
		{
		case 0:  //アルセウス
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[1], FALSE);
			break;
		case 1:  //レックウザ
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[3], FALSE);
			break;
		case 2:  //マフォクシー
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[4], FALSE);
			break;
		case 3:  //ネオラント
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[5], FALSE);
			break;
		case 4:  //カルボウ
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[6], FALSE);
			break;
		case 5:  //バケッチャ
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[8], FALSE);
			break;
		case 6:  //ホシガリス
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[9], FALSE);
			break;
		case 7:  //ヒードラン
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[10], FALSE);
			break;
		case 8:  //エネルギー
			DrawRotaGraph(SCREEN_WIDTH / 2 - 20, 375, 1, PI, cardImg[12], FALSE);
			break;
		}
	}
}

int CPU::DetermineCard(int card_id, int dtype) const
{
	//デッキタイプが1の時
	if (dtype == 1)
	{
		if (strcmp(poke_data[card_id].NAME, "aruseusu") == 0
			|| strcmp(poke_data[card_id].NAME, "\naruseusu") == 0) //アルセウス
		{
			return 0;
		}
		if (strcmp(poke_data[card_id].NAME, "\nrekkuza") == 0) //レックウザ
		{
			return 1;
		}
		if (strcmp(poke_data[card_id].NAME, "\nmafokushi") == 0)//マフォクシー
		{
			return 2;
		}
		if (strcmp(poke_data[card_id].NAME, "\nneoranto") == 0)//ネオラント
		{
			return 3;
		}
		if (strcmp(poke_data[card_id].NAME, "\nkarubou") == 0)//カルボウ
		{
			return 4;
		}
		if (strcmp(poke_data[card_id].NAME, "\nbakettya") == 0)//バケッチャ
		{
			return 5;
		}
		if (strcmp(poke_data[card_id].NAME, "\nhosigarisu") == 0)//ホシガリス
		{
			return 6;
		}
		if (strcmp(poke_data[card_id].NAME, "\nhi-doran") == 0)//ヒードラン
		{
			return 7;
		}
		return 8;//エネルギー

		//if (card_id <= 3) //こくば
		//{
		//	return 0;
		//}
		//if (card_id <= 7) //ラルトス
		//{
		//	return 1;
		//}
		//if (card_id == 8)//ディアンシー
		//{
		//	return 2;
		//}
		//if (card_id == 9)//ゲッコウガ
		//{
		//	return 3;
		//}
		//if (card_id <= 22)//エネルギー
		//{
		//	return 4;
		//}

		///*ポケモン*/
		//if (card_id <= 3) //こくば
		//{
		//	return 0;
		//}
		//if (card_id <= 7) //こくばVMAX
		//{
		//	return 1;
		//}
		//if (card_id <= 11)//ラルトス
		//{
		//	return 2;
		//}
		//if (card_id <= 14)//キルリア
		//{
		//	return 3;
		//}
		//if (card_id <= 16)//サーナイト
		//{
		//	return 4;
		//}
		//if (card_id == 17)//ディアンシー
		//{
		//	return 5;
		//}
		//if (card_id == 18)//ゲッコウガ
		//{
		//	return 6;
		//}
		//if (card_id <= 31)//超エネルギー
		//{
		//	return 7;
		//}
	}
	return -1;
}
