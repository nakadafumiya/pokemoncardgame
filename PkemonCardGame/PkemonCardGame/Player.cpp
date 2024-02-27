#include "Player.h"
#include "DxLib.h"
#include "PadInput.h"

Player::Player()
{
	Cursor_X = 0;
	Cursor_Y = 1;
	OldX = -1;
	DeckType = 0;
	Battle = -1;
	tCount = 0;
	EndFirstDraw = false;
	EndFirstSet = false;
	EndSetSide = false;
	EndStartDraw = false;

	for (int i = 0; i < 27; i++)
	{
		cardImg[i] = -1;
	}
	for (int i = 0; i < 60; i++)
	{
		Trash[i] = -1;
	}
	for (int i = 0; i < 5; i++)
	{
		Bench[i] = -1;
	}
	for (int i = 0; i < 19; i++)
	{
		poke_data[i] = poke.GetPokeID1(i);
	}

	LoadImages();
}

//Player::Player(int dtype)
//{
//	DeckType = dtype;
//	LoadImages();
//
//	//デッキタイプが0の時(こくば)
//	if (DeckType == 0)
//	{
//		for (int i = 0; i < 19; i++)
//		{
//			poke_data[i] = poke.GetPokeID(i);
//		}
//	}
//	else //デッキタイプが1の時()
//	{
//
//	}
//}

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
			AddHand(CardDraw());
		}
	}

	//削除開始
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_BACK))
	{
		TrashHand();
		AdjustmentCursor();
	}
	//ここまで

	//カードを置き終わっていないか
	if (!EndFirstSet)
	{
		FirstCardSet();
	}
	//カードを置き終わった
	else
	{
		//カーソル移動
		//右
		if (MARGIN < PAD_INPUT::GetPadThumbLX() && FlgX == 0)
		{
			//カーソルY位置がベンチの時
			if (Cursor_Y == 1)
			{
				if (HandNum - 1 < ++Cursor_X)
				{
					Cursor_X = 0;
				}
			}
			//カーソルY位置が手札の時
			if (Cursor_Y == 2)
			{
				if (5 - 1 < ++Cursor_X)
				{
					Cursor_X = 0;
				}
			}
		}
		//左
		if (PAD_INPUT::GetPadThumbLX() < -MARGIN && FlgX == 0)
		{
			//カーソルY位置がベンチの時
			if (Cursor_Y == 1)
			{
				if (--Cursor_X < 0)
				{
					Cursor_X = HandNum - 1;
				}
			}
			//カーソルY位置が手札の時
			if (Cursor_Y == 2)
			{
				if (--Cursor_X < 0)
				{
					Cursor_X = 5 - 1;
				}
			}
		}
		//上
		if (EndFirstSet && MARGIN < PAD_INPUT::GetPadThumbLY() && FlgY == 0)
		{
			if (--Cursor_Y < 0)
			{
				Cursor_Y = 2;
			}
			//カーソル移動時に横の範囲から出ないようにする
			switch (Cursor_Y)
			{
			case 0:
				Cursor_X = 0;
				break;
			case 1:
				//手札の数よりカーソルX位置が上回っている時調整する
				if (HandNum < Cursor_X)
				{
					Cursor_X = HandNum;
				}
				break;
			case 2:
				//ベンチの数よりカーソルX位置が上回っている時調整する
				if (5 - 1 < Cursor_X)
				{
					Cursor_X = 4;
				}
				break;
			}
		}
		//下
		if (EndFirstSet && PAD_INPUT::GetPadThumbLY() < -MARGIN && FlgY == 0)
		{
			if (2 < ++Cursor_Y)
			{
				Cursor_Y = 0;
			}

			//カーソルが移動時に横の範囲から出ないようにする
			switch (Cursor_Y)
			{
			case 0:
				Cursor_X = 0;
				break;
			case 1:
				//手札の数よりカーソルX位置が上回っている時調整する
				if (HandNum < Cursor_X)
				{
					Cursor_X = HandNum;
				}
				break;
			case 2:
				//ベンチの数よりカーソルX位置が上回っている時調整する
				if (5 - 1 < Cursor_X)
				{
					Cursor_X = 4;
				}
				break;
			}
		}

		//決定
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
		{
			//カーソルが手札の位置の時 & カーソル位置にカードが存在する時
			if (Cursor_Y == 1 && hand[Cursor_X] != -1)
			{
				//カーソルが手札の位置の時 & カーソル位置にカードが存在する時
				if (Cursor_Y == 1 && hand[Cursor_X] != -1)
				{
					SetTrashPosition(Cursor_X);
					if (Battle == -1)
					{
						//カーソル位置のカードのidをバトルフィールドに入れる
						Battle = hand[Cursor_X];
					}
					else
					{
						for (int i = 0; i < 5; i++)
						{
							if (Bench[i] == -1)
							{
								Bench[i] = hand[Cursor_X];
								break;
							}
						}
					}
					TrashHand(); //手札をトラッシュする
					AdjustmentCursor(); //カーソル位置の調整
				}
			}
		}
	}


	
}

