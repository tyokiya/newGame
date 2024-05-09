#include "Scene.h"

Scene::Scene()
{
    nowScene = Tittle; // シーン設定
}

Scene::~Scene()
{

}

/// <summary>
/// 次のシーンへ切り替え
/// </summary>
void Scene::ChangeNextScene()
{
	switch (nowScene)
	{
	case Tittle:
		nowScene = Game;
		break;
	case Game:
		nowScene = Result;
		break;
	case Result:
		nowScene = Tittle;
		break;
	default:
		break;
	}
}