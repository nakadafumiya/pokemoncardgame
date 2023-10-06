#include "SceneManager.h"
#include "AbstractScene.h"
#include "KeyManager.h"

//�����o�ϐ��̒l������������̂��A�b�v�f�[�g�֐�
AbstractScene* SceneManager::Update()
{
	//�L�[���͂̍X�V
	KeyManager::Update();

	//���݃V�[���̃A�b�v�f�[�g�����s
	AbstractScene* nextScene = mScene->Update();

	//���̃V�[�������݃V�[���ƈႤ�ꍇ�؂�ւ���
	if (nextScene != mScene)
	{
		delete mScene;
		mScene = nextScene;
	}
	return nextScene;
}

//�`�揈���݂̂��s���֐�
void SceneManager::Draw() const
{
	//���݃V�[���̕`��֐������s
	mScene->Draw();
}