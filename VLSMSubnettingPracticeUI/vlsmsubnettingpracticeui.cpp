#include "vlsmsubnettingpracticeui.h"
#include "ui_vlsmsubnettingpracticeui.h"

VLSMSubnettingPracticeUI::VLSMSubnettingPracticeUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VLSMSubnettingPracticeUI), tableOutput(NULL)
{
    //Initialize UI
    ui->setupUi(this);

    setWindowFlags( (windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowMaximizeButtonHint);
    tableOutput = ui->tableWidget;
    tableOutput->setColumnCount(5);
    headers<<"Network Address"<<"First Usable Address"<<"Last Usable Address" << "Broadcast Address" << "Subnet Mask";
    tableOutput->setHorizontalHeaderLabels(headers);
    tableOutput->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (int c = 0; c < tableOutput->horizontalHeader()->count(); ++c)
    {
        tableOutput->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);
    }
    addressSpace = new IPAddress();
    instance = new SubnetService();
}

VLSMSubnettingPracticeUI::~VLSMSubnettingPracticeUI()
{
    delete instance;
    delete addressSpace;
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

void VLSMSubnettingPracticeUI::on_btnGenerate_clicked()
{
    int count = 0;
    unsigned long int maxAddressSpace, spaceToSubnet;
    int maxSubnetGenerated;
    QString output;

    if (classType == 'A') {
        addressSpace->setAddress(10, 0, 0, 0);
        maxAddressSpace = MAX_CLASS_A_ADDRESS;
        spaceToSubnet = MAX_CLASS_A_ADDRESS;
        maxSubnetGenerated = CLASS_A_LIMIT;
        output = "Given an IP Address 10.0.0.0 with subnet mask 255.0.0.0 and the following subnet requirements:\n\n";
    }
    else if (classType == 'B') {
        addressSpace->setAddress(172,16,0,0);
        maxAddressSpace = MAX_CLASS_B_ADDRESS;
        spaceToSubnet = MAX_CLASS_B_ADDRESS;
        maxSubnetGenerated = CLASS_B_LIMIT;
        output = "Given an IP Address 172.16.0.0 with subnet mask 255.255.0.0 and the following subnet requirements:\n\n";
    }
    else if (classType == 'C') {
        addressSpace ->setAddress(192,168,1,0);
        maxAddressSpace = MAX_CLASS_C_ADDRESS;
        spaceToSubnet = MAX_CLASS_C_ADDRESS;
        maxSubnetGenerated = CLASS_C_LIMIT;
        output = "Given an IP Address 192.168.1.0 with subnet mask 255.255.255.0 and the following subnet requirements:\n\n";
    }

    srand(time(NULL));

    while (spaceToSubnet > 2) {
        unsigned long int value = rand() % (spaceToSubnet/2) + 2;
        requirements.push_back(value);

        output += QString::number(value) + "\n";

        bool stop = false;
        int startExp = 1;
        int subnetSpace = 0;

        while(!stop) {
            subnetSpace = (int)(pow(2.0, (double)(startExp)));

            if (subnetSpace - 2 >= value) {
                stop = true;
            }
            else {
                startExp++;
            }
        }

        spaceToSubnet -= subnetSpace;
        if (count == maxSubnetGenerated) {
            break;
        }
        else {
            count++;
        }
    }


    std::sort(requirements.begin(), requirements.end());

    output += "\nFind the most optimal addressing scheme for these subnets.";

    ui -> lblQuestion->setText(output);

    ui -> btnSolve->setEnabled(true);
}

void VLSMSubnettingPracticeUI::on_btnSolve_clicked()
{
    list<SubnetInformation*> result = instance->run(*addressSpace, requirements);
    SubnetInformation* data = new SubnetInformation();
    int rowCount = 0;

    tableOutput->setRowCount(result.size());

    while(result.size() > 0) {
        data = result.front();
        result.pop_front();

        IPAddress* subnetData[] = { data->networkAddress, data->firstUsableAddress, data->lastUsableAddress, data->broadcastAddress, data->subnetMask };

        for (int i = 0; i < 5; i++) {
            unsigned int* ipAddress = subnetData[i]->getAddress();
            QString print = "";

            for (int j = 0; j < 4; j++) {
                print += QString::number(ipAddress[j]);

                if (j != 3) {
                    print+= ".";
                }
            }

            tableOutput->setItem(rowCount, i, new QTableWidgetItem(print));
        }

        rowCount++;
    }
}

void VLSMSubnettingPracticeUI::on_rdbClassA_clicked()
{
    classType = 'A';
    ui->btnGenerate->setEnabled(true);
}

void VLSMSubnettingPracticeUI::on_rdbClassB_clicked()
{
    classType = 'B';
    ui->btnGenerate->setEnabled(true);
}

void VLSMSubnettingPracticeUI::on_rdbClassC_clicked()
{
    classType = 'C';
    ui->btnGenerate->setEnabled(true);
}

