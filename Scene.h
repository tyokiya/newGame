#pragma once
#include "DxLib.h"

// �V�[���񋓑�
enum SeceList
{
    Tittle,
    Game,
    Result,
};

class Scene
{
public:
    Scene();
    ~Scene();
    void ChangeNextScene(); // ���̃V�[���֐؂�ւ�
    SeceList GetNowScene() const { return nowScene; };
private:
    SeceList nowScene; // ���݂̃V�[��
};
