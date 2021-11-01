#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QPair>
#include <QDebug>
#include "application.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	application = Application::getInstance();
	setupMainMenu();
	bindInputs();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::setupMainMenu()
{
	QMenu* fileMenu = menuBar()->addMenu("File");
	QAction* saveAction = new QAction("Save");
	QAction* loadAction = new QAction("Load");
	fileMenu->addAction(saveAction);
	fileMenu->addAction(loadAction);

	connect(saveAction, &QAction::triggered, this, &MainWindow::saveAction);
	connect(saveAction, &QAction::triggered, this, &MainWindow::loadAction);
}

void MainWindow::saveAction()
{

}

void MainWindow::loadAction()
{

}

void MainWindow::bindInputs()
{
	connect(ui->AddPushButton, &QPushButton::clicked, this, &MainWindow::AddButtonPressed);
}

void MainWindow::AddButtonPressed()
{
	QPair<QString, QString> pairToAdd;
	int repetitions = ui->RepetitionsSpinBox->value();
	pairToAdd.first = ui->WordLineEdit->text();
	pairToAdd.second = ui->EquvivalentLineEdit->text();
	application->addWord({pairToAdd, repetitions});
	addPairToTable({pairToAdd, repetitions});
	ui->WordLineEdit->clear();
	ui->EquvivalentLineEdit->clear();
}

void MainWindow::addPairToTable(WordStructure wordpair)
{
		ui->tableWidget->insertRow(ui->tableWidget->rowCount());
		ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(wordpair.words.first));
		ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(wordpair.words.second));
		ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(QString::number(wordpair.repetitions)));
}

