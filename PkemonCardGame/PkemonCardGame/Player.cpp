#include "Player.h"
#include "DxLib.h"
#include "PadInput.h"

Player::Player()
{
	Cursor_X = 0;
	OldX = -1;
	DeckType = 0;

	for (int i = 0; i < 27; i++)
	{
		cardImg[i] = -1;
	}
}

Player::Player(int dtype)
{
	DeckType = dtype;
	LoadImages();

	//デッキタイプが0の時(こくば)
	if (DeckType == 0)
	{
		for (int i = 0; i < 19; i++)
		{
			poke_data[i] = poke.GetPokeID(i);
		}
	}
	else //デッキタイプが1の時()
	{

	}
}

void Player::Update()
{
	SticControl();

	//to do 確認用	
	//デッキからカードを引く
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_X))
	{
		//引けるカードがある時だけ引く
		if (CheckCard())
		{
			DrawCard(CardDraw());
		}
	}

	//削除開始
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_BACK))
	{
		TrashHand();
		AdjustmentCursor();
	}
	//ここまで

	//カーソル移動
	//右
	if (MARGIN < PAD_INPUT::GetPadThumbLX() && FlgX == 0)
	{
		if (HandNum - 1 < ++Cursor_X)
		{
			Cursor_X = 0;
		}
	}
	//左
	if (PAD_INPUT::GetPadThumbLX() < -MARGIN && FlgX == 0)
	{
		if (--Cursor_X < 0)
		{
			Cursor_X = HandNum - 1;
		}
	}

	//決定
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
	{
		SetTrashPosition(Cursor_X);
	}
}

void Player::Draw() const
{
	DrawString(1100, 680, "手札", 0xffffff);
	for (int i = 0; i < HandNum; i++)
	{
		DrawFormatString(1100 + 25 * i, 700, 0xffffff, "%d", hand[i]);
	}
	DrawCircle(910 + 110 * Cursor_X, 800, 5, 0xff0000, true);

	for (int i = 0; i < HandNum; i++)
	{
		int ph = 0;
		int pw = 0;
		//カーソル位置のカードを上に上げる
		if (Cursor_X == i)
		{
			ph = 20;
		}
		//カーソル位置以外のカードを左右にずらす
		if (i < Cursor_X)
		{
			pw = -20;
		}
		else if (Cursor_X < i)
		{
			pw = 20;
		}

		if (hand[i] != -1)
		{
			switch (DetermineCard(i,DeckType))
			{
			case 0:  //こくば
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[0], TRUE);
				break;
			case 1:  //こくばVMAX
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[1], TRUE);
				break;
			case 2:  //ラルトス
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[2], TRUE);
				break;
			case 3:  //キルリア
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[3], TRUE);
				break;
			case 4:  //サーナイト
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[4], TRUE);
				break;
			case 5:  //ディアンシー
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[5], TRUE);
				break;
			case 6:  //ゲッコウガ
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[6], TRUE);
				break;
			}
		}
	}

#ifndef DEBUG
#define DEBUG
	/*for (int i = 0; i < 10; i++)
	{
		DrawFormatString(900 + 25 * i, 400, 0xffffff, "%d", hand[i]);
	}*/

	DrawFormatString(1100, 600, 0xff0000, "消す枚数 %d", DecreaseNum);
	DrawString(1250, 600, "消す位置 ", 0xff0000);
	for (int i = 0; i < DecreaseNum; i++)
	{
		DrawFormatString(1380 + 20 * i, 600, 0xff0000, "%d ", dPosition[i]);
	}

	/*DrawString(1300, 680, "カーソル移動 ←→(スティック)", 0x000000);
	DrawString(1300, 700, "選択 A", 0x000000);
	DrawString(1300, 720, "消去 BACK", 0x000000);
	DrawString(1300, 740, "数字を入れる X", 0x000000);*/
#endif // !DEBUG

}

