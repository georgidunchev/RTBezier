#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <QObject>
#include <QtGlobal>
#include <QImage>
#include <QAtomicInt>
#include <QElapsedTimer>
#include <QtWidgets/QProgressDialog>
#include <qmutex.h>

#include "lightsscene.h"
#include "camera.h"
#include "shader.h"

class CRaytracerThread;
class CMesh;

class RayTracer : public QObject
{
    Q_OBJECT
public:
    explicit RayTracer(QObject *parent = 0);
    ~RayTracer();

    void BeginFrame(bool bHighQuality);
	void SetCanvas(int fWidth, int fHeight);
    void Render();
    void RenderThreaded();
	QRgb RenderPixel(const int x, const int y, bool bDebug = false);
	QRgb RenderPixelFromScreen(const int x, const int y, bool bDebug = false);

    QImage &GetImage();

    CMesh &GetMesh();

    void LoadNewMesh(const QString& strInputFileName);

    Camera & GetCamera();
    CLightsScene & GetLightScene();
    CShader & GetShader();

    QElapsedTimer& GetTimer() { return m_Timer; }
    //threaded methods
    int GetBucketsCount() const;
    int GetNextBucketId();
    void GetBucketRectById(int nBucketId, QRect &rect) const;
    void ThreadsFinished();

    //KD tree
    void GenerateKDTree();

	bool IsHighQuality() const;

	std::string GetOpenFileName() const;

    QAtomicInt m_nAABBIntersections;
    QAtomicInt m_nObjIntersections;
    QAtomicInt m_nAABBTime;
    QAtomicInt m_nObjTime;
    QAtomicInt m_nTotalTime;

private:
    Camera m_Camera;
    CLightsScene m_LightScene;
    CShader m_Shader;

    QImage * m_pImage;
	int m_nCanvasWidth;
	int m_nCanvasHeight;
    int m_nWidth;
    int m_nHeight;
	int m_nSmallWidth;
	int m_nSmallHeight;
	int m_nCrntWidth;
    int m_nCrntHeight;

    CMesh m_Mesh;

    QElapsedTimer m_Timer;

    // threaded rendering settings
    QAtomicInt m_nNextBucket;
    int m_nHorizontalBuckets;
    int m_nVerticalBuckets;
    std::vector<CRaytracerThread*> m_arrThreads;

    QProgressDialog* progress;

    int m_nRunningThreads;

    int m_nBucketId;

	bool m_bHighQuality;

	QMutex mutex;

	std::string m_strOpenFile;

signals:
    void sigBucketDone(int value);
    void sigThreadsFinished();

public slots:
    void slotThreadStarted(int nId);
    void slotThreadEnded(int nId);
};

#endif // RAYTRACER_H
