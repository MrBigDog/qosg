#pragma once
#include <osg/Shape>
#include "Shape.h"
#include "../Converter.h"

class Sphere : public Shape {
    Q_OBJECT
    Q_PROPERTY(float radius READ getRadius WRITE setRadius NOTIFY radiusChanged)
    Q_PROPERTY(QVector3D center READ getCenter WRITE setCenter NOTIFY centerChanged)

public:
    void classBegin() override;
    osg::Sphere* toOsg() { return static_cast<osg::Sphere*>(osgObj.get()); }

    float getRadius() { return toOsg()->getRadius(); }
    void setRadius(float radius);

    QVector3D getCenter() { return Converter::fromVec3(toOsg()->getCenter()); }
    void setCenter(const QVector3D& center);

signals:
    void radiusChanged(float radius);
    void centerChanged(const QVector3D& center);
};
