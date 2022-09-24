#ifndef SER2_H
#define SER2_H

#include <QMainWindow>
#include <QObject>

class ser2 : public QObject
{
    Q_OBJECT
public:
    explicit ser2(QObject *parent = nullptr);

signals:

};

#endif // SER2_H
