/*
 * Papyros Shell - The desktop shell for Papyros following Material Design
 * Copyright (C) 2015 Michael Spencer <sonrisesoftware@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WINDOWDECORATIONS_H
#define WINDOWDECORATIONS_H

#include <QObject>
#include <QWindow>

class WindowDecorations : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor
               NOTIFY backgroundColorChanged)
    Q_PROPERTY(QWindow *window READ window WRITE setWindow NOTIFY windowChanged)

public:
    WindowDecorations(QObject *parent = 0);

    QColor backgroundColor() const { return mColor; }
    QWindow *window() const { return mWindow; }

public slots:
    void setBackgroundColor(QColor color) {
        if (mColor != color) {
            mColor = color;
            emit backgroundColorChanged();
            update();
        }
    }

    void setWindow(QWindow *window) {
        if (mWindow != window) {
            mWindow = window;
            emit windowChanged();
            update();
        }
    }

signals:
    void backgroundColorChanged();
    void windowChanged();

private slots:
    void update();

private:
    QColor mColor;
    QWindow *mWindow;
};

#endif // WINDOWDECORATIONS_H
