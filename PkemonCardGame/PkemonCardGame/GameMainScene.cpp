#include "Dxlib.h"
#include "GameMainScene.h"
#include "Card_Deck.h"

#include "Pokemon.h"
#include "PadInput.h"
#include"Help.h"

Pokemon poke;
int interval = 0;


GameMainScene::GameMainScene()
{
	NextTurn = false;
	Battlefield = true;

	TurnCount = 0;
	Player = 0;
	Turn = START;
	Cr = GetColor(255, 255, 255);

	helpimage1 = LoadGraph("image/rule (2).png");
	helpimage2 = LoadGraph("image/rule2 (2).png");
	Backimage = LoadGraph("image/Title_Back.png");

	HelpFlag = false;
}

AbstractScene* GameMainScene::Update()
{
	player.Update();
	cpu.Update();
	//side.Update();
	end.Update();

	if (PAD_INPUT::OnClick(XINPUT_BUTTON_START))
	{

		HelpFlag=true;
	}

	if (HelpFlag == false)
	{
		switch (Turn)
		{
		case START:

			if (player.EndFirstDraw && cpu.EndFirstDraw)
			{
				//if (!NextTurn/*==false*/)
				//{
				//	Turn = MY_TURN;
				//}
				//else
				//{
				//	Turn = ENEMY_TURN;
				//}
				Turn = MY_TURN;
			}

			//最初に7枚手札に加える・サイドを入れる
			if (10 < ++interval)
			{
				interval = 0;
				//プレイヤー
				if (!player.EndFirstDraw)
				{
					//一枚も持っていない時7枚手札に加える
					if (player.GetHand(0) == -1)
					{
						for (int i = 0; i < 7; i++)
						{
							player.AddHand(player.CardDraw());
						}
					}

					//手札に[たね]があるかないか調べる
					if (!player.IsSeedInHand())//[たね]がない場合
					{
						//手札のカードを全て山札に戻す
						for (int i = 0; i < 7; i++)
						{
							player.ReturnCard(player.GetHand(i));
							player.DecreaseHandNum();
						}

						//ドローし直す
						for (int i = 0; i < 7; i++)
						{
							player.AddHand(player.CardDraw());
						}
					}
					else
					{
						//サイドに置く
						for (int i = 0; i < 6; i++)
						{
							if (player.CheckCard())
							{
								player.SetSide(player.CardDraw());
							}
						}

						player.EndFirstDraw = true;
					}
				}
				//CPU
				if (!cpu.EndFirstDraw)
				{
					//7枚手札に加える
					if (cpu.GetHand(0) == -1)
					{
						for (int i = 0; i < 7; i++)
						{
							cpu.AddHand(cpu.CardDraw());
						}
					}

					//手札に[たね]があるかないか調べる
					if (!cpu.IsSeedInHand())//[たね]がない場合
					{
						//手札のカードを全て山札に戻す
						for (int i = 0; i < 7; i++)
						{
							cpu.ReturnCard(cpu.GetHand(i));
							cpu.DecreaseHandNum();
						}

						//ドローし直す
						for (int i = 0; i < 7; i++)
						{
							cpu.AddHand(cpu.CardDraw());
						}
					}
					else
					{
						//サイドに置く
						for (int i = 0; i < 6; i++)
						{
							if (cpu.CheckCard())
							{
								cpu.SetSide(cpu.CardDraw());
							}
						}

						cpu.EndFirstDraw = true;
					}
				}
			}

			//Turn = MY_TURN;


			break;

		case MY_TURN:
			if (Player == 0)
			{

				Cr = GetColor(255, 255, 255);


				if (GetJoypadInputState(PAD_INPUT_X) == 1)
				{
					//手札
					return this;
				}
				if (GetJoypadInputState(PAD_INPUT_Y) == 1)
				{
					//カードの使用・召喚
				}
				if (GetJoypadInputState(PAD_INPUT_B) == 1)
				{
					//カードの詳細表示(横のスペース)
				}
				if (GetJoypadInputState(PAD_INPUT_A) == 1)
				{
					//戻る
				}
				if (PAD_INPUT::OnClick(PAD_INPUT_START) || CheckHitKey(KEY_INPUT_SPACE))
				{
					int A = 0;
					if (KEY_INPUT_SPACE) { A++; }
					else { A = 0; } //Ａボタンが離されたら
					TurnCount++;
					//一瞬だけ反応させたい
					if (A == 1)
					{
						Turn = ENEMY_TURN;
					}
					break;
				}
			}
			break;
		case ENEMY_TURN:

			Cr = GetColor(255, 255, 255);

			if (PAD_INPUT::OnClick(PAD_INPUT_START) || CheckHitKey(KEY_INPUT_G))
			{
				TurnCount++;
				Turn = MY_TURN;
			}
		}
	}



	card_deck.Update(this);
	pokemon.Update(this);
	return this;
}

