#include "vlsmsubnettingpracticeui.h"
#include "ui_vlsmsubnettingpracticeui.h"

VLSMSubnettingPracticeUI::VLSMSubnettingPracticeUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VLSMSubnettingPracticeUI), m_pTableWidget(NULL)
{
    ui->setupUi(this);
    m_pTableWidget = ui->tableWidget;
    m_pTableWidget->setColumnCount(5);
    m_TableHeader<<"Network Address"<<"First Usable Address"<<"Last Usable Address" << "Broadcast Address" << "Subnet Mask";

    m_pTableWidget->setHorizontalHeaderLabels(m_TableHeader);

    m_pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int c = 0; c < m_pTableWidget->horizontalHeader()->count(); ++c)
    {
        m_pTableWidget->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);
    }

    connect(m_pTableWidget, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(cellSelected(int,int)));
}

VLSMSubnettingPracticeUI::~VLSMSubnettingPracticeUI()
{
    delete ui;
}

void VLSMSubnettingPracticeUI::on_btnExit_clicked()
{
    QApplication::quit();
}

void VLSMSubnettingPracticeUI::on_btnAbout_clicked()
{
    QMessageBox::information(this, "About", "VLSM Subnetting Practice\n\nCreated by David Vuong\nhttp://davidvuong.ca\n\nLEGAL INFORMATION\n\nTHE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.");
}

void VLSMSubnettingPracticeUI::cellSelected(int nRow, int nCol){
    QMessageBox::information(this, "TEST", QString::number(nRow) + " " + QString::number(nCol));
}

void VLSMSubnettingPracticeUI::on_btnGenerate_clicked()
{
    ui -> btnSolve->setEnabled(true);
}
