/*
  Copyright (c) 2012 The KoRE Project

  This file is part of KoRE.

  KoRE is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

  KoRE is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with KoRE.  If not, see <http://www.gnu.org/licenses/>.
*/

/************************************************************************/
/* \author Dominik Ospelt                                               */
/************************************************************************/

#ifndef SRC_KOREGUI_RENDERVIEWER_H_
#define SRC_KOREGUI_RENDERVIEWER_H_

#include <QGraphicsView>
#include "KoRE_GUI/NodeItem.h"
#include "KoRE_GUI/BindPathItem.h"
#include "KoRE_GUI/FrameBufferStageItem.h"
#include "KoRE_GUI/ShaderInputItem.h"

namespace koregui {
  class RenderViewer : public QGraphicsView {
      Q_OBJECT

  public:
    RenderViewer(QWidget *parent = 0);
    ~RenderViewer();

    void addSelection(const std::vector<NodeItem*>& nodes);
    void createNode(kore::SceneNode* sourcenode, int x, int y);
    void framebufferMoved(FrameBufferStageItem* bufferstage);


  public slots:
    void zoomIn(void) {scale(1.2,1.2);}
    void zoomOut(void) {scale(1/1.2,1/1.2);}

    /// Create a new Framebuffer Stage.
    void createFBOStage(void);

    /// Create a new Shader Pass
    void createShaderPass(void);

    /// Create an empty Node. It is a child of the root Node.
    void createEmptyNode(void);

    /// Create an empty NodeGroup
    void createEmptyGroup(void);

    void animatePath(void);

  protected:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);

  private:
      void clearScene();
      QGraphicsScene _scene;
      BindPathItem* _currentpath;
      FrameBufferStageItem* _currentframebuffer;
      QPoint _lastpos;
      std::vector<FrameBufferStageItem*> _framebufferStages;
      ShaderInputItem* _bindTarget;
      QTimer _pathanim;
      BindPathItem* _activePath;
  };
}
#endif // SRC_KOREGUI_RENDERVIEWER_H_