void Player::LoadImages()
{
	//デッキタイプが0の時
	if (DeckType == 0)
	{
		const char* card[] = { "images/Pokemon_Card_D1/Calyrex_V.png","images/Pokemon_Card_D1/Calyrex_VMAX.png","images/Pokemon_Card_D1/Ralts.png"
		,"images/Pokemon_Card_D1/Kirlia.png","images/Pokemon_Card_D1/Gardevoir_ex.png","images/Pokemon_Card_D1/Diancie.png","images/Pokemon_Card_D1/かがやくゲッコウガ.png"
		,"images/Pokemon_Card_D1/超エネルギー.png","images/Pokemon_Card_D1/OldCemetery.png","images/Pokemon_Card_D1/ポケモンいれかえ.png","images/Pokemon_Card_D1/NestBall.png"
		,"images/Pokemon_Card_D1/ハイパーボール.png","images/Pokemon_Card_D1/FogCrystal.png","images/Pokemon_Card_D1/EscapeRope.png","images/Pokemon_Card_D1/げんきのハチマキ.png"
		,"images/Pokemon_Card_D1/ChoiceBelt.png","images/Pokemon_Card_D1/ふしぎなアメ.png","images/Pokemon_Card_D1/Miriam.png","images/Pokemon_Card_D1/ProfessorsResearch_Sada.png"
		,"images/Pokemon_Card_D1/BosssOrders_GCis.png","images/Pokemon_Card_D1/Serena.png","images/Pokemon_Card_D1/Arven.png" };

		for (int i = 0; i < 22; i++)
		{
			cardImg[i] = LoadGraph(card[i]);
		}
	}
	else //デッキタイプが1の時
	{
		const char* card[] = { "images/Pokemon_Card_D2/Arceus_VSTAR.png","images/Pokemon_Card_D2/Arceus_VSTAR.png","images/Pokemon_Card_D2/Arceus_V.png","images/Pokemon_Card_D2/Rayquaza_VMAX.png"
			,"images/Pokemon_Card_D2/Rayquaza_V.png","images/Pokemon_Card_D2/Delphox_V.png","images/Pokemon_Card_D2/Lumineon_V.png","images/Pokemon_Card_D2/Charcadet.png","images/Pokemon_Card_D2/Armarouge.png"
			,"images/Pokemon_Card_D2/Pumpkaboo.png","images/Pokemon_Card_D2/Skwovet.png","images/Pokemon_Card_D2/ShiningHeatran.png","images/Pokemon_Card_D2/FireEnergy .png","images/Pokemon_Card_D2/LightningEnergy.png"
			,"images/Pokemon_Card_D2/DoubleTurboEnergy.png","images/Pokemon_Card_D2/MagmaBasin.png","images/Pokemon_Card_D2/NestBall.png","images/Pokemon_Card_D2/UltraBall.png","images/Pokemon_Card_D2/CaptureAroma.png"
			,"images/Pokemon_Card_D2/BattleVIPPath.png","images/Pokemon_Card_D2/Switch.png","images/Pokemon_Card_D2/PalPad.png","images/Pokemon_Card_D2/ChoiceBelt.png","images/Pokemon_Card_D2/ProfessorsResearch_Sada.png"
			,"images/Pokemon_Card_D2/BosssOrders_GCis.png","images/Pokemon_Card_D2/Serena.png","images/Pokemon_Card_D2/Raihan.png","images/Pokemon_Card_D2/Judge.png" };

		for (int i = 0; i < 27; i++)
		{
			cardImg[i] = LoadGraph(card[i]);
		}
	}
}

void Player::SticControl()
{
	if (MARGIN < OldX && MARGIN < PAD_INPUT::GetPadThumbLX())
	{
		FlgX = 1;
	}
	else if (OldX < -MARGIN && PAD_INPUT::GetPadThumbLX() < -MARGIN)
	{
		FlgX = 1;
	}
	else
	{
		FlgX = 0;
	}

	OldX = PAD_INPUT::GetPadThumbLX();
}

void Player::AdjustmentCursor()
{
	//カーソル位置が手札の数より大きかったら
	//最後尾に調整する
	if (HandNum < Cursor_X + 1)
	{
		Cursor_X = HandNum - 1;
	}
}
