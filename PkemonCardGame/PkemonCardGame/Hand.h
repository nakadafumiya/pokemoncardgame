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
	void TrashHand();
	//�����J�[�h��ݒ肷��
	void SetTrashPosition(int position);
	//��D�S������
	void AllTrash();
	void LoadImages();

private:
	int cardimg[22]; //�J�[�h�摜
	int hand[10]; //��D
	int HandNum;  //�����Ă����D�̐�
	int Cursor_X;  //�J�[�\���ʒu
	int DecreaseNum = 0;    //���炷��
	int dPosition[10]; //���炷�ʒu
	int Push_X;  //��D�������邽�тɉ��ɋl�߂�

	const int MaxHand = 10;  //�ő�Ŏ��Ă��D�̐�
};