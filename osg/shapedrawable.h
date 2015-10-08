#pragma once
#include <osg/ShapeDrawable>
#include <osg/CopyOp>
#include <QObject>
#include "drawable.h"

class ShapeDrawable : public Drawable, public osg::ShapeDrawable
{
    Q_OBJECT

public:
    ShapeDrawable() {}
    osg::Object* cloneType() const { return nullptr; }
    osg::Object* clone(const osg::CopyOp&) const { return nullptr; }
};
