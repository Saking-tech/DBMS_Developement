#include "graphwindow.h"
#include "ui_graphwindow.h"


QString col;
QString wid;
QString sty;
QString comment;

int GraphWindow::FigureCounter=0;
void GraphWindow::downloadChartImage(const QString &fileName)
{
    // Create a pixmap of the size of the customPlot
    QPixmap pixmap(ui->customPlot->size());
    pixmap.fill(Qt::white);  // Fill the pixmap with a white background

    // Create a QCPPainter from the pixmap
    QCPPainter painter(&pixmap);

    // Render the customPlot to the QCPPainter
    ui->customPlot->toPainter(&painter);

    // Finish painting
    painter.end();
    // Convert the pixmap to an image
    QImage image = pixmap.toImage();

    // Save the image to a file
    if (!image.save(fileName)) {
        qDebug() << "Failed to save image";
    } else {
        qDebug() << "Image saved successfully";
    }
}

GraphWindow::GraphWindow(DataSet *DataSet,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphWindow)
{
    ui->setupUi(this);

    // Increment the figure counter:
    FigureCounter++;

    // Create the XY graph (setting te paramters of the dataset graph):
    SetGraphSetting(DataSet);

    // Setting the paramters of the figure:
    SetFigureSetting();

    // Setting the title of the figure
    this->setWindowTitle("Graph "+QString::number(FigureCounter));


}

GraphWindow::~GraphWindow()
{ // Called when the window of the figure is closed
    delete ui;
}

void GraphWindow::SetGraphSetting(DataSet *DataSet)
{ // Sets up the curve and plots it

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->addData(DataSet);
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue,3));
    // ui->customPlot->graph(0)->setPen(QPen(ui->customPlot->graph(0)->pen().color(), 5));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::QCPGraph::lsLine);
    ui->customPlot->graph(0)->setName(DataSet->getName());
    ui->customPlot->graph(0)->rescaleAxes();
    // Add text comment

}

void GraphWindow::SetFigureSetting()
{ // Sets up the properties of the figure (that contains the curve)

    ui->customPlot->legend->setVisible(true);
    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis2->setTickLabels(false);
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}
void GraphWindow::on_lineEdit_textChanged(const QString &arg1)
{
    comment = arg1;
}



void GraphWindow::on_comboBox_2_textHighlighted(const QString &arg1)
{
    col = arg1;
    if (col == "Blue")
    {
        ui->customPlot->graph(0)->setPen(QPen(QColor(31, 119, 180))); // Blue
    }
    else if (col == "Orange")
    {
        ui->customPlot->graph(0)->setPen(QPen(QColor(255, 127, 14))); // Orange
    }
    else if (col == "Green")
    {
        ui->customPlot->graph(0)->setPen(QPen(QColor(44, 160, 44))); // Green
    }
    else if (col == "Red")
    {
        ui->customPlot->graph(0)->setPen(QPen(QColor(214, 39, 40))); // Red
    }
    else if (col == "Purple")
    {
        ui->customPlot->graph(0)->setPen(QPen(QColor(148, 103, 189))); // Purple
    }
    else if (col == "Brown")
    {
        ui->customPlot->graph(0)->setPen(QPen(QColor(140, 86, 75))); // Brown
    }
    else if (col == "Pink")
    {
        ui->customPlot->graph(0)->setPen(QPen(QColor(227, 119, 194))); // Pink
    }
    else if (col == "Gray")
    {
        ui->customPlot->graph(0)->setPen(QPen(QColor(127, 127, 127))); // Gray
    }
    else if (col == "Olive")
    {
        ui->customPlot->graph(0)->setPen(QPen(QColor(188, 189, 34))); // Olive
    }
    else if (col == "Cyan")
    {
        ui->customPlot->graph(0)->setPen(QPen(QColor(23, 190, 207))); // Cyan
    }
    else if (col == "Black")
    {
        ui->customPlot->graph(0)->setPen(QPen(QColor(0,0,0))); // Dark Blue
    }
    else if (col == "Light Orange")
    {
        ui->customPlot->graph(0)->setPen(QPen(QColor(255, 187, 120))); // Light Orange
    }
}


void GraphWindow::on_comboBox_textHighlighted(const QString &arg1)
{
    wid = arg1;
    if (wid == "Thin"){
        ui->customPlot->graph(0)->setPen(QPen(ui->customPlot->graph(0)->pen().color(), 1));
    }
    else if (wid == "Bold+Thin"){
        ui->customPlot->graph(0)->setPen(QPen(ui->customPlot->graph(0)->pen().color(), 2));
    }
    else if (wid == "Regular"){
        ui->customPlot->graph(0)->setPen(QPen(ui->customPlot->graph(0)->pen().color(), 3));
    }
    else if (wid == "Bold"){
        ui->customPlot->graph(0)->setPen(QPen(ui->customPlot->graph(0)->pen().color(), 3.5));
    }
    else if (wid == "Thick"){
        ui->customPlot->graph(0)->setPen(QPen(ui->customPlot->graph(0)->pen().color(), 5));
    }
    else if (wid == "Bold+Thick"){
        ui->customPlot->graph(0)->setPen(QPen(ui->customPlot->graph(0)->pen().color(), 7));
    }


}


void GraphWindow::on_comboBox_3_textHighlighted(const QString &arg1)
{
    sty = arg1;
    if (sty == "None"){
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::QCPGraph::lsNone);
    }
    else if (sty == "Line"){
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::QCPGraph::lsLine);
    }
    else if (sty == "StepLeft"){
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::QCPGraph::lsStepLeft);
    }
    else if (sty == "StepRight"){
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::QCPGraph::lsStepRight);
    }
    else if (sty == "Impulse"){
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::QCPGraph::lsImpulse);
    }
}






void GraphWindow::on_pushButton_2_clicked()
{
    QCPItemText *textItem = new QCPItemText(ui->customPlot);
    textItem->setText("Comment: "+comment);
    textItem->position->setCoords(0.5, 0.95);
    textItem->setFont(QFont("Courier New", 10));
}


// void GraphWindow::on_pushButton_clicked(DataSet *DataSet)
// {
//     ui->customPlot->addGraph();
//     ui->customPlot->graph(1)->addData(DataSet);
//     ui->customPlot->graph(1)->setPen(QPen(Qt::red));

// }





void GraphWindow::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Chart Image", "", "Images (*.png)");
    if (!fileName.isEmpty()) {
        downloadChartImage(fileName);
    }
}


