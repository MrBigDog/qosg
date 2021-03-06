#pragma once
#include <osg/ShapeDrawable>
#include "Drawable.h"
#include "Shape.h"
#include "../Converter.h"

class ShapeDrawable : public Drawable {
    Q_OBJECT
    Q_PROPERTY(Shape* shape READ getShape WRITE setShape NOTIFY shapeChanged)
    Q_PROPERTY(QColor color READ getColor WRITE setColor NOTIFY colorChanged)
public:
    void classBegin() override;
    osg::ShapeDrawable* toOsg() { return static_cast<osg::ShapeDrawable*>(osgObj.get()); }

    Shape* getShape() { return shape; }
    void setShape(Shape *shape);

    QColor getColor() { return Converter::fromVec4(toOsg()->getColor()); }
    void setColor(const QColor& color);

signals:
    void shapeChanged(Shape* shape);
    void colorChanged(QColor color);

private:
    Shape* shape;
};
