/*
1. Basic Banking Operations
Deposit: Add money to an account.

Withdraw: Remove money from an account with checks for sufficient balance.

Check Balance: Retrieve the current balance in the account.

2. Account Types
Savings Account: Should include functionality for:

Interest Calculation: Add interest to the account balance (e.g., 10% annual interest).

Minimum Balance Enforcement: Ensure the account doesn't go below a certain balance (e.g., $100 for savings).

Current Account: May include:

No Interest: Current accounts typically don't accrue interest.

Lower Minimum Balance Requirements: E.g., $0 or a small balance.

Additional Account Types: You could add Loan Accounts, Business Accounts, etc., for extra complexity.

3. Transaction History
Track Transactions: Keep a log of all transactions (deposits and withdrawals) in a vector or database.

View History: Retrieve the full transaction history for an account.

4. Account Management
Create Account: The ability to create an account by specifying the account type (Savings or Current) and the account holder's name.

Close Account: Functionality to close an account, which could delete or archive the account and transfer the balance to another account or external system.

Transfer Between Accounts: Implement transfers between accounts (same bank or external), including validation of sufficient funds.

5. Security & Validations
Pin/Password Protection (Optional): Each account could have a password or PIN to validate access for transactions.

Overdraft Protection: Ensure the system prevents withdrawal of amounts beyond the available balance, or implement a policy like "overdraft protection" where you allow limited negative balances.

Input Validation: Ensure user inputs are properly validated (e.g., non-negative deposit/withdrawal amounts).

6. Account Balances and Limits
Set and Get Account Limits: Set limits on transactions or account balance (e.g., max withdrawal limits).

Currency Support: (Optional) Add support for different currencies by creating a class for currency and implementing conversion methods.

Account Fees: (Optional) Charge transaction fees for specific operations like withdrawals or transfers.

7. Miscellaneous Features
Interest Accrual: At regular intervals, interest should be added to the savings account. This could be done via a background task or manual execution.

Notifications: Send alerts (e.g., low balance notifications or successful transactions) to users or log them for future reference.

Database Integration: Optionally, you can simulate database storage using std::map or a database connection to persist account information and transactions.

8. Exception Handling
Insufficient Funds: Handle cases where the user tries to withdraw more than the available balance.

Invalid Account Type: Ensure only valid account types (e.g., Savings or Current) can be used.

Invalid Input: Ensure proper validation for deposit, withdrawal amounts, etc.

Non-Functional Requirements to Consider (Optional)
Scalability: Consider how you might handle millions of accounts in a real-world system.

Performance: Optimize for frequent transactions by reducing unnecessary processing.

Concurrency: Consider handling multiple threads or users accessing and modifying the same account data.

How to Implement:
Start with the basic banking operations (Deposit, Withdraw, Balance check).

Add account types (Savings, Current), along with the specific functionalities (interest, minimum balance enforcement).

Handle transactions (log each action and maintain history).

Add validation for edge cases (e.g., invalid withdrawal, insufficient funds).

Test thoroughly with different scenarios (creating accounts, transferring money, withdrawing funds).

Extra Feature Ideas (Optional)
Generate monthly account statements for customers, which include their balance and transaction history.

Account transfers between different account types.

Add a “Loan” feature to model loans, payments, and interest rates.
*/