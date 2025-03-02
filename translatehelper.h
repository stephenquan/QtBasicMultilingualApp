#ifndef TRANSLATEHELPER_H
#define TRANSLATEHELPER_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTranslator>
#include <QDebug>

class TranslateHelper : public QObject
{
    Q_OBJECT
public:
    QGuiApplication& m_app;
    QQmlApplicationEngine& m_engine;

    TranslateHelper(QGuiApplication& app, QQmlApplicationEngine& engine) :
        m_app(app),
        m_engine(engine)
    {
    }

    Q_INVOKABLE void setLanguage(const QString& name)
    {
        QLocale locale(name);
        QLocale::setDefault(locale);
        QTranslator translator;
        bool ok = translator.load(":/myapp_" + locale.name());
        qDebug() << Q_FUNC_INFO << "translator.load: " << ok;
        m_app.installTranslator(&translator);
        m_engine.retranslate();
    }
};

#endif // TRANSLATEHELPER_H
