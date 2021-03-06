#ifndef SCENELIGHTS_H
#define SCENELIGHTS_H

//#include <vector>

#include "light.h"
#include "cmesh.h"

class CLightsScene
{
public:
    explicit CLightsScene();
    virtual ~CLightsScene();

    void AddLight(const ILight &Light);
    ILight& GetLight(int n);
    int GetLightsNumber();
private:
    CMesh &GetMesh();
    std::vector<ILight> m_aLights;
};

#endif // SCENELIGHTS_H
