#ifndef CMESH_H
#define CMESH_H

#include <QObject>
#include <QVector>
#include <ray.h>
#include <intersactioninfo.h>
#include <triangle.h>

class CMesh : public QObject
{
    Q_OBJECT
public:
    explicit CMesh(QObject *parent = 0);
    
    void Load(const QString &strInputFileName);

    bool Intersect(const CRay& ray, CIntersactionInfo& intersectionInfo );
signals:
    
public slots:

private:
    QVector<QVector3D> m_aVertices;
    QVector<CTriangle> m_aTriangles;
};

#endif // CMESH_H
