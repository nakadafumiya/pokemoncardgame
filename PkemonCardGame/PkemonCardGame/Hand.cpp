#include "Hand.h"
#include "DxLib.h"
#include "PadInput.h"
#include <string.h>

Hand::Hand()
{
	for (int i = 0; i < MaxHand; i++)
	{
		hand[i] = -1;

		dPosition[i] = -1;
	}
	for (int i = 0; i < 5; i++)
	{
		saveHand[i] = -1;
	}
	HandNum = 0;//7
	Push_X = 90;
}

void Hand::AddHand(int card)
{
	//ŽèŽD‚Ì”‚ðˆø‚¢‚½•ª‘‚â‚·
	++HandNum;

	//ƒJ[ƒh‚ÌŽí—Þ‚ðŠi”[
	hand[HandNum - 1] = card;
	//hand[HandNum] = poke.GetName(card);

	//ŽèŽD‚Ì”‚ª7–‡‚æ‚èã‚ÌŽžŠÔŠu‚ð‹·‚ß‚é
	if (7 < HandNum)
	{
		Push_X -= 5;  //ŽèŽD‚ª‘‚¦‚½•ªƒJ[ƒh‚ÌŠÔŠu‚ð‹·‚ß‚é
	}
	
}

void Hand::TrashHand()
{
	//Žw’è‚µ‚½ˆÊ’u‚ÌƒJ[ƒh‚ðÁ‚·
	for (int i = 0; i < DecreaseNum; i++)
	{
		if (i < 5) //ˆêŽž•Û‘¶
		{
			saveHand[i] = hand[i];
		}
		hand[dPosition[i]] = -1;
		if (Push_X < 90) //ŠÔŠu‚ª90–¢–ž‚ÌŽž
		{
			Push_X += 5;  //ŽèŽD‚ªŒ¸‚Á‚½•ªƒJ[ƒh‚ÌŠÔŠu‚ðL‚°‚é
		}
	}

	//”‚ðŒ¸‚ç‚µI‚¦‚½‚çAdPosition‚ÆDecreaseNum‚ð‰Šú‰»
	for (int i = 0; i < DecreaseNum; i++)
	{
		dPosition[i] = -1;
	}
	DecreaseNum = 0;

	//ŽèŽD‚ÉƒJ[ƒh‚ªŽc‚Á‚Ä‚¢‚é‚©’²‚×‚é
	bool have_c = false; //true:Žc‚Á‚Ä‚¢‚é false:Žc‚Á‚Ä‚¢‚È‚¢
	for (int i = 0; i < HandNum; i++)
	{
		//ƒJ[ƒh‚ª‚ ‚éŽžhave_c‚ðtrue‚É‚·‚é
		if (hand[i] != -1)
		{
			have_c = true;
			break;
		}
	}


	int i = 0;
	//Žc‚Á‚Ä‚¢‚éƒJ[ƒh‚ª‚ ‚éŽž‘O‚É‹l‚ß‚é
	if (have_c)
	{
		while (i < HandNum)
		{
			//¡Œ©‚Ä‚¢‚é‚Ì‚ªNULL‚È‚çŒã‚ë‚©‚ç‘O‚É‹l‚ß‚é
			if (hand[i] == -1)
			{
				for (int j = i; j < HandNum; j++)
				{
					hand[j] = hand[j + 1];
				}
				//ÅŒã”ö‚ð-1‚É‚·‚éEŽèŽD‚Ì”‚ðŒ¸‚ç‚·
				hand[HandNum - 1] = -1;
				--HandNum;
			}

			//hand[i]‚ª-1‚¶‚á‚È‚¢‚È‚çi‚ð+1‚·‚é
			if (hand[i] != -1) ++i;
		}
	}
	else
	{
		HandNum = 0;
	}
}

void Hand::SetTrashPosition(int position)
{
	dPosition[DecreaseNum] = position;
	++DecreaseNum;
}

void Hand::AllTrash()
{
	for (int i = 0; i < HandNum; i++)
	{ 
		saveHand[i] = hand[i];
		hand[i] = -1;
	}
	HandNum = 0;
}
