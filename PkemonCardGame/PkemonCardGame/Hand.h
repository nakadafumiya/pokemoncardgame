#pragma once
#include "Card_Deck.h"
#include "Pokemon.h"

class Hand
{
public:
	Hand();
	//èD‚ğ‘‚â‚·
	void DrawCard(int card);
	//èD‚ğŒ¸‚ç‚·
	void TrashHand();
	//Á‚·ƒJ[ƒh‚ğİ’è‚·‚é
	void SetTrashPosition(int position);
	//èD‘S•”Á‚·
	void AllTrash();
	//char* SendCardName(int i) { return saveHand[i]; }
	int SendCardName(int i) { return saveHand[i]; }
	void InitSaveHand()
	{
		/*for (int i = 0; i < 5; i++)
		{
			if (saveHand[i] == NULL) break;
			saveHand[i] = NULL;
		}*/

		for (int i = 0; i < 5; i++)
		{
			if (saveHand[i] == -1) break;
			saveHand[i] = -1;
		}
	}
	//•`‰æ‚·‚éƒJ[ƒh‚ğ”»•Ê
	int DetermineCard(int i ,int dtype)const;

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