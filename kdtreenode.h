#ifndef KDTREENODE_H
#define KDTREENODE_H

#include "vector3df.h"
#include "Utils.h"
#include "AABox.h"
#include "ray.h"
#include "intersactioninfo.h"
#include "vector"
#include "SubTriangle.h"
#include "vector3df.h"

class CMesh;

class CKDTreeNode
{
public:
    CKDTreeNode(std::vector<CSubTriangle*>* pTriangles, int nLevel, const CAABox& BoundingBox);
    ~CKDTreeNode();

    int Process();
    bool Separate(std::vector<CSubTriangle*>& AllTriangles,
					std::vector<CSubTriangle*>* pLeftTriangleIndeces,
					std::vector<CSubTriangle*>* pRightTriangleIndeces,
					CVector3DF::EDimiensions eDimension,
					float& fBestPortion);

    bool Intersect(const CRay& ray, CIntersactionInfo& intersectionInfo, bool bDebug = false);

    int GetMemory() const;

private:
    CMesh &GetMesh();
    std::vector<CSubTriangle*>* m_pTriangles;
    int m_nLevel;
    CKDTreeNode * m_pLeftNode;
    CKDTreeNode * m_pRightNode;
    CAABox m_BoundingBox;
};

#endif // KDTREENODE_H
