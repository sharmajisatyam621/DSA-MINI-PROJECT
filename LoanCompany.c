#include <stdio.h>
#include <math.h>

typedef struct {
    char name[50];
    double monthlyIncome;
    double currentDebt; 
    int creditScore;    
} Applicant;

typedef struct {
    double principal;     
    double annualRate;    
    int tenureMonths;     
} LoanRequest;

double calculateEMI(double principal, double annualRate, int months);
int checkEligibility(Applicant user, double estimatedEMI);
void displayLoanSummary(double principal, int tenureMonths, double emi);
void generateRepaymentSchedule(double principal, double monthlyRate, int months, double emi);

int main() {
    Applicant user;
    LoanRequest loan;
    
    printf("=== LOAN PROCESSING SYSTEM ===\n");
    printf("--- Applicant Details ---\n");
    printf("Enter Name: ");
    scanf("%s", user.name); 
    printf("Enter Monthly Income: ");
    scanf("%lf", &user.monthlyIncome);
    printf("Enter Current Monthly Debt/EMIs: ");
    scanf("%lf", &user.currentDebt);
    printf("Enter Credit Score (300-900): ");
    scanf("%d", &user.creditScore);

    printf("\n--- Loan Request Details ---\n");
    printf("Enter Loan Amount (Principal): ");
    scanf("%lf", &loan.principal);
    printf("Enter Annual Interest Rate (%%): ");
    scanf("%lf", &loan.annualRate);
    printf("Enter Tenure (Months): ");
    scanf("%d", &loan.tenureMonths);

    double emi = calculateEMI(loan.principal, loan.annualRate, loan.tenureMonths);

    if (checkEligibility(user, emi)) {
        printf("\n[STATUS] Congratulations %s, your loan is APPROVED.\n", user.name);
        
        displayLoanSummary(loan.principal, loan.tenureMonths, emi);
        
        char choice;
        printf("\nWould you like to see the month-by-month repayment schedule? (y/n): ");
        scanf(" %c", &choice);
        
        if(choice == 'y' || choice == 'Y') {
            double monthlyRate = loan.annualRate / 12.0 / 100.0;
            generateRepaymentSchedule(loan.principal, monthlyRate, loan.tenureMonths, emi);
        }
    } else {
        printf("\n[STATUS] Loan REJECTED.\n");
        printf("Reason: High Debt-to-Income ratio or low Credit Score.\n");
    }

    return 0;
}


double calculateEMI(double principal, double annualRate, int months) {
    double monthlyRate = annualRate / 12.0 / 100.0;
    double growth = pow(1 + monthlyRate, months);
    return (principal * monthlyRate * growth) / (growth - 1);
}

int checkEligibility(Applicant user, double estimatedEMI) {
    if (user.creditScore < 650) return 0;

    double totalObligation = user.currentDebt + estimatedEMI;
    double maxAllowedDebt = user.monthlyIncome * 0.50;

    if (totalObligation > maxAllowedDebt) return 0;

    return 1;
}

void displayLoanSummary(double principal, int tenureMonths, double emi) {
    double totalAmountPayable = emi * tenureMonths;
    double totalInterest = totalAmountPayable - principal;
    
    printf("\n--- FINANCIAL SUMMARY ---\n");
    printf("Loan Amount:         $%.2f\n", principal);
    printf("Monthly EMI:         $%.2f\n", emi);
    printf("Total Repayment:     $%.2f\n", totalAmountPayable);
    printf("-----------------------------\n");
    printf("TOTAL INTEREST COST: $%.2f\n", totalInterest);
    printf("-----------------------------\n");
}

void generateRepaymentSchedule(double principal, double monthlyRate, int months, double emi) {
    double balance = principal;
    double totalInterestPaid = 0;

    printf("\n%-8s %-12s %-12s %-12s %-12s\n", "Month", "EMI", "Interest", "Principal", "Balance");
    printf("------------------------------------------------------------------\n");

    for (int i = 1; i <= months; i++) {
        double interestPart = balance * monthlyRate;
        double principalPart = emi - interestPart;
        
        balance = balance - principalPart;
        if (balance < 0) balance = 0;

        printf("%-8d %-12.2f %-12.2f %-12.2f %-12.2f\n", 
               i, emi, interestPart, principalPart, balance);
    }
}
