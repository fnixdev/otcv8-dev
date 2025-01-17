/*
 * Copyright (c) 2010-2017 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef UIMAP_H
#define UIMAP_H

#include "declarations.h"
#include <framework/ui/uiwidget.h>
#include "tile.h"

#include "mapview.h"

class UIMap : public UIWidget
{
public:
    UIMap();
    ~UIMap();

    bool onMouseMove(const Point& mousePos, const Point& mouseMoved);

    void drawSelf(Fw::DrawPane drawPane);

    void movePixels(int x, int y);
    bool setZoom(int zoom);
    bool zoomIn();
    bool zoomOut();
    void followCreature(const CreaturePtr& creature) { m_mapView->followCreature(creature); }

    void setCameraPosition(const Position& pos) { m_mapView->setCameraPosition(pos); }
    void setMaxZoomIn(int maxZoomIn) { m_maxZoomIn = maxZoomIn; }
    void setMaxZoomOut(int maxZoomOut) { m_maxZoomOut = maxZoomOut; }
    void setMultifloor(bool enable) { m_mapView->setMultifloor(enable); }
    void lockVisibleFloor(int floor) { m_mapView->lockFirstVisibleFloor(floor); }
    void unlockVisibleFloor() { m_mapView->unlockFirstVisibleFloor(); }
    void setVisibleDimension(const Size& visibleDimension);
    void setDrawFlags(Otc::DrawFlags drawFlags) { m_mapView->setDrawFlags(drawFlags); }
    void setDrawTexts(bool enable) { m_mapView->setDrawTexts(enable); }
    void setDrawNames(bool enable) { m_mapView->setDrawNames(enable); }
    void setDrawHealthBars(bool enable) { m_mapView->setDrawHealthBars(enable); }
    void setDrawHealthBarsOnTop(bool enable) { m_mapView->setDrawHealthBarsOnTop(enable); }
    void setDrawLights(bool enable) { m_mapView->setDrawLights(enable); }
    void setDrawManaBar(bool enable) { m_mapView->setDrawManaBar(enable); }
    void setDrawExperienceBars(bool enable) { m_mapView->setDrawExperienceBars(enable); }
    void setDrawPlayerBars(bool enable) { m_mapView->setDrawPlayerBars(enable); }
    void setAnimated(bool enable) { m_mapView->setAnimated(enable); }
    void setKeepAspectRatio(bool enable);
    void setMinimumAmbientLight(float intensity) { m_mapView->setMinimumAmbientLight(intensity); }
    void setLimitVisibleRange(bool limitVisibleRange) { m_limitVisibleRange = limitVisibleRange; updateVisibleDimension(); }
    void setFloorFading(int value) { m_mapView->setFloorFading(value); }
    void setCrosshair(const std::string& type) { m_mapView->setCrosshair(type); }
    bool isMultifloor() { return m_mapView->isMultifloor(); }
    bool isDrawingTexts() { return m_mapView->isDrawingTexts(); }
    bool isDrawingNames() { return m_mapView->isDrawingNames(); }
    bool isDrawingHealthBars() { return m_mapView->isDrawingHealthBars(); }
    bool isDrawingHealthBarsOnTop() { return m_mapView->isDrawingHealthBarsOnTop(); }
    bool isDrawingLights() { return m_mapView->isDrawingLights(); }
    bool isDrawingManaBar() { return m_mapView->isDrawingManaBar(); }
    bool isAnimating() { return m_mapView->isAnimating(); }
    bool isKeepAspectRatioEnabled() { return m_keepAspectRatio; }
    bool isLimitVisibleRangeEnabled() { return m_limitVisibleRange; }

    Size getVisibleDimension() { return m_mapView->getVisibleDimension(); }
    CreaturePtr getFollowingCreature() { return m_mapView->getFollowingCreature(); }
    Otc::DrawFlags getDrawFlags() { return m_mapView->getDrawFlags(); }
    Position getCameraPosition() { return m_mapView->getCameraPosition(); }
    Position getPosition(const Point& mousePos);
    Point getPositionOffset(const Point& mousePos);
    TilePtr getTile(const Point& mousePos);
    int getMaxZoomIn() { return m_maxZoomIn; }
    int getMaxZoomOut() { return m_maxZoomOut; }
    int getZoom() { return m_zoom; }
    float getMinimumAmbientLight() { return m_mapView->getMinimumAmbientLight(); }

    void setShader(const std::string& shader)
    {
        m_shader = shader;
    }
    std::string getShader()
    {
        return m_shader;
    }

protected:
    virtual void onStyleApply(const std::string& styleName, const OTMLNodePtr& styleNode);
    virtual void onGeometryChange(const Rect& oldRect, const Rect& newRect);

private:
    void updateVisibleDimension();
    void updateMapSize();

    int m_zoom;
    MapViewPtr m_mapView;
    Rect m_mapRect;
    Point m_mousePosition;
    float m_aspectRatio;
    bool m_keepAspectRatio;
    bool m_limitVisibleRange;
    int m_maxZoomIn;
    int m_maxZoomOut;
    std::string m_shader;
};

#endif
