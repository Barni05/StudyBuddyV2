#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPair>
#include "application.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Application;
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void setupMainMenu();

	void saveAction();
	void loadAction();
	void bindInputs();

	void AddButtonPressed();
	void addPairToTable(WordStructure wordpair);
private:
	Ui::MainWindow *ui;
	Application* application;
};
#endif // MAINWINDOW_H