void GameMainScene::Draw() const
{
	if (HelpFlag == false)
	{

		field.Draw();
		card_deck.Draw();
		//pokemon.Draw();



		switch (Turn)
		{
		case START:
			//DrawString(960, 540, "Battle Start", GetColor(255, 0, 0));
			break;

		case MY_TURN:
			if (Player == 0)
			{

				//������̕`��
				//DrawString(960, 540, "�����̃^�[���I", Cr);
				//DrawString(50, 100, "B:��D Y:�J�[�h�̏ڍ� X:�g�p(����) A:�߂� START:�^�[���G���h", Cr);

				if (GetJoypadInputState(PAD_INPUT_1) == 1)
				{
					//��D����
				}
				if (GetJoypadInputState(PAD_INPUT_3) == 1)
				{
					//�J�[�h�̏ڍ�(���̉�ʂɃA�b�v)
				}
				if (GetJoypadInputState(PAD_INPUT_2) == 1)
				{
					//�J�[�h�̎g�p(����)
				}
				if (GetJoypadInputState(PAD_INPUT_4) == 1)
				{
					//�߂�
				}
				if (GetJoypadInputState(PAD_INPUT_START) == 1)
				{
					//DrawString(960, 540, "�^�[���G���h", Cr);
					break;
				}

				DrawString(960, 540, "YOUR TURN", Cr);
				DrawBoxAA(950, 500, 1200, 600, 0x57AF72, true);
				DrawString(50, 100, "X:手札　 Y:カードの使用 B:カードの詳細　 A:戻る 　START:ターンエンド　", Cr);

				if (GetJoypadInputState(PAD_INPUT_X) == 1)
				{
					//手札
				}
				if (GetJoypadInputState(PAD_INPUT_Y) == 1)
				{
					//カードの使用・召喚
				}
				if (GetJoypadInputState(PAD_INPUT_B) == 1)
				{
					//カードの詳細表示(横のスペース)
				}
				if (GetJoypadInputState(PAD_INPUT_START) == 1)
				{
					//戻る
				}
				if (PAD_INPUT::OnClick(PAD_INPUT_A) || CheckHitKey(KEY_INPUT_SPACE))
				{
					DrawString(960, 540, "TURN END", Cr);
					break;
				}
				break;
		case ENEMY_TURN:

			//�����̕`��
			DrawString(960, 540, "ENEMY TURN", Cr);
			}

			
			break;

		}
		side.Draw();
		player.Draw();
		cpu.Draw();
	}

	if (HelpFlag == true)
	{
		DrawGraph(0, 0, Backimage, TRUE);

		SetFontSize(50);
		DrawString(SCREEN_WIDTH / 5 - 100, 250, "自分の番にすること", 0x00000);
		DrawString(SCREEN_WIDTH / 2 + 200, 250, "ターンの流れ", 0x00000);
		SetFontSize(100);
		DrawString(SCREEN_WIDTH / 2 - 200, 100, "遊び方", 0x000000);
		DrawRotaGraph(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2, 1, 0, helpimage1, TRUE);
		DrawRotaGraph(SCREEN_WIDTH / 2 + 400, SCREEN_HEIGHT / 2, 1, 0, helpimage2, TRUE);

		SetFontSize(30);
		DrawString(0, 1000, "Aボタンで戻る", 0x000000);
	}

}
	
	
//ポケモンをバトルフィールドに置く条件
//void GameMainScene::Battlepoke(int Card)
//{
//	if (Battlefield = true && Card < 10)
//	{
//		Battlefield = false;
//	}
//}
