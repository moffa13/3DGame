#include "irrlicht/irrlicht.h"

int main(){

    irr::IrrlichtDevice *device{irr::createDevice (
		irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(800,600),
		32,
		false,
		true,
		false,
        0)};

    device->getCursorControl()->setVisible(false);

    irr::video::IVideoDriver *driver{device->getVideoDriver()};

    irr::scene::ISceneManager *sceneManager{device->getSceneManager()};


    irr::SKeyMap keyMap[5];
    keyMap[0].Action = irr::EKA_MOVE_FORWARD;   // avancer
    keyMap[0].KeyCode = irr::KEY_KEY_Z;
    keyMap[1].Action = irr::EKA_MOVE_BACKWARD;  // reculer
    keyMap[1].KeyCode = irr::KEY_KEY_S;
    keyMap[2].Action = irr::EKA_STRAFE_LEFT;    // a gauche
    keyMap[2].KeyCode = irr::KEY_KEY_Q;
    keyMap[3].Action = irr::EKA_STRAFE_RIGHT;   // a droite
    keyMap[3].KeyCode = irr::KEY_KEY_D;
    keyMap[4].Action = irr::EKA_JUMP_UP;        // saut
    keyMap[4].KeyCode = irr::KEY_SPACE;

    sceneManager->addCameraSceneNodeFPS(
        0,
        100.0f,
        0.1f,
        -1,
        keyMap,
        5
    );


    irr::scene::IMeshSceneNode *cube{sceneManager->addCubeSceneNode(10.0f, 0, -1, irr::core::vector3df{0.0f, 0.0f, 20.0f})};

    irr::scene::IAnimatedMeshSceneNode *sydney{sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh("sydney.md2"))};

    sydney->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    sydney->setMaterialTexture(0, driver->getTexture("sydney.bmp"));

    sydney->setMaterialFlag(irr::video::EMF_FOG_ENABLE, true);

    sydney->setMD2Animation(irr::scene::EMAT_STAND);
    driver->setFog(
      irr::video::SColor(0, 255, 255, 255),
      irr::video::EFT_FOG_LINEAR,
      20.0f,
      100.0f,
      0.01f,
      true,
      true);

    driver->getOverrideMaterial().EnableFlags = irr::video::EMF_FOG_ENABLE;
    driver->getOverrideMaterial().Material.setFlag(irr::video::EMF_FOG_ENABLE, true);
    driver->getOverrideMaterial().EnablePasses = irr::scene::ESNRP_SOLID;


    while(device->run()){
        driver->beginScene(true, true, irr::video::SColor{255, 115, 17, 17});
        sceneManager->drawAll();
        driver->endScene();
    }

    device->drop();

	return 0;
}
