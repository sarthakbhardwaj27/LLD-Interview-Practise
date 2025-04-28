#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==============================
// Single Responsibility Principle (SRP)
// ==============================

// A class should have only one reason to change. This class is only responsible for 
// sending notifications, not anything else.
class NotificationService {
public:
    void sendNotification(const string& message) {
        cout << "Sending notification: " << message << endl;
    }
};

// ==============================
// Open/Closed Principle (OCP)
// ==============================

// The base class is open for extension (we can add new notification types) but closed 
// for modification (we don't modify existing functionality).
class Notification {
public:
    virtual void send(const string& message) = 0; // abstract send method
    virtual ~Notification() = default;
};

class EmailNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending Email: " << message << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

// ==============================
// Liskov Substitution Principle (LSP)
// ==============================

// A derived class should be able to replace its base class without affecting correctness.
class NotificationManager {
public:
    // This function can accept any Notification type and treat them interchangeably
    void sendNotification(Notification* notification, const string& message) {
        notification->send(message);
    }
};

// ==============================
// Interface Segregation Principle (ISP)
// ==============================

// Clients should not be forced to implement interfaces they do not use.
// Split into separate interfaces for different kinds of notifications.
class EmailSender {
public:
    virtual void sendEmail(const string& message) = 0;
};

class SMSSender {
public:
    virtual void sendSMS(const string& message) = 0;
};

class EmailNotificationV2 : public Notification, public EmailSender {
public:
    void send(const string& message) override {
        sendEmail(message);
    }

    void sendEmail(const string& message) override {
        cout << "Sending Email in new way: " << message << endl;
    }
};

class SMSNotificationV2 : public Notification, public SMSSender {
public:
    void send(const string& message) override {
        sendSMS(message);
    }

    void sendSMS(const string& message) override {
        cout << "Sending SMS in new way: " << message << endl;
    }
};

// ==============================
// Dependency Inversion Principle (DIP)
// ==============================

// High-level modules should not depend on low-level modules. Both should depend on abstractions.
class NotificationServiceV2 {
private:
    Notification* notification;  // Low-level dependency

public:
    // Constructor accepts abstraction (interface), not concrete class
    NotificationServiceV2(Notification* notification) : notification(notification) {}

    void sendNotification(const string& message) {
        notification->send(message); // Delegate to the specific notification type
    }
};

int main() {
    // SRP: Only sending notification here
    NotificationService notificationService;
    notificationService.sendNotification("Welcome to SOLID principles!");

    // OCP & LSP: Extending functionality without modifying base code
    Notification* emailNotification = new EmailNotification();
    Notification* smsNotification = new SMSNotification();

    NotificationManager manager;
    manager.sendNotification(emailNotification, "Hello via Email!");
    manager.sendNotification(smsNotification, "Hello via SMS!");

    // ISP: Using specific interfaces for email and SMS senders
    EmailNotificationV2 emailNotificationV2;
    SMSNotificationV2 smsNotificationV2;

    emailNotificationV2.send("New Email via V2");
    smsNotificationV2.send("New SMS via V2");

    // DIP: High-level module depends on abstraction (Notification interface)
    NotificationServiceV2 notificationServiceV2(emailNotification);
    notificationServiceV2.sendNotification("Test using DIP!");

    // Cleanup
    delete emailNotification;
    delete smsNotification;

    return 0;
}
