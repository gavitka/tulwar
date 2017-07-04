#include "settingswindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QGroupBox>
#include <QListView>
#include <QListWidget>
#include <QLabel>
#include <QGridLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QStackedWidget>


SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint)
{
    buttonDialog = new ButtonDialog(this);

    TouchPage *touchPage =  new TouchPage(this);
    ListPage *listPage =  new ListPage(this);

    QTabWidget *tabs = new QTabWidget(this);
    tabs->addTab(listPage, "List");
    tabs->addTab(touchPage, "Settings");
    connect(listPage->addButton, SIGNAL(released()), buttonDialog, SLOT(exec()));
    connect(listPage->editButton, SIGNAL(released()), buttonDialog, SLOT(exec()));

    QPushButton *okButton = new QPushButton("Ok", this);
    connect(okButton, SIGNAL(released()), this, SLOT(accept()));

    QPushButton *cancelButton = new QPushButton("Cancel", this);
    connect(cancelButton, SIGNAL(released()), this, SLOT(reject()));

    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    hBoxLayout->addStretch(1);
    hBoxLayout->addWidget(okButton);
    hBoxLayout->addWidget(cancelButton);

    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(tabs);
    vBoxLayout->addLayout(hBoxLayout);

    setLayout(vBoxLayout);

    setMinimumSize(500, 500);
}


TouchPage::TouchPage(QWidget *parent) :
    QWidget(parent)
{
    QGroupBox *groupBox = new QGroupBox(tr("Palm Rejection"));

    QRadioButton *radio1 = new QRadioButton(tr("Reject anywhere to the right of pen position (right handed)"));
    QRadioButton *radio2 = new QRadioButton(tr("Reject anywhere to the left of pen position (left handed)"));
    QRadioButton *radio3 = new QRadioButton(tr("Reject everywhere, except the Tulwar"));
    QRadioButton *radio4 = new QRadioButton(tr("Reject anywhere"));
    QRadioButton *radio5 = new QRadioButton(tr("Do not reject"));

    radio5->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(radio4);
    vbox->addWidget(radio5);

    groupBox->setLayout(vbox);

    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(groupBox);
    vBoxLayout->addStretch(1);

    setLayout(vBoxLayout);
}

ListPage::ListPage(QWidget *parent) :
    QWidget(parent)
{
    QLabel *label3 = new QLabel("Created Toolbars", this);
    QComboBox *comboBox = new QComboBox(this);
    comboBox->addItem("Ssibal");
    comboBox->addItem("Ssibal");
    comboBox->addItem("Ssibal");
    comboBox->addItem("Ssibal");
    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    QPushButton *addToolbarButton = new QPushButton("Add",this);
    QPushButton *deleteToolbarButton = new QPushButton("Delete",this);

    QHBoxLayout *hBoxLayout3 = new QHBoxLayout();
    hBoxLayout3->addWidget(label3);
    hBoxLayout3->addWidget(comboBox);
    hBoxLayout3->addWidget(addToolbarButton);
    hBoxLayout3->addWidget(deleteToolbarButton);

    QPushButton *removeButton = new QPushButton("Remove Button", this);
    addButton = new QPushButton("Add Button", this);
    editButton = new QPushButton("Edit Button", this);
    QPushButton *delButton = new QPushButton("Delete Button", this);

    QHBoxLayout *hBoxLayout1 = new QHBoxLayout();
    hBoxLayout1->addWidget(removeButton);
    hBoxLayout1->addStretch(1);

    QHBoxLayout *hBoxLayout2 = new QHBoxLayout();
    hBoxLayout2->addWidget(addButton);
    hBoxLayout2->addWidget(editButton);
    hBoxLayout2->addWidget(delButton);
    hBoxLayout2->addStretch(1);

    QLabel *label1 = new QLabel("Panel buttons", this);
    QListWidget *listWidget1 = new QListWidget(this);
    new QListWidgetItem("Panel 1",listWidget1);
    new QListWidgetItem("Panel 2",listWidget1);
    new QListWidgetItem("Panel 3",listWidget1);
    new QListWidgetItem("Panel 4",listWidget1);

    QLabel *label2 = new QLabel("Created buttons", this);
    QListWidget *listWidget2 = new QListWidget(this);
    new QListWidgetItem("Panel 1",listWidget2);
    new QListWidgetItem("Panel 2",listWidget2);
    new QListWidgetItem("Panel 3",listWidget2);
    new QListWidgetItem("Panel 4",listWidget2);

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addLayout(hBoxLayout3,0,0,1,2);

    gridLayout->addWidget(label1,1,0);
    gridLayout->addWidget(listWidget1,2,0);
    gridLayout->addLayout(hBoxLayout1,3,0);

    gridLayout->addWidget(label2,1,1);
    gridLayout->addWidget(listWidget2,2,1);
    gridLayout->addLayout(hBoxLayout2,3,1);

    setLayout(gridLayout);
}

