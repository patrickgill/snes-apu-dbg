#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include <QMainWindow>
#include <qlayout.h>
#include <qtimer.h>

#include "SnesApu.h"

#include "RamViewer.h"
#include "VoiceViewer.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(SnesApu *apu, QWidget *parent = nullptr);
    ~MainWindow();

    void Update(Snapshot snapshot);

private slots:
    void on_fileOpenSpcFile_triggered(bool checked = false);

    void on_resetButton_clicked();
    void on_stopButton_clicked();

private:
    Ui::MainWindow *ui;

    SnesApu *apu;

    RamViewer *ramViewer;
    VoiceViewer **voiceViewers;
};

#endif
