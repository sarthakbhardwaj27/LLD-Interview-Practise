#include <iostream>
#include <string>

// Base class for payment processing
class PaymentProcessor
{
public:
    virtual void processPayment(double amount) = 0; // Pure virtual function
};

// Credit card payment processor
class CreditCardPaymentProcessor : public PaymentProcessor
{
public:
    void processPayment(double amount) override
    {
        std::cout << "Processing credit card payment of $" << amount << std::endl;
    }
};

// PayPal payment processor
class PayPalPaymentProcessor : public PaymentProcessor
{
public:
    void processPayment(double amount) override
    {
        std::cout << "Processing PayPal payment of $" << amount << std::endl;
    }
};

void processPayment(PaymentProcessor *processor, double amount)
{
    processor->processPayment(amount);
}

int main()
{
    CreditCardPaymentProcessor creditCardProcessor;
    PayPalPaymentProcessor payPalProcessor;

    processPayment(&creditCardProcessor, 100.00); // Processing credit card payment
    processPayment(&payPalProcessor, 150.00);     // Processing PayPal payment

    return 0;
}