ButtonDialog::ButtonDialog(QWidget *parent) :
    QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint)
{
    QGroupBox *groupBox3 = new QGroupBox("Button name");
    QVBoxLayout *vBoxLayout2 = new QVBoxLayout();
    QLineEdit *nameLine = new QLineEdit(this);
    vBoxLayout2->addWidget(nameLine);
    groupBox3->setLayout(vBoxLayout2);

    QGroupBox *groupBox1 = new QGroupBox("Button type");
    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    QRadioButton *radio1 = new QRadioButton("Hotkey (press and release key combination)");
    QRadioButton *radio2 = new QRadioButton("Modifier (press and hold modifier until toolbar button is released)");
    QRadioButton *radio3 = new QRadioButton("Modifier + pen tap (press and hold modifier until pen tapped and released)");

    vBoxLayout->addWidget(radio1);
    vBoxLayout->addWidget(radio2);
    vBoxLayout->addWidget(radio3);
    radio1->setChecked(true);
    groupBox1->setLayout(vBoxLayout);

    stackedWidget = new QStackedWidget(this);

    QGroupBox *groupBox2 = new QGroupBox("Modifier",this);
    QVBoxLayout *vBoxLayout1 = new QVBoxLayout();
    QCheckBox *check1 = new QCheckBox("Ctrl",this);
    QCheckBox *check2 = new QCheckBox("Alt",this);
    QCheckBox *check3 = new QCheckBox("Shift",this);
    QCheckBox *check4 = new QCheckBox("Space",this);
    vBoxLayout1->addWidget(check1);
    vBoxLayout1->addWidget(check2);
    vBoxLayout1->addWidget(check3);
    vBoxLayout1->addWidget(check4);
    groupBox2->setLayout(vBoxLayout1);

    QGroupBox *groupBox4 = new QGroupBox("Key sequence",this);
    QLineEdit *keySeq = new QLineEdit("Ctrl + Alt + Q",this);
    QVBoxLayout *vBoxLayout3 = new QVBoxLayout();
    vBoxLayout3->addWidget(keySeq);
    vBoxLayout3->addStretch(1);
    groupBox4->setLayout(vBoxLayout3);

    stackedWidget->addWidget(groupBox2);
    stackedWidget->addWidget(groupBox4);

    stackedWidget->setCurrentIndex(0);

    QPushButton *okButton = new QPushButton("Ok", this);
    connect(okButton, SIGNAL(released()), this, SLOT(accept()));
    QPushButton *cancelButton = new QPushButton("Cancel", this);
    connect(cancelButton, SIGNAL(released()), this, SLOT(reject()));

    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    hBoxLayout->addStretch(1);
    hBoxLayout->addWidget(okButton);
    hBoxLayout->addWidget(cancelButton);

    QVBoxLayout *vLayout1 = new QVBoxLayout();
    vLayout1->addWidget(groupBox3);
    vLayout1->addWidget(groupBox1);
    vLayout1->addWidget(stackedWidget);
    vLayout1->addLayout(hBoxLayout);
    vLayout1->addStretch(1);
    setLayout(vLayout1);


    setMinimumSize(200, 200);
    window()->setFixedSize(window()->sizeHint());

    connect(radio1,SIGNAL(toggled(bool)),this,SLOT(setButtonType(bool)));
    connect(radio2,SIGNAL(toggled(bool)),this,SLOT(setButtonType(bool)));
    connect(radio3,SIGNAL(toggled(bool)),this,SLOT(setButtonType(bool)));
}

void ButtonDialog::setButtonType(bool value)
{
    stackedWidget->setCurrentIndex(1);
}
