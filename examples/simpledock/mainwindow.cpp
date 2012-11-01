/****************************************************************************
**
** QtDockTile - crossplatform for the work this docks 
**
** Copyright © 1301 USA
** Copyright © 2012 Sidorov Aleksey <gorthauer87@ya.ru>
**
*****************************************************************************
**
** $QTDOCKTILE_BEGIN_LICENSE$
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU Lesser General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU Lesser General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see http://www.gnu.org/licenses/.
** $QTDOCKTILE_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qtdocktile.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_tile(new QtDockTile(this))
{
    ui->setupUi(this);
	ui->menubar->setNativeMenuBar(false);

    ui->actionElementWithIcon->setIcon(QIcon::fromTheme("applications-internet"));
	m_tile->setMenu(ui->menu);

    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(onBadgeChanged(QString)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(onProgressChanged(int)));
    connect(ui->alertButton, SIGNAL(clicked()), m_tile, SLOT(alert()));

	connect(ui->element, SIGNAL(triggered()), SLOT(actionTriggered()));
	connect(ui->element1, SIGNAL(triggered()), SLOT(actionTriggered()));
	connect(ui->element2, SIGNAL(triggered()), SLOT(actionTriggered()));
	connect(ui->actionElementWithIcon, SIGNAL(triggered()), SLOT(actionTriggered()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::actionTriggered() const
{
	QAction *action = static_cast<QAction*>(sender());
    statusBar()->showMessage(tr("Action %1 triggered").arg(action->text()), 2000);
}

void MainWindow::onProgressChanged(int percent)
{
    m_tile->setProgress(percent);
}

void MainWindow::onBadgeChanged(const QString &text)
{
    m_tile->setBadge(text);
}

