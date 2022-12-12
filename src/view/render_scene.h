#ifndef RENDERSCENE_H
#define RENDERSCENE_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QColor>
#include <QImage>
#include <vector>
#include "s21_view.h"

class RenderScene: public QWidget {
  Q_OBJECT

public:
//    RenderScene() = default;
    explicit RenderScene(QWidget* parent = nullptr);
//    RenderScene(QWidget* parent = nullptr);
    ~RenderScene() override = default;
public:
    auto VectorFromImage() -> const std::vector<double>&;
    auto GetImage() const -> const QImage&;
    auto SetImage(const QString& filePath) -> void;
    auto IsClear() const -> bool;
    auto SetMainWindow(s21_view* window) -> void;

protected:
    auto mousePressEvent(QMouseEvent *event) -> void override;
    auto mouseMoveEvent(QMouseEvent *event) -> void override;
    auto mouseReleaseEvent(QMouseEvent* event) -> void override;
    auto paintEvent(QPaintEvent* event) -> void override;

private:
    QPoint m_lastPoint_                {};
    QImage m_image_                    {};
    QImage m_resized_image_            {};
    bool   m_drag_                    {};
    std::vector<double> m_pixelVector_ {};
    s21_view*          m_mainWindow_ {};

    static constexpr double lineWidth = 40;
    static constexpr int    pixelSize = 28;

    auto clearImage() -> void;
    auto lineTo(const QPoint& newPoint) -> void;

};



#endif // RENDERSCENE_H
