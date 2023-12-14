#pragma once
#include "Card_Deck.h"
#include "Pokemon.h"

class Hand
{
public:
	Hand();
	//èD‚ğ‘‚â‚·
	void AddHand(int card);
	//èD‚ğŒ¸‚ç‚·
	void TrashHand();
	//Á‚·ƒJ[ƒh‚ğİ’è‚·‚é
	void SetTrashPosition(int position);
	//èD‘S•”Á‚·
	void AllTrash();
	int SendCardID(int i) { return saveHand[i]; }
	//ˆê•Û‘¶‚µ‚Ä‚¢‚½ƒJ[ƒh‚ğÁ‚·
	void InitSaveHand()
	{
		for (int i = 0; i < 5; i++)
		{
			if (saveHand[i] == -1) break;
			saveHand[i] = -1;
		}
	}
	//èD‚Éu‚½‚Ëv‚ª‘¶İ‚·‚é‚©
	bool IsSeedInHand()
	{
		for (int i = 0; i < HandNum; i++)
		{
			if (hand[i] <= 9) //Œ³F18 ID‚ª18ˆÈ‰º‚Ì‚Æ‚«[‚½‚Ë]‚ª‘¶İ‚·‚é
			{
				return true;
			}
		}

		return false;
	}
	int GetHand(int i) { return hand[i]; }
	void DecreaseHandNum() { --HandNum; }

protected:
	int hand[10]; //èD
	//char* hand[10]; //charŒ^èD
	//char* saveHand[5]; //ˆê•Û‘¶—p
	int saveHand[5];
	int HandNum;  //‚Á‚Ä‚¢‚éèD‚Ì”
	int DecreaseNum = 0;    //Œ¸‚ç‚·”
	int dPosition[10]; //Œ¸‚ç‚·ˆÊ’u
	int Push_X;  //èD‚ª‘‚¦‚é‚½‚Ñ‚É‰¡‚É‹l‚ß‚é
	const int MaxHand = 10;  //Å‘å‚Å‚Ä‚éèD‚Ì”

private:
	Card_Deck deck;
	Pokemon poke;
};