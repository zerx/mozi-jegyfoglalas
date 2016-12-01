TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Admin.cpp \
    Customer.cpp \
    DateTime.cpp \
    ErrorEntry.cpp \
    ErrorLog.cpp \
    Guest.cpp \
    MovieTicketBookingSystem.cpp \
    Payment.cpp \
    Reservation.cpp \
	Room.cpp \
    Screening.cpp \
    StaffMember.cpp \
    User.cpp \
    EmailAddress.cpp \
    Address.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Address.h \
    Admin.h \
    Customer.h \
    DateTime.h \
    EmailAddress.h \
    ErrorEntry.h \
    ErrorLog.h \
    Guest.h \
    MovieTicketBookingSystem.h \
    Payment.h \
    Reservation.h \
    Room.h \
    Screening.h \
    StaffMember.h \
    User.h \
    currenttime.h

