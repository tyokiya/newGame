#include "Scene.h"

Scene::Scene()
{
    nowScene = Tittle; // �V�[���ݒ�
}

Scene::~Scene()
{

}

/// <summary>
/// ���̃V�[���֐؂�ւ�
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