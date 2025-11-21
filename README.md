📘 README – Loan Processing System (C Project)
📌 Project Title:

Loan Processing Automation System

👨‍💻 Group Members (Group J):

Satyam Sharma – 25/SCA/MCAN/055

Pushpesh Pant – 25/SCA/MCAN/052

Maniya – 25/SCA/MCAN/054

Kashish Kaushik – 25/SCA/MCAN/056

📜 Project Description

This project implements a Loan Processing System in C language that automates key loan-related tasks such as:

Loan Eligibility Checking

EMI Calculation

Total Interest Estimation

Month-by-month Repayment Schedule

It uses structures, functions, and mathematical calculations to simulate a real-world loan approval workflow.

🔧 Technology & Libraries Used

Programming Language: C

Libraries:

<stdio.h> – for input/output

<math.h> – for power function used in EMI calculation

✨ Features
✔ 1. Automated Eligibility Check

The loan is approved only if:

Credit Score ≥ 650

Debt-to-Income Ratio ≤ 50%

Uses a function that compares income, current debt, and EMI.

✔ 2. EMI Calculator

EMI is computed using the standard formula:

𝐸
𝑀
𝐼
=
𝑃
×
𝑅
×
(
1
+
𝑅
)
𝑁
(
1
+
𝑅
)
𝑁
−
1
EMI=
(1+R)
N
−1
P×R×(1+R)
N
	​


Where:

P = Principal

R = Monthly Interest Rate

N = Tenure (Months)

✔ 3. Financial Summary

Before showing detailed logs, the system displays:

Loan Amount

Monthly EMI

Total Repayment

Total Interest Cost

(Shown on page 5 in your PDF) 

DSA Mini Project

✔ 4. Amortization Schedule

Month-by-month breakdown

EMI, Interest, Principal, Remaining Balance

Ensures last balance is adjusted correctly to zero
(Example visible in the screenshot on page 5.) 

DSA Mini Project

✔ 5. Clean Input & Output

User-friendly prompts and formatted tables for professional presentation.

📁 Project File Structure
LoanProject/
│
├── loan_processing.c
├── README.md
└── (optional) output_screenshot.png

🧠 How It Works (Explanation)

(As described on page 4 in your PDF) 

DSA Mini Project

The program uses two structures:

Applicant (Income, Debt, Credit Score)

LoanRequest (Principal, Rate, Tenure)

EMI is calculated using pow() function.

The checkEligibility() function:

Returns 1 (Approved) if credit score ≥650 and obligations <50% income.

Else returns 0 (Rejected).

If approved:

Summary is printed

User can choose to print full repayment schedule

A loop calculates for each month:

Interest = RemainingBalance × MonthlyRate

Principal = EMI – Interest

New Balance = OldBalance – Principal

🖥 Example Output

The PDF's output section shows a sample run (page 5):
User inputs details → Loan is approved → EMI and schedule shown. 

DSA Mini Project

📚 How to Run
On Windows (using GCC / CodeBlocks):
gcc loan_processing.c -o loan
./loan

On Linux:
gcc loan_processing.c -lm -o loan
./loan

📢 Conclusion

This project successfully models a real-life loan approval system by combining data structures, mathematical logic, and systematic financial calculations. It provides a structured workflow commonly used in financial software applications.
