#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void replot();

private slots:
    void on_move_left_clicked();
    void on_move_right_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    std::vector<double> *vx, *vy;
    double minX, maxX, incrX;
};

#endif // WIDGET_H
