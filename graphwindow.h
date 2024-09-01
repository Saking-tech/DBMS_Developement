#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H
#include <QDialog>
#include "dataset.h"
#include <QString>
#include <QPushButton>
#include <QFileDialog>
#include <QPainter>
#include <QPixmap>
#include <QImage>



namespace Ui {
class GraphWindow;
}

class GraphWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GraphWindow(DataSet *DataSet,QWidget *parent = nullptr);
    ~GraphWindow();
    void SetGraphSetting(DataSet *DataSet); // Function to control the setting of the curve (dataset represenation in the figure)
    void SetFigureSetting(); // Function to control the setting of the figure itself

private slots:
    void on_comboBox_2_textHighlighted(const QString &arg1);

    void on_comboBox_textHighlighted(const QString &arg1);

    void on_comboBox_3_textHighlighted(const QString &arg1);
    void downloadChartImage(const QString &fileName);



    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    // void on_pushButton_clicked(DataSet *DataSet);

    void on_pushButton_3_clicked();

private:
    Ui::GraphWindow *ui;
    static int FigureCounter; // Number of Figures created in the app ( defined as static because it is shared among all objects of this class)
};

#endif // GRAPHWINDOW_H
