#pragma once

#define DEFINE_QML_PROPERTY(type, name)                                                  \
public:                                                                                  \
    Q_PROPERTY(type name READ get##name WRITE set##name NOTIFY sig##name##Changed)       \
    type get##name() {                                                                   \
        return m##name;                                                                  \
    };                                                                                   \
    void set##name(type value) {                                                         \
        m##name = value;                                                                 \
        emit sig##name##Changed();                                                       \
    };                                                                                   \
private:                                                                                 \
    type m##name;                                                                        \
Q_SIGNALS:                                                                               \
    void sig##name##Changed();
