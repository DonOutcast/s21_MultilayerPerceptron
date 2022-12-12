#include "render_scene.h"

#include <iostream>

RenderScene::RenderScene(QWidget* parent)
    : QWidget(parent),
      m_image_(QSize(400, 400), QImage::Format_RGB16),
      m_drag_(false) {
  clearImage();
}

auto RenderScene::mousePressEvent(QMouseEvent* event) -> void {
  if (event->button() == Qt::LeftButton) {
    m_lastPoint_ = event->pos();
    m_drag_ = true;
  } else {
    clearImage();
  }
}

auto RenderScene::mouseMoveEvent(QMouseEvent* event) -> void {
  if ((event->buttons() & Qt::LeftButton) && m_drag_) {
    lineTo(event->pos());
  }
}

auto RenderScene::mouseReleaseEvent(QMouseEvent* event) -> void {
  if (event->button() == Qt::LeftButton && m_drag_) {
    lineTo(event->pos());
    m_drag_ = false;
  }
   m_mainWindow_->Predict();
}

auto RenderScene::paintEvent(QPaintEvent* event) -> void {
  QPainter painter(this);
  QRect rect(event->rect());
  painter.drawImage(rect, m_image_, rect);
}

auto RenderScene::lineTo(const QPoint& newPoint) -> void {
  QPainter painter(&m_image_);
  painter.setPen(
      QPen(Qt::black, lineWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
  painter.setRenderHint(QPainter::SmoothPixmapTransform);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.drawLine(m_lastPoint_, newPoint);

  int rad = (lineWidth / 2) + 2;
  update(QRect(m_lastPoint_, newPoint)
             .normalized()
             .adjusted(-rad, -rad, +rad, +rad));
  m_lastPoint_ = newPoint;
}

auto RenderScene::clearImage() -> void {
  m_image_.fill(qRgb(0xFF, 0xFF, 0xFF));
  update();
}

auto RenderScene::VectorFromImage() -> const std::vector<double>& {
  if (!m_pixelVector_.empty()) {
    m_pixelVector_.clear();
  }
  m_resized_image_ = m_image_.scaled(pixelSize, pixelSize);
  for (int i = 0; i < pixelSize; ++i) {
    for (int j = 0; j < pixelSize; ++j) {
      m_pixelVector_.emplace_back(
          static_cast<double>(m_resized_image_.pixelColor(i, j).blackF()));
    }
  }
  return m_pixelVector_;
}

auto RenderScene::GetImage() const -> const QImage& { return m_image_; }

auto RenderScene::SetImage(const QString& filePath) -> void {
  clearImage();
  m_image_.load(filePath);
  update();
}

auto RenderScene::IsClear() const -> bool {
  for (int i = 0; i < m_image_.width(); ++i) {
    for (int j = 0; j < m_image_.height(); ++j) {
      if (m_image_.pixelColor(i, j).blackF() != 0.f) {
        return false;
      }
    }
  }
  return true;
}

auto RenderScene::SetMainWindow(s21_view* window) -> void {
  m_mainWindow_ = window;
}

