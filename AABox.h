#ifndef AABOX_H
#define AABOX_H

#include <QVector3D>

class CRay;

class CAABox
{
public:
    explicit CAABox();
    explicit CAABox(const QVector3D & vMinVertex,const QVector3D & vMaxVertex);

    void AddPoint(const QVector3D& vPoint);

    void Set(const QVector3D & vMinVertex,const QVector3D & vMaxVertex);

    bool IsInside(const QVector3D& vPoint) const;

    bool Intersect(const CRay& ray) const;

    const QVector3D& GetMinVertex() const;
    const QVector3D& GetMaxVertex() const;

signals:
    
public slots:

private:
    QVector3D m_vMaxVertex;
    QVector3D m_vMinVertex;

};

#endif // AABOX_H