void Player::Draw() const
{
	//山札
	if (CheckCard()) //山札にカードが1枚でも存在する時描画する
	{
		DrawGraph(1397, 723, CardBack, FALSE);
	}
	//トラッシュ
	if (Trash[0] != -1) //トラッシュにカードが1枚でも存在する時描画する
	{
		DrawGraph(1397, 899, CardBack, FALSE);
	}
	//手札
	HandDraw();
	//バトルフィールド
	BattleFieldDraw();
	//ベンチ
	for (int i = 0; i < 5; i++)
	{
		if (Bench[i] != -1)
		{
			switch (DetermineCard(Bench[i], DeckType))
			{
			case 0:  //こくば
				DrawGraph(639 + i * 140, 885, cardImg[0], FALSE);
				break;
			case 1:  //ラルトス
				DrawGraph(639 + i * 140, 885, cardImg[2], FALSE);
				break;
			case 2:  //ディアンシー
				DrawGraph(639 + i * 140, 885, cardImg[5], FALSE);
				break;
			case 3:  //ゲッコウガ
				DrawGraph(639 + i * 140, 885, cardImg[6], FALSE);
				break;
			case 4:  //エネルギー
				DrawGraph(639 + i * 140, 885, cardImg[7], FALSE);
				break;
			}
		}
	}
	//サイド
	Side::Draw();
	
	//カーソル
	DrawCircle(X[Cursor_Y] + 110 * Cursor_X, Y[Cursor_Y], 5, 0xff0000, true);


	DrawString(1300, 680, "cursor キー", 0x000000);
	DrawString(1300, 700, "select スペース", 0x000000);

	//カードを何処に置いてほしいか表示
	//1ターン目のカードセット
	if (!EndFirstSet)
	{
		//バトルフィールド
		if (Battle == -1)
		{
			SetFontSize(25);
			DrawString(1560, 100, "バトルフィールドにカードを\nセットしてください", 0x000000);
			SetFontSize(16);
		}
		//ベンチ
		else
		{
			SetFontSize(25);
			DrawString(1580, 100, "ベンチにカードを\nセットしてください", 0x000000);
			SetFontSize(16);
		}
	}
	

#ifndef DEBUG
#define DEBUG
	if (Battle != -1)
	{
		DrawFormatString(SCREEN_WIDTH / 2 - 70, 580, 0xff0000, "%s", poke_data[Battle].NAME);
		DrawFormatString(SCREEN_WIDTH / 2 - 70, 630, 0xff0000, "HP %d", poke_data[Battle].HP);
	}

	DrawString(1100, 680, "手札", 0xffffff);
	for (int i = 0; i < HandNum; i++)
	{
		DrawFormatString(1100 + 50 * i, 700, 0xffffff, "%d", hand[i]);
	}
	DrawFormatString(1100, 730, 0xffffff, "sCount %d", count);
	DrawString(1100, 750, "Side", 0xffffff);
	for (int i = 0; i < HandNum; i++)
	{
		DrawFormatString(1100 + 25 * i, 770, 0xffffff, "%d", GetSide(i));
	}

	/*DrawFormatString(1100, 600, 0xff0000, "消す枚数 %d", DecreaseNum);
	DrawString(1250, 600, "消す位置 ", 0xff0000);
	for (int i = 0; i < DecreaseNum; i++)
	{
		DrawFormatString(1380 + 20 * i, 600, 0xff0000, "%d ", dPosition[i]);
	}*/
#endif // !DEBUG

}

