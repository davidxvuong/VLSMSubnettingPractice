#ifndef VLSMSUBNETTINGPRACTICEUI_H
#define VLSMSUBNETTINGPRACTICEUI_H

#include <QWidget>
#include <QMessageBox>
#include <QTableWidget>

namespace Ui {
class VLSMSubnettingPracticeUI;
}

class VLSMSubnettingPracticeUI : public QWidget
{
    Q_OBJECT

public:
    explicit VLSMSubnettingPracticeUI(QWidget *parent = 0);
    ~VLSMSubnettingPracticeUI();

private slots:
    void on_btnExit_clicked();
    void on_btnAbout_clicked();
    void cellSelected(int nRow, int nCol);

    void on_btnGenerate_clicked();

private:
    Ui::VLSMSubnettingPracticeUI *ui;
    QTableWidget* m_pTableWidget;
    QStringList m_TableHeader;
};

#endif // VLSMSUBNETTINGPRACTICEUI_H
