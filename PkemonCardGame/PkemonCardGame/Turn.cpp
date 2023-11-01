#include "Turn.h"
#include "common.h"

Turn::Turn()
{
	// Ç∂Ç·ÇÒÇØÇÒÇÃîªíËä÷êî
	int check(int human, int computer)
	{
		if (human == computer) {
			return TYP_AIKO;
		}
		switch (human) {
		case JKN_GOO return ((computer == JKN_CHOKI) ? TYP_KATI : TYP_MAKE);
		case JKN_CHOKI return ((computer == JKN_PA) ? TYP_KATI : TYP_MAKE);
		case JKN_PA return ((computer == JKN_GOO) ? TYP_KATI : TYP_MAKE);
		default return -1;
		}
	}
}

AbstractScene* Turn::Update()
{
	if (BattleStart == 0)
	{
		
	}
}

void Turn::Draw() const
{

}