//画像読み込み
void Player::LoadImages()
{
	const char* card[] = { "images/Pokemon_Card_D1/Calyrex_V.png","images/Pokemon_Card_D1/Calyrex_VMAX.png","images/Pokemon_Card_D1/Ralts.png"
		,"images/Pokemon_Card_D1/Kirlia.png","images/Pokemon_Card_D1/Gardevoir_ex.png","images/Pokemon_Card_D1/Diancie.png","images/Pokemon_Card_D1/ShiningGreninja.png"
		,"images/Pokemon_Card_D1/PsychicEnergy.png","images/Pokemon_Card_D1/OldCemetery.png","images/Pokemon_Card_D1/ポケモンいれかえ.png","images/Pokemon_Card_D1/NestBall.png"
		,"images/Pokemon_Card_D1/UltraBall.png","images/Pokemon_Card_D1/FogCrystal.png","images/Pokemon_Card_D1/EscapeRope.png","images/Pokemon_Card_D1/げんきのハチマキ.png"
		,"images/Pokemon_Card_D1/ChoiceBelt.png","images/Pokemon_Card_D1/ふしぎなアメ.png","images/Pokemon_Card_D1/Miriam.png","images/Pokemon_Card_D1/ProfessorsResearch_Sada.png"
		,"images/Pokemon_Card_D1/BosssOrders_GCis.png","images/Pokemon_Card_D1/Serena.png","images/Pokemon_Card_D1/Arven.png" };

	for (int i = 0; i < 22; i++)
	{
		cardImg[i] = LoadGraph(card[i]);
	}

	CardBack = LoadGraph("images/Pokemon_Card_D1/CardBack.png");
}

//スティック制御
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

	if (MARGIN < OldY && MARGIN < PAD_INPUT::GetPadThumbLY())
	{
		FlgY = 1;
	}
	else if (OldY < -MARGIN && PAD_INPUT::GetPadThumbLY() < -MARGIN)
	{
		FlgY = 1;
	}
	else
	{
		FlgY = 0;
	}

	OldX = PAD_INPUT::GetPadThumbLX();
	OldY = PAD_INPUT::GetPadThumbLY();
}

//カーソル位置調整
void Player::AdjustmentCursor()
{
	//カーソル位置が手札の数より大きかったら
	//最後尾に調整する
	if (HandNum < Cursor_X + 1)
	{
		if (Cursor_X != 0) //カーソル位置が0じゃない時に調整する
		{
			Cursor_X = HandNum - 1;
		}
	}
}

void Player::FirstDraw()
{
	//一枚も持っていない時7枚手札に加える
	if (GetHand(0) == -1)
	{
		for (int i = 0; i < 7; i++)
		{
			AddHand(CardDraw());
		}
	}

	//手札に[たね]があるかないか調べる
	if (!IsSeedInHand())//[たね]がない場合
	{
		//手札のカードを全て山札に戻す
		for (int i = 0; i < 7; i++)
		{
			ReturnCard(GetHand(i));
			DecreaseHandNum();
		}

		//ドローし直す
		for (int i = 0; i < 7; i++)
		{
			AddHand(CardDraw());
		}
	}
	//[たね]がある場合
	else
	{
		EndFirstDraw = true; //EndFirstDrawフラグをtrueにする
	}
}

//手札描画
void Player::HandDraw() const
{
	for (int i = 0; i < HandNum; i++)
	{
		int ph = 0;
		int pw = 0;
		//カーソルY位置が1の時のみ調整する
		if (Cursor_Y == 1)
		{
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
		}

		if (hand[i] != -1)
		{
			//switch (DetermineCard(hand[i], DeckType))
			//{
			//case 0:  //こくば
			//	DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[0], FALSE);
			//	break;
			//case 1:  //こくばVMAX
			//	DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[1], FALSE);
			//	break;
			//case 2:  //ラルトス
			//	DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[2], FALSE);
			//	break;
			//case 3:  //キルリア
			//	DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[3], FALSE);
			//	break;
			//case 4:  //サーナイト
			//	DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[4], FALSE);
			//	break;
			//case 5:  //ディアンシー
			//	DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[5], FALSE);
			//	break;
			//case 6:  //ゲッコウガ
			//	DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[6], FALSE);
			//	break;
			//case 7:  //超エネルギー
			//	DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[7], FALSE);
			//	break;
			//}

			switch (DetermineCard(hand[i], DeckType))
			{
			case 0:  //こくば
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[0], FALSE);
				break;
			case 1:  //ラルトス
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[2], FALSE);
				break;
			case 2:  //ディアンシー
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[5], FALSE);
				break;
			case 3:  //ゲッコウガ
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[6], FALSE);
				break;
			case 4:  //エネルギー
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[7], FALSE);
				break;
			}
		}
	}
}

