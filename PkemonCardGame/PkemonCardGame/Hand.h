#pragma once

class Hand
{
public:
	Hand();
	void Update();
	void Draw()const;
	//��D�𑝂₷
	void DrawCard(int card);
	//��D�����炷
	void TrashHand(int start);
	//�����J�[�h��ݒ肷��
	void SetTrashPosition(int position)
	{
		cs[dc] = position;
		++dc;
	}
	//��D�S������
	void AllTrash();

private:
	int hand[10];
	int hand_num;  //�����Ă����D�̐�
	int cursor_x;  //�J�[�\���ʒu
	int dc = 0;    //���炷��
	int cs[10]; //���炷�ʒu
};