#ifndef VLSMSUBNETTINGPRACTICEUI_H
#define VLSMSUBNETTINGPRACTICEUI_H

#include <QWidget>
#include <QMessageBox>
#include <QTableWidget>
#include <QLabel>
#include <vector>
#include <time.h>
#include <algorithm>
#include "ipaddress.h"
#include "SubnetService.h"

#define MAX_CLASS_A_ADDRESS 16777216
#define MAX_CLASS_B_ADDRESS 65536
#define MAX_CLASS_C_ADDRESS 256
#define CLASS_A_LIMIT 50
#define CLASS_B_LIMIT 15
#define CLASS_C_LIMIT 5

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
    void on_btnGenerate_clicked();
    void on_btnSolve_clicked();
    void on_rdbClassA_clicked();
    void on_rdbClassB_clicked();
    void on_rdbClassC_clicked();

private:
    Ui::VLSMSubnettingPracticeUI *ui;
    QTableWidget* tableOutput;
    QStringList headers;
    IPAddress* addressSpace;
    SubnetService* instance;
    char classType;
    vector <unsigned long int> requirements;
};

#endif // VLSMSUBNETTINGPRACTICEUI_H
