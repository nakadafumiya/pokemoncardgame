#include "SceneManager.h"
#include "AbstractScene.h"
#include "KeyManager.h"

//メンバ変数の値を書き換えるのがアップデート関数
AbstractScene* SceneManager::Update()
{
	//キー入力の更新
	KeyManager::Update();

	//現在シーンのアップデートを実行
	AbstractScene* nextScene = mScene->Update();

	//次のシーンが現在シーンと違う場合切り替える
	if (nextScene != mScene)
	{
		delete mScene;
		mScene = nextScene;
	}
	return nextScene;
}

//描画処理のみを行う関数
void SceneManager::Draw() const
{
	//現在シーンの描画関数を実行
	mScene->Draw();
}