//バトルフィールドに置いたカードを描画
void Player::BattleFieldDraw() const
{
	if (Battle != -1)
	{
		switch (DetermineCard(Battle, DeckType))
		{
		case 0:  //こくば
			DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[0], FALSE);
			break;
		case 1:  //ラルトス
			DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[2], FALSE);
			break;
		case 2:  //ディアンシー
			DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[5], FALSE);
			break;
		case 3:  //ゲッコウガ
			DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[6], FALSE);
			break;
		case 4:  //エネルギー
			DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[7], FALSE);
			break;
		}
		//switch (DetermineCard(Battle, DeckType))
		//{
		//case 0:  //こくば
		//	DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[0], FALSE);
		//	break;
		//case 1:  //こくばVMAX
		//	DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[1], FALSE);
		//	break;
		//case 2:  //ラルトス
		//	DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[2], FALSE);
		//	break;
		//case 3:  //キルリア
		//	DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[3], FALSE);
		//	break;
		//case 4:  //サーナイト
		//	DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[4], FALSE);
		//	break;
		//case 5:  //ディアンシー
		//	DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[5], FALSE);
		//	break;
		//case 6:  //ゲッコウガ
		//	DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[6], FALSE);
		//	break;
		//case 7:  //超エネルギー
		//	DrawGraph(SCREEN_WIDTH / 2 - 70, 630, cardImg[7], FALSE);
		//	break;
		//}
	}
}

//描画するカードを判別
int Player::DetermineCard(int card_id, int dtype) const
{
	//デッキタイプが0の時
	if (dtype == 0)
	{
		if (strcmp(poke.GetPokeID1(card_id).NAME,"kokuba") == 0
			|| strcmp(poke.GetPokeID1(card_id).NAME,"\nkokuba") == 0) //こくば
		{
			return 0;
		}
		if (strcmp(poke.GetPokeID1(card_id).NAME, "\nrarutosu") == 0) //ラルトス
		{
			return 1;
		}
		if (strcmp(poke.GetPokeID1(card_id).NAME, "\ndhianshi") == 0)//ディアンシー
		{
			return 2;
		}
		if (strcmp(poke.GetPokeID1(card_id).NAME, "\ngekkouga") == 0)//ゲッコウガ
		{
			return 3;
		}
		return 4;//エネルギー

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

//1ターン目にバトルフィールドとベンチにカードを置く
void Player::FirstCardSet()
{
	//カーソル移動
	//右
	if (MARGIN < PAD_INPUT::GetPadThumbLX() && FlgX == 0)
	{
		//カーソルY位置が手札の時
		if (Cursor_Y == 1)
		{
			if (HandNum - 1 < ++Cursor_X)
			{
				Cursor_X = 0;
			}
		}
	}
	//左
	if (PAD_INPUT::GetPadThumbLX() < -MARGIN && FlgX == 0)
	{
		//カーソルY位置が手札の時
		if (Cursor_Y == 1)
		{
			if (--Cursor_X < 0)
			{
				Cursor_X = HandNum - 1;
			}
		}
	}

	//上
	if (MARGIN < PAD_INPUT::GetPadThumbLY() && FlgY == 0)
	{
		Cursor_Y -= 2;
		//Y位置が1より小さい時最後に戻る
		if (Cursor_Y < 1)
		{
			Cursor_Y = 3;

			//カーソル位置の調整
			Cursor_X = 3;
		}
	}
	//下
	if (PAD_INPUT::GetPadThumbLY() < -MARGIN && FlgY == 0)
	{
		Cursor_Y += 2;

		//Y位置が4より多い時最初に戻る
		if (3 < Cursor_Y)
		{
			Cursor_Y = 1;
		}

		//カーソル位置の調整
		if (Cursor_Y == 3)
		{
			Cursor_X = 3;
		}
	}

	//決定
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
	{
		//カーソルが手札の位置の時 & カーソル位置にカードが存在する時
		if (Cursor_Y == 1 && hand[Cursor_X] != -1)
		{
			SetTrashPosition(Cursor_X);
			if (Battle == -1)
			{
				//カーソル位置のカードのidをバトルフィールドに入れる
				Battle = hand[Cursor_X];
			}
			else
			{
				for (int i = 0; i < 5; i++)
				{
					if (Bench[i] == -1)
					{
						Bench[i] = hand[Cursor_X];
						break;
					}
				}
			}
			TrashHand(); //手札をトラッシュする
			AdjustmentCursor(); //カーソル位置の調整
		}
		//カーソルがセット完了ボタンの時
		else if(Cursor_Y == 3)
		{
			EndFirstSet = true;
		}
	}
